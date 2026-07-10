<div align="center">

# 🚁 Project Falcon
### ESP32-Based Quadcopter Prototype

An experimental quadcopter prototype designed using **ESP32**, **custom PCB**, **BLDC motors**, and **embedded flight control algorithms**. This project focuses on learning embedded systems, PCB design, sensor integration, and flight stabilization.

![Cover](images/cover.png)

![ESP32](https://img.shields.io/badge/ESP32-Flight_Controller-blue?style=for-the-badge)
![Embedded](https://img.shields.io/badge/Embedded-Systems-success?style=for-the-badge)
![PCB](https://img.shields.io/badge/Custom-PCB-orange?style=for-the-badge)
![Arduino](https://img.shields.io/badge/Arduino-IDE-00979D?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Prototype-yellow?style=for-the-badge)

</div>

---

# 📖 Project Overview

Project Falcon is an ESP32-based quadcopter prototype developed as an undergraduate embedded systems project.

The objective of this project was to design a low-cost quadcopter capable of performing basic flight operations while integrating a custom PCB, sensors, and wireless control.

The prototype successfully achieved:

- Motor synchronization
- Lift-off
- Embedded flight controller implementation
- PCB integration
- Flight testing

Stable hovering and precise flight control remain under development due to PID tuning and sensor calibration challenges.

---

# 🚧 Project Status

> **Prototype Successfully Developed**

✔ Hardware Integration Completed

✔ Custom PCB Designed

✔ Flight Controller Developed

✔ Lift-off Achieved

⚠ Stable Flight Control Under Development

---

# ✨ Features

- 🚁 ESP32 Flight Controller
- 🔷 Custom PCB Design
- 🧭 MPU6500 IMU
- 📍 Neo-6M GPS
- ⚡ 4-in-1 ESC
- 🔋 Li-Po Battery System
- 🎮 FlySky FS-i6 Remote Control
- 🛰 Wireless Flight Control
- 📦 Payload Deployment Mechanism
- 🛠 PID Control Algorithm
- 🧪 Prototype Flight Testing

---

# 🛠 Hardware Components

| Component | Description |
|-----------|-------------|
| ESP32 | Main Flight Controller |
| MPU6500 | IMU Sensor |
| Neo-6M GPS | Position Tracking |
| 4× A2212 BLDC Motors | Propulsion |
| 4-in-1 ESC | Motor Speed Control |
| FlySky FS-iA6 Receiver | Radio Communication |
| Li-Po Battery | Power Supply |
| Custom PCB | Flight Controller Board |
| Servo Motor | Payload Release |

---

# 💻 Software Used

- Arduino IDE
- Embedded C++
- ESP32 Framework
- PID Control Algorithm

---

# 📷 Prototype

<p align="center">
<img src="images/prototype.jpg" width="700">
</p>

---

# 🎥 Flight Test

> Prototype Flight Test (Stable flight is under development)

<p align="center">
<img src="images/flight-test.gif" width="700">
</p>

---

# 🧩 System Block Diagram

<p align="center">
<img src="images/block-diagram.png" width="700">
</p>

---

# ⚡ Circuit Diagram

<p align="center">
<img src="images/circuit.png" width="700">
</p>

---

# 🔌 Hardware Architecture

```text
            FlySky Transmitter
                    │
                    ▼
          FlySky Receiver
                    │
                    ▼
          ESP32 Flight Controller
                    │
    ┌──────────┬──────────┬──────────┐
    ▼          ▼          ▼          ▼
 MPU6500      GPS       Servo      ESC
                                   │
                          ┌────────┴────────┐
                          ▼                 ▼
                     BLDC Motors       Propellers
```

---

# ⚙ Working Principle

1. ESP32 receives commands from the FlySky receiver.
2. MPU6500 continuously measures orientation.
3. PID controller calculates the required correction.
4. ESC adjusts motor speed.
5. BLDC motors generate thrust for flight.
6. GPS provides positioning information.
7. Servo controls payload deployment.

---

# 📈 Experimental Results

### Successfully Achieved

- ✔ Custom PCB Integration
- ✔ Sensor Communication
- ✔ Motor Synchronization
- ✔ Lift-off
- ✔ Payload Mechanism
- ✔ Flight Testing

### Current Limitations

- Stable hovering not achieved
- PID tuning requires further optimization
- IMU calibration needs improvement
- Flight stability affected by vibration

---

# 📚 Lessons Learned

This project provided practical experience in:

- Embedded Systems
- PCB Design
- Flight Control
- Sensor Integration
- PID Tuning
- Power Electronics
- Drone System Development
- Hardware Debugging

---

# 📂 Repository Structure

```text
Project-Falcon
│
├── README.md
├── LICENSE
│
├── images
│   ├── cover.png
│   ├── prototype.jpg
│   ├── flight-test.gif
│   ├── block-diagram.png
│   └── circuit.png
│
├── src
│   └── Flight_Controller.ino
│
└── hardware
    └── PCB.pdf
```

---

# 🚀 Future Improvements

- Autonomous Navigation
- Optical Flow Sensor
- Improved PID Controller
- Better IMU Calibration
- Altitude Hold
- FPV Camera
- Obstacle Avoidance
- Mobile Monitoring App
- AI-based Flight Assistance

---

# 👨‍💻 Author

**Ruhit Mondal**

B.Sc. in Electrical & Electronic Engineering (EEE)

Ahsanullah University of Science and Technology (AUST)

📍 Bangladesh

---

# ⭐ Support

If you found this project interesting, consider giving it a **Star ⭐**.
