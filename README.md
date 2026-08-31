<div align="center">

# 🚁 Project Falcon
### ESP32-Based Quadcopter Prototype

An experimental quadcopter prototype built around an **ESP32** flight controller, **custom PCB**, **BLDC motors**, and a hand-tuned **embedded flight control algorithm**. The project covers the full stack of building a small UAV from scratch — embedded firmware, PCB design, sensor integration, and flight stabilization.

![Cover](images/cover.png)

![ESP32](https://img.shields.io/badge/ESP32-Flight_Controller-blue?style=for-the-badge)
![Embedded](https://img.shields.io/badge/Embedded-Systems-success?style=for-the-badge)
![PCB](https://img.shields.io/badge/Custom-PCB-orange?style=for-the-badge)
![Arduino](https://img.shields.io/badge/Arduino-IDE-00979D?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Prototype-yellow?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-lightgrey?style=for-the-badge)

</div>

---

## 📖 Overview

**Project Falcon** is an ESP32-based quadcopter prototype developed as an undergraduate embedded systems project. The goal was to design and build a low-cost quadcopter from the ground up — integrating a custom PCB, IMU and GPS sensors, BLDC motors with electronic speed controllers, wireless RC control, and a servo-driven payload deployment mechanism.

The prototype successfully achieved:

- Motor synchronization
- Lift-off
- A working embedded flight controller
- Full PCB and sensor integration
- Payload deployment mechanism
- Multiple rounds of flight testing

Stable hovering and precise flight control are still in progress, pending further PID tuning, sensor calibration, and vibration isolation.

---

## 🚧 Project Status

| Milestone | Status |
|---|---|
| Hardware Integration | ✅ Completed |
| Custom PCB Design | ✅ Completed |
| Flight Controller Firmware | ✅ Completed |
| Sensor Integration | ✅ Completed |
| Lift-off | ✅ Achieved |
| Flight Testing | ✅ Completed |
| Stable Hover / Flight Control | ⚠️ In Progress |

---

## ✨ Features

- ESP32-based flight controller
- Custom-designed PCB for power and signal integration
- MPU6500 6-axis IMU for orientation sensing
- Neo-6M GPS module for position tracking
- 4-in-1 ESC for motor speed control
- Li-Po battery power system
- FlySky FS-i6 transmitter with FS-iA6 receiver for wireless control
- Servo-based payload deployment mechanism
- PID-based stabilization algorithm
- Field-tested prototype flights

---

## 🛠 Hardware Components

| Component | Description |
|---|---|
| ESP32 | Main flight controller |
| MPU6500 | 6-axis IMU sensor |
| Neo-6M GPS | Position tracking |
| 4× A2212 BLDC Motors | Propulsion |
| 4-in-1 ESC | Motor speed control |
| FlySky FS-iA6 Receiver | Radio communication |
| 2200 mAh 3S Li-Po Battery | Power supply |
| Custom PCB | Flight controller & power integration |
| Servo Motor | Payload deployment |

---

## 💻 Software & Tools

- Arduino IDE
- Embedded C++
- ESP32 core / framework
- PID control algorithm

---

## 📷 Prototype

<p align="center">
<img src="images/prototype.png" width="700">
</p>

---

## ⚡ Circuit Diagram

<p align="center">
<img src="images/pinout.png" width="700">
</p>

---

## 🧩 Custom PCB

<p align="center">
<img src="images/pcb_board.jpg" width="700">
</p>

---

## 📸 Flight Demonstration

<div align="center">

<img src="images/flight-test.gif" width="75%"/>

> 🚁 Prototype flight test — lift-off and flight-control evaluation.

</div>

---

## 🔌 System Architecture

```text
            FlySky Transmitter
                    │
                    ▼
             FlySky Receiver
                    │
                    ▼
          ESP32 Flight Controller
                    │
     ┌─────────┬─────────┬─────────┐
     ▼         ▼         ▼         ▼
  MPU6500     GPS      Servo    4-in-1 ESC
                                     │
                            ┌────────┴────────┐
                            ▼                 ▼
                       BLDC Motors       Propellers
```

---

## ⚙️ Working Principle

1. The ESP32 receives control commands from the FlySky receiver.
2. The MPU6500 IMU supplies real-time inertial measurement data.
3. A PID controller computes the required stabilization corrections.
4. The ESP32 sends corrected control signals to the ESC.
5. The ESC regulates the speed of each BLDC motor.
6. The BLDC motors generate thrust for flight.
7. The GPS module provides positional data.
8. The servo motor triggers the payload deployment mechanism on command.

---

## 📈 Experimental Results

**Achieved**
- Custom PCB integration
- Reliable sensor communication
- Motor synchronization
- Successful lift-off
- Working payload deployment mechanism
- Multiple flight test sessions

**Current Limitations**
- Stable hovering not yet fully achieved
- PID gains require further tuning
- IMU calibration needs refinement
- Mechanical vibration affects flight stability
- Precise flight-path control needs further development

---

## 📚 Lessons Learned

This project provided hands-on experience in:

- Embedded systems development
- PCB design and fabrication
- Flight control theory
- Sensor integration and calibration
- PID tuning
- Power electronics
- End-to-end drone system development
- Hardware debugging and testing

---

## 📂 Repository Structure

```text
Project-Falcon/
│
├── README.md
├── LICENSE
│
├── images/
│   ├── cover.png
│   ├── prototype.png
│   └── flight-test.gif
│
├── pinout.png
├── pcb_board.jpg
│
└── src/
    └── Flight_Controller.ino
```

---

## 🚀 Future Improvements

- [ ] Autonomous navigation
- [ ] Optical flow sensor for position hold
- [ ] Improved PID controller tuning
- [ ] Better IMU calibration routines
- [ ] Altitude hold mode
- [ ] FPV camera integration
- [ ] Obstacle avoidance
- [ ] Mobile monitoring app
- [ ] AI-assisted flight stabilization

---

## 👨‍💻 Author

**Ruhit Mondal**
B.Sc. in Electrical & Electronic Engineering (EEE)
Ahsanullah University of Science and Technology (AUST)
📍 Bangladesh

---

## ⭐ Support

If you found this project interesting, consider giving this repository a **Star ⭐** — it helps others discover it too.
