#include <Wire.h>
#include <IBusBM.h>
#include <TinyGPSPlus.h>
#include <ESP32Servo.h>
#include <MPU6050.h>

IBusBM ibus;
TinyGPSPlus gps;
MPU6050 mpu;

HardwareSerial GPSserial(2);

/* ---------------- PIN CONFIG ---------------- */

#define IBUS_PIN 6

#define SERVO1_PIN 1
#define SERVO2_PIN 2
#define SERVO3_PIN 42
#define SERVO4_PIN 41

#define ESC1_PIN 35
#define ESC2_PIN 0
#define ESC3_PIN 45
#define ESC4_PIN 48

#define BUZZER_PIN 39

#define SDA_PIN 12
#define SCL_PIN 11

#define GPS_RX 44
#define GPS_TX 43

/* ---------------- OBJECTS ---------------- */

Servo esc1, esc2, esc3, esc4;
Servo servo1, servo2, servo3, servo4;

/* ---------------- VARIABLES ---------------- */

float lat_prev = 0;
float lon_prev = 0;
unsigned long time_prev = 0;

float speed_mps = 0;

float home_lat = 0;
float home_lon = 0;

bool home_set = false;
bool RTH = false;

unsigned long ch10_timer = 0;
bool ch10_started = false;

int servo3_target = 90;
int servo4_target = 90;

int servo3_current = 90;
int servo4_current = 90;

unsigned long servo_timer = 0;

/* ---------------- HAVERSINE FUNCTION ---------------- */

float haversine(float lat1, float lon1, float lat2, float lon2)
{
  float R = 6371000;

  float dLat = radians(lat2 - lat1);
  float dLon = radians(lon2 - lon1);

  lat1 = radians(lat1);
  lat2 = radians(lat2);

  float a =
    sin(dLat / 2) * sin(dLat / 2) +
    cos(lat1) * cos(lat2) *
    sin(dLon / 2) * sin(dLon / 2);

  float c = 2 * atan2(sqrt(a), sqrt(1 - a));

  return R * c;
}

/* ---------------- SETUP ---------------- */

void setup()
{
  Serial.begin(115200);

  Wire.begin(SDA_PIN, SCL_PIN);

  pinMode(BUZZER_PIN, OUTPUT);

  mpu.initialize();

  ibus.begin(Serial1, IBUS_PIN);

  GPSserial.begin(9600, SERIAL_8N1, GPS_RX, GPS_TX);

  esc1.attach(ESC1_PIN, 1000, 2000);
  esc2.attach(ESC2_PIN, 1000, 2000);
  esc3.attach(ESC3_PIN, 1000, 2000);
  esc4.attach(ESC4_PIN, 1000, 2000);

  servo1.attach(SERVO1_PIN);
  servo2.attach(SERVO2_PIN);
  servo3.attach(SERVO3_PIN);
  servo4.attach(SERVO4_PIN);

  servo1.write(0);
  servo2.write(0);

  servo3.write(90);
  servo4.write(90);

  digitalWrite(BUZZER_PIN, HIGH);
}

/* ---------------- LOOP ---------------- */

void loop()
{

/* ---------- iBUS UPDATE ---------- */

  ibus.loop();

  int ch1 = ibus.readChannel(0);
  int ch2 = ibus.readChannel(1);
  int ch3 = ibus.readChannel(2);
  int ch4 = ibus.readChannel(3);
  int ch5 = ibus.readChannel(4);
  int ch6 = ibus.readChannel(5);
  int ch7 = ibus.readChannel(6);
  int ch10 = ibus.readChannel(9);

/* ---------- SERVO1 & SERVO2 MODE ---------- */

  if (ch7 < 1500)
  {
    servo1.write(0);
    servo2.write(0);
  }
  else
  {
    servo1.write(90);
    servo2.write(90);
  }

/* ---------- SERVO3 & SERVO4 KNOB CONTROL ---------- */

  servo3_target = map(ch5, 1000, 2000, 0, 180);
  servo4_target = map(ch6, 1000, 2000, 0, 180);

  if (millis() - servo_timer > 250)
  {
    servo_timer = millis();

    if (servo3_current < servo3_target) servo3_current++;
    if (servo3_current > servo3_target) servo3_current--;

    if (servo4_current < servo4_target) servo4_current++;
    if (servo4_current > servo4_target) servo4_current--;

    servo3.write(servo3_current);
    servo4.write(servo4_current);
  }

/* ---------- GPS UPDATE ---------- */

  while (GPSserial.available())
  {
    gps.encode(GPSserial.read());
  }

  if (gps.location.isUpdated())
  {

    float lat = gps.location.lat();
    float lon = gps.location.lng();

    unsigned long now = millis();

    if (lat_prev != 0)
    {
      float distance = haversine(lat_prev, lon_prev, lat, lon);

      float dt = (now - time_prev) / 1000.0;

      if (dt > 0)
      {
        speed_mps = distance / dt;
      }
    }

    lat_prev = lat;
    lon_prev = lon;
    time_prev = now;

/* ---------- SET HOME ---------- */

    if (!home_set && gps.satellites.value() >= 6)
    {
      home_lat = lat;
      home_lon = lon;

      home_set = true;

      digitalWrite(BUZZER_PIN, LOW);
    }
  }

/* ---------- CH10 RETURN TO HOME ---------- */

  if (ch10 > 1500)
  {
    if (!ch10_started)
    {
      ch10_started = true;
      ch10_timer = millis();
    }

    if (millis() - ch10_timer > 2000)
    {
      RTH = true;
    }
  }
  else
  {
    ch10_started = false;
  }

/* ---------- MOTOR OUTPUT (basic passthrough) ---------- */

  int throttle = map(ch3, 1000, 2000, 1000, 2000);

  esc1.writeMicroseconds(throttle);
  esc2.writeMicroseconds(throttle);
  esc3.writeMicroseconds(throttle);
  esc4.writeMicroseconds(throttle);

/* ---------- DEBUG ---------- */

  Serial.print("Speed m/s: ");
  Serial.println(speed_mps);

}