
# 🔐 GuardianEye – Smart Surveillance System

![Arduino IDE](https://img.shields.io/badge/Arduino%20IDE-00979D?logo=arduino&logoColor=white)
![ESP32-CAM](https://img.shields.io/badge/ESP32--CAM-blue)
![IoT](https://img.shields.io/badge/Internet%20of%20Things-IoT-orange)
![Telegram](https://img.shields.io/badge/Telegram-Bot-blue)
![Wi-Fi](https://img.shields.io/badge/Wi--Fi-Connectivity-green)

---

## 📖 Project Overview

**GuardianEye** is an IoT-based smart surveillance system designed to detect movement and monitor a secured area.

The system uses a **PIR sensor and ESP32-CAM** to detect motion, capture images, and send security alerts through a **Telegram Bot**. It also includes a buzzer, LCD display, flash LED, and servo motor for security and door-control functions.

---

# ✨ Key Features

- 🚨 PIR-based Motion Detection
- 📸 Image Capture using ESP32-CAM
- 📱 Telegram Security Alerts
- 🔊 Buzzer Alert
- 💡 Flash LED Control
- 🚪 Servo-based Door Control
- 📟 LCD Status Display
- 📡 Wi-Fi Connectivity
- 🔄 Serial Communication
- ⚡ Low-Cost IoT Prototype

---

# 🛠 Hardware Components

| Component                      | Purpose                                          |
| ------------------------------ | ------------------------------------------------ |
| **ESP32-CAM**                  | Captures images and communicates through Wi-Fi   |
| **PIR Sensor (HC-SR501)**      | Detects human movement                           |
| **Arduino / Controller Board** | Reads PIR sensor and communicates with ESP32-CAM |
| **LCD Display**                | Displays system/PIR status                       |
| **Servo Motor**                | Provides the physical door lock/unlock mechanism |
| **Buzzer**                     | Provides an audible alert                        |
| **ESP32-CAM Flash LED**        | Provides illumination for image capture          |
| **Breadboard**                 | Circuit prototyping                              |
| **Jumper Wires**               | Component connections                            |
| **USB Cable / Power Supply**   | Powers and programs the system                   |


---

# 💻 Software Used

- Arduino IDE
- Embedded C/C++
- ESP32 Camera Library
- UniversalTelegramBot
- ArduinoJson
- Wi-Fi
- Servo Library
- LiquidCrystal Library
- Telegram Bot API

---

# 📂 Project Structure

```text
GuardianEye-Smart-Surveillance-System
│
├── security-bot.ino
├── security.ino
│
├── Images
│   ├── hardware-prototype.png
│   └── working-prototype.png
│
└── README.md



---

⚙️ System Workflow

                👤 Person Approaches
                        │
                        ▼
                ┌──────────────┐
                │ PIR Sensor   │
                └──────┬───────┘
                       │
                  Motion Detected
                       │
                       ▼
                ┌──────────────┐
                │ Arduino /    │
                │ Controller   │
                └──────┬───────┘
                       │
                Serial Communication
                       │
                       ▼
                ┌──────────────┐
                │  ESP32-CAM   │
                └──────┬───────┘
                       │
                  Capture Image
                       │        
                       ▼
                ┌──────────────┐
                │ Wi-Fi +      │
                │ Telegram Bot │
                └──────┬───────┘
                       │
                       ▼
                📱 User Receives Photo
                       │
                       ▼
                User Checks the Photo
                       │
                ┌──────┴───────┐
                │              │
                ▼              ▼
           Normal Person   Suspicious/
                           Unauthorized
                │              │
                ▼              ▼
              Normal       Buzzer / Door
                           Control





---

# 📸 Project Preview

## 🔧 Hardware Prototype

<img width="1672" height="941" alt="ChatGPT Image Sep 25, 2026, 05_27_35 PM" src="https://github.com/user-attachments/assets/03c82a72-eb39-4ca5-b08f-3e93414e4458" />


---

## 🚗 Working Prototype

<img width="1536" height="1024" alt="ChatGPT Image Sep 25, 2026, 05_27_26 PM" src="https://github.com/user-attachments/assets/e90c3e5b-c030-4b96-8ada-50346d8fc6b6" />


---

# 🚀 Technologies Used

* ESP32-CAM
* Embedded C/C++
* Arduino IDE
* IoT
* PIR Sensor
* Telegram Bot API
* Wi-Fi
* LCD Display
* Servo Motor
* Buzzer

---

# 🔮 Future Enhancements

* 📱 Mobile Application
* ☁️ Cloud Image Storage
* 🤖 AI-Based Person Detection
* 👤 Face Recognition
* 📊 Security Event History
* 🔐 Advanced Access Control

---

# 🎯 Applications

* Home Security
* Smart Door Monitoring
* Office Security
* College/School Security
* Restricted Area Monitoring
* Remote Surveillance

---

# 👩‍💻 Author

**INDIRA KOSARAJU**

B.Tech – CSE(IoT,Cybersecurity & Blockchain Technology)

GitHub: [https://github.com/indira7-kosaraju](https://github.com/indira7-kosaraju)

---

## ⭐ If you found this project helpful, consider giving it a Star!

