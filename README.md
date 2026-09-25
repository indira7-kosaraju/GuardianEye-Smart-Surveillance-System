# 🔐 GuardianEye – Smart Surveillance System


📖 Project Overview

GuardianEye is an IoT-based smart surveillance system designed to monitor a secured area and detect movement. It uses a PIR sensor to detect motion and an ESP32-CAM to capture images. The captured images can be sent to an authorized user through a Telegram Bot using Wi-Fi.
The system also includes a buzzer, LCD display, flash LED, and servo motor to provide security alerts, status information, and door-control functionality.


✨ Key Features
🚨 Motion Detection – Detects movement using a PIR sensor.
📸 Image Capture – ESP32-CAM captures the scene when motion is detected.
📱 Telegram Alerts – Sends captured images to the authorized user through Telegram.
🔊 Buzzer Alert – Provides an audible security alert.
💡 Flash LED – Provides additional light for the camera.
🚪 Door Control – Servo motor provides lock/unlock functionality.
📟 LCD Display – Displays the current system/PIR status.
📡 Wi-Fi Connectivity – Enables remote communication through Telegram.


🛠 Hardware Components

| Component                      | Purpose                                          |
| ------------------------------ | ------------------------------------------------ |
| **ESP32-CAM**                  | Captures images and provides Wi-Fi communication |
| **PIR Sensor (HC-SR501)**      | Detects motion                                   |
| **Arduino / Controller Board** | Controls the PIR sensor and system operations    |
| **Servo Motor**                | Provides door lock/unlock control                |
| **LCD Display**                | Displays system and PIR status                   |
| **Buzzer**                     | Gives an audible security alert                  |
| **Flash LED**                  | Provides light for the camera                    |
| **Breadboard**                 | Used for circuit connections                     |
| **Jumper Wires**               | Connects the components                          |
| **USB Cable / Power Supply**   | Provides power and programming connection        |



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



📸 Project Preview


🔧 Hardware Prototype

<img width="1672" height="941" alt="ChatGPT Image Sep 25, 2026, 05_27_35 PM" src="https://github.com/user-attachments/assets/bf80d209-dbc1-48ac-82a6-411e1d57aa58" />



