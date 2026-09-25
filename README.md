
ESP32-CAM Smart Security and Door Monitoring System
📌 Project Overview
This project is a small IoT-based security system that combines a PIR
motion sensor, ESP32-CAM, Telegram Bot, buzzer, servo motor, LCD
display, and LED/flash control.

The system detects movement, requests a photograph from the ESP32-CAM,
and sends the captured image to an authorized Telegram user. The user
can then send Telegram commands to control the camera flash, buzzer, and
door-control output.

Important: The provided code does not perform AI/face recognition
or automatically decide whether a person is suspicious. The user
receives the photo and makes the decision.

🔧 Hardware Components
ESP32-CAM (AI-Thinker)

PIR motion sensor (HC-SR501)

Arduino/controller board

Servo motor

Buzzer

16x2 LCD display

ESP32-CAM flash LED

Jumper wires

Breadboard / connection board

USB power/programming connection

🧩 Software / Technologies
Arduino IDE

ESP32-CAM

Arduino

C/C++ (Arduino)

Wi-Fi

Telegram Bot API

UniversalTelegramBot library

ArduinoJson library

ESP32 Camera library

LiquidCrystal library

Servo library

⚙️ How the Project Works
1. Motion Detection
The PIR sensor continuously checks for movement.

PIR = 0 → no motion detected

PIR = 1 → motion detected

The PIR value is displayed on the 16x2 LCD.

2. Security Alert
When the PIR detects motion, the Arduino sends information through
Serial communication to the ESP32-CAM.

The message contains the Telegram details, Wi-Fi details, the text
Security Alert, and a photo request.

3. Photo Capture
The ESP32-CAM receives the photo request and captures an image using its
camera.

4. Telegram Notification
The ESP32-CAM connects to Telegram's server and uploads the captured
image to the configured Telegram chat.

The authorized user can therefore see the captured image remotely.

5. User Decision
The system does not identify the person automatically.

The user checks the received photo and can decide whether further action
is required.

6. Hardware Control
The Telegram bot supports commands for:

Taking a new photo

Turning the ESP32-CAM flash ON/OFF

Turning the buzzer ON/OFF

Controlling the ESP32 lock output

The second Arduino program also controls a servo motor using Serial
commands.

📱 Telegram Commands
Command Function

/start Shows the available commands
/photo Captures and sends a new photo
/flash Toggles the ESP32-CAM flash LED
/1 Turns the buzzer/alarm output ON
/2 Turns the buzzer/alarm output OFF
/3 Sets the ESP32 LOCK output HIGH
/4 Sets the ESP32 LOCK output LOW

💡 LED / Flash Function
The ESP32-CAM has a flash LED connected to GPIO 4 in the code.

The flash is controlled by:

/flash
It toggles the flash LED between ON and OFF.

The provided code does not automatically turn this LED ON when the
PIR detects motion. Therefore, it should be described as the ESP32-CAM
flash LED, not as an automatic motion indicator.

🔊 Buzzer Function
The buzzer is used as an alarm output.

From Telegram:

/1 → Buzzer ON
/2 → Buzzer OFF
The second Arduino program also briefly activates the buzzer when it
receives Serial command 2.

🚪 Servo Motor
The second Arduino program controls a servo motor.

The servo is attached to pin 5.

Its initial position is:

0°
When Serial command 1 is received:

Servo → 90°
When Serial command 2 is received:

Servo → 0°
Buzzer → ON briefly
The servo can therefore be used as the physical door lock/unlock
mechanism.

Important Code Note
The two provided programs are not completely connected for direct
Telegram-to-servo control.

The ESP32 Telegram program uses:

/3 → LOCK output HIGH
/4 → LOCK output LOW
while the Arduino servo program expects:

Serial '1' → Servo 90°
Serial '2' → Servo 0°
So /3 and /4 should not be claimed to directly move the servo unless
an additional connection/control layer is added.

🖥️ LCD Display
The 16x2 LCD displays the initial message:

WELCOME
During operation, it displays the PIR sensor value:

P:0
or

P:1
where:

P:0 = no motion

P:1 = motion detected

🔄 Overall System Flow
Person approaches
       ↓
PIR detects movement
       ↓
PIR = 1
       ↓
Arduino sends security alert
       ↓
ESP32-CAM receives photo request
       ↓
ESP32-CAM captures image
       ↓
Image sent to Telegram
       ↓
User checks the image
       ↓
User can send Telegram commands
       ↓
Buzzer / Flash / Lock output controlled
📂 Project Files
Security-Project/
│
├── security-bot.ino
│   └── ESP32-CAM + Wi-Fi + Telegram + camera + flash + alarm/lock output
│
├── security.ino
│   └── PIR + LCD + servo + buzzer + Serial communication
│
└── README.md
🔐 Configuration
Before uploading the ESP32-CAM program, configure:

const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

String BOTtoken = "YOUR_BOT_TOKEN";
String CHAT_ID = "YOUR_CHAT_ID";
Replace these placeholders with your actual Wi-Fi and Telegram Bot
details.

Do not publish real Wi-Fi passwords, Telegram bot tokens, or private
credentials on GitHub.

🚀 Setup
Connect the ESP32-CAM and other hardware according to the circuit.

Install the required Arduino libraries.

Select the correct ESP32-CAM board in Arduino IDE.

Enter Wi-Fi credentials.

Enter the Telegram Bot Token.

Enter the authorized Telegram Chat ID.

Upload the ESP32-CAM code.

Upload the Arduino/controller code.

Open the Serial Monitor and check communication.

Start the Telegram bot with /start.

Move in front of the PIR sensor.

Check whether the security photo reaches Telegram.

Test /photo, /flash, /1, and /2.

Test the servo separately using the Serial commands 1 and 2.

🎯 Main Features
Motion detection using PIR sensor

ESP32-CAM image capture

Telegram photo notification

Remote photo request

ESP32-CAM flash control

Buzzer/alarm control

Servo-based door mechanism

LCD status display

Wi-Fi communication

Serial communication between controllers

⚠️ Current Limitations
No face recognition is implemented.

No AI-based suspicious-person detection is implemented.

The ESP32-CAM flash is controlled by /flash; it is not
automatically triggered by PIR in the provided code.

Telegram /3 and /4 control the ESP32 LOCK output, while the
servo code expects Serial 1 and 2. These parts require proper
integration if Telegram commands are intended to directly operate
the servo.

The project depends on Wi-Fi and Telegram connectivity for remote
photo delivery.

📌 Project Summary
This project demonstrates an IoT-based security and door-monitoring
system. A PIR sensor detects movement, the Arduino communicates the
event to an ESP32-CAM, and the ESP32-CAM captures and sends an image to
an authorized Telegram user. The user can then control available
security outputs such as the buzzer, camera flash, and door-control
mechanism through the Telegram bot.
