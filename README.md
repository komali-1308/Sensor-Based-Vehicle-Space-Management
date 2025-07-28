# 🚗 Sensor-Based Smart Parking System using Arduino and IoT

A smart, IoT-enabled parking management system using Arduino, IR sensors, and ThingSpeak. This project addresses urban parking challenges by guiding users to available parking spaces and uploading real-time data to the cloud.

## 📄 Abstract

The increasing number of vehicles has intensified parking issues in urban areas. This project proposes a sensor-based smart parking solution that monitors space availability and uploads real-time data to the cloud using an Arduino Uno, IR sensors, and ThingSpeak. It also features a servo mechanism for gate control and a proximity alert system for wall-distance detection. Users can view parking status remotely via the ThingView app.

## 🧠 Objectives

- Provide real-time parking slot availability
- Guide vehicles efficiently to available spots
- Reduce congestion caused by unauthorized or random parking
- Enable remote monitoring via IoT platforms (ThingSpeak)
- Implement proximity-based servo operation and obstacle alerting

## 🔧 Hardware Components

| Component               | Description                    |
|------------------------|--------------------------------|
| Arduino Uno            | Microcontroller board          |
| IR Sensors (5)         | Slot occupancy detection       |
| LCD 16x2               | Local display of slot status   |
| Servo Motor            | Automated gate control         |
| ESP8266 WiFi Module    | Internet connectivity          |
| Buzzer (optional)      | Wall distance alert            |
| Jumper Wires, Breadboard, Power Supply | Prototyping tools |

## 💻 Software Components

| Software       | Purpose                              |
|----------------|--------------------------------------|
| Arduino IDE    | Coding and uploading to microcontroller |
| ThingSpeak     | IoT cloud platform for data logging  |
| ThingView App  | Mobile monitoring of slot data       |
| Arduino C/C++  | Programming language used            |

## 📐 System Architecture

1. IR sensors detect presence/absence of vehicles in each slot.
2. Sensor data is displayed on an LCD.
3. Every 10 cycles, data is uploaded to ThingSpeak using ESP8266 (via AT commands).
4. Servo motor opens/closes based on distance to wall (IR5).
5. User can view real-time data using the ThingView mobile app.

## 📋 Methodology

- **Sensors** detect vehicle presence.
- **Arduino Uno** processes and displays data.
- **ESP8266** uploads to ThingSpeak.
- **Servo** rotates to 90° or 0° based on proximity (IR5).
- **LCD** displays current slot availability.

## 📈 Results

- ✅ High detection accuracy of IR sensors
- ✅ Effective real-time data upload to ThingSpeak
- ✅ Fast LCD response and clear UI
- ✅ Servo accurately triggered by wall proximity
- ✅ Scalable and adaptable for large parking lots

## 🧪 Testing

- Real-time monitoring of 4 parking slots
- Servo operation tested under different object distances
- Data verified via ThingSpeak and ThingView
- Minimal false positives during real-world testing

## 🌱 Future Scope

- Add mobile/web app for booking/reserving slots
- Payment integration (e.g., PayTM, UPI)
- Predictive analytics for parking demand
- License plate detection with camera integration
- Use of ultrasonic sensors for higher accuracy

## 📚 Literature Survey Highlights

- Several IoT-based smart parking studies emphasize real-time availability, automation, and reduced manpower.
- Our approach integrates these findings with a simple, cost-effective Arduino setup.
- Referenced works explore cloud-based solutions, vehicle authentication, and smart reservations.

## ✅ Conclusion

The Sensor-Based Smart Parking System offers a modern, automated approach to parking management in urban areas. By using affordable hardware and integrating cloud services, it reduces traffic congestion, enhances user experience, and contributes to smarter, more sustainable cities.

## 📁 Repository Structure
├── SmartParking.ino
├── README.md  
└── LICENSE 


