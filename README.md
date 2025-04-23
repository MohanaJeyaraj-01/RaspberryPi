# RaspberryPi


# 🚮 Smart Dustbin using ESP32

A contactless, automated smart dustbin built using **ESP32**, **ultrasonic sensor**, and **servo motor**. The lid opens automatically when a person approaches, and closes after a short delay — ensuring hygiene and convenience.

---

## 🧠 Features

- Automatically detects hand presence using ultrasonic sensor
- Opens and closes lid with servo motor
- Reduces the need for physical contact
- Built using low-cost and easily available components

---

## 🛠️ Components Used

| Component           | Quantity |
|--------------------|----------|
| ESP32 Board         | 1        |
| Ultrasonic Sensor (HC-SR04) | 1        |
| Servo Motor (SG90 or MG995) | 1        |
| Jumper Wires        | As needed |
| Breadboard (optional) | 1        |
| USB cable (for ESP32) | 1        |

---

## 🔌 Circuit Connections

| Ultrasonic Sensor | ESP32 Pin |
|------------------|------------|
| VCC              | 3.3V       |
| GND              | GND        |
| Trig             | D12        |
| Echo             | D14        |

| Servo Motor | ESP32 Pin |
|-------------|-----------|
| VCC         | 5V        |
| GND         | GND       |
| Signal      | D27       |

---

## 🧾 How it Works

1. The ultrasonic sensor constantly measures distance.
2. When an object (like a hand) is detected within 15 cm:
   - The servo motor rotates to open the lid.
   - After 3 seconds, the lid closes automatically.
3. This prevents physical touch and promotes hygiene.

---

## 📦 Code File

- `smart_dustbin.ino`: Contains the full Arduino code for ESP32.

---

## 📸 Demo

*Insert a GIF or photo here if you have one.*

---

## 🧠 Future Enhancements (Optional)

- Add a "Bin Full" alert using IR sensor.
- Send data to mobile app using Blynk or Firebase.
- Display status on OLED or LCD.
- Add voice alert or buzzer.

---

## 💡 Author

**Mohana Arumugamnayenar**  
**Sowmiya Saravanan**
**Amsa S**
**Suganthi M**
**Supriya J**
**Zeeneth**
**Lathika saran**
**Arundhathi**
**Lavanya**
Dept. of Computer Engineering, MIT – Anna University

---

