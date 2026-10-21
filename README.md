# Wi-Fi-Deauthentication-Attack-Detector
An ESP32 based Wi-Fi deauthentication detection project that monitors suspicious wireless management frames and triggers LED and buzzer alerts for cybersecurity awareness.


# Wi-Fi Deauthentication Attack Detector

An IoT-based cybersecurity project designed to detect suspicious Wi-Fi deauthentication traffic and trigger LED and buzzer alerts using a microcontroller.

## 📌 Project Overview

Wi-Fi deauthentication attacks can disconnect devices from wireless networks by exploiting Wi-Fi management frames. This project explores wireless traffic monitoring and suspicious activity detection using an embedded device.

The system monitors relevant wireless frames, counts suspicious events, and activates an LED and buzzer when a configured detection threshold is reached.

## 🎯 Features

- Wi-Fi deauthentication traffic monitoring
- Suspicious frame detection
- Configurable detection threshold
- LED-based visual alerts
- Buzzer-based audible alerts
- Embedded cybersecurity learning
- IoT and wireless security experimentation

## 🛠️ Hardware Requirements

- ESP32 DevKit V1 or ESP8266 NodeMCU, depending on firmware
- Red LED
- 220Ω resistor
- Active buzzer
- Breadboard and jumper wires
- USB cable

## 💻 Software Requirements

- Arduino IDE
- Appropriate ESP32 or ESP8266 board package
- Board-compatible firmware

## ⚙️ Working Principle

1. The microcontroller monitors supported Wi-Fi traffic.
2. Relevant management frames are examined.
3. Suspicious events are counted within a time interval.
4. The event count is compared with a configured threshold.
5. The LED and buzzer provide alerts when the detection condition is met.

**System Flow:**  
Wi-Fi Traffic → Frame Monitoring → Event Detection → Threshold Check → LED & Buzzer Alert

## 🚀 Installation and Setup

1. Install the Arduino IDE.
2. Install the board package for your microcontroller.
3. Clone or download this repository.
4. Open the appropriate firmware sketch.
5. Select the correct board and COM port.
6. Verify GPIO assignments and compile the firmware.
7. Upload the code to the microcontroller.
8. Open the Serial Monitor to view detection messages.
9. Test the alert system in an authorized laboratory environment.

**Note:** ESP8266 and ESP32 use different hardware-specific APIs in some cases. Ensure the firmware matches your selected board.

## 🧪 Testing

- Verify that the microcontroller starts successfully.
- Test LED and buzzer alert functionality.
- Check event counting and threshold logic.
- Evaluate detection behavior using authorized test traffic.
- Document false positives and detection limitations.

## 🛡️ Cybersecurity Relevance

This project demonstrates the fundamentals of wireless network security, Wi-Fi management frames, embedded monitoring, and security alert systems.

Additional defensive measures include enabling Protected Management Frames (802.11w/PMF) and using supported modern Wi-Fi security configurations.

## 🔮 Future Improvements

- Improve detection accuracy.
- Reduce false-positive alerts.
- Add an OLED display or web dashboard.
- Store event logs with timestamps.
- Improve ESP32-specific firmware support.
- Add real-time monitoring and reporting.

## 📁 Repository Structure

```text
wifi-deauthentication-attack-detector/
├── README.md
├── firmware/
├── images/
├── docs/
└── LICENSE
```

## ⚠️ Disclaimer

This project is intended for educational purposes, defensive cybersecurity research, and authorized laboratory testing only. Do not disrupt networks or test equipment without permission. This prototype detects suspicious activity but does not guarantee prevention of wireless attacks.

## 👨‍💻 Author

**Harshit Rawat**  
First-Year B.Tech Student | Cybersecurity & IoT
