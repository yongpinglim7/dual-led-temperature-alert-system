# Dual-LED Temperature Alert System
## Project Overview
This project presents a Dual-LED Temperature Alert System designed to monitor real-time temperature and provide immediate visual feedback using LEDs. The system uses a temperature sensor to detect environmental temperature and activates different alert levels when predefined thresholds are exceeded.

The system demonstrates a simple embedded monitoring solution using an Arduino platform.

---

## Objective
The objective of this project is to design and implement a reliable prototype that can:

- Monitor real-time temperature
- Provide visual alerts using LEDs
- Demonstrate multi-level warning logic in an embedded system

---

## Components Used

- Arduino Mega 2560
- DHT11 Temperature and Humidity Sensor
- Breadboard
- LEDs (Warning LED and Alert LED)
- Resistors
- Jumper Wires

---

## Hardware Setup

The hardware components are connected as follows:

|   Component  |   Connection  |
|--------------|---------------|
| DHT11 Sensor | Digital Pin 2 |
|  Warning LED | Digital Pin 7 |
|   Alert LED  | Digital Pin 8 |

The DHT11 sensor reads the ambient temperature and sends the data to the Arduino board for processing.

### Hardware Implementation

![Hardware Setup](C:\Users\User\Downloads\Gemini_Generated_Image_r5oa7cr5oa7cr5oa.png)

---

## Software Logic

The system operates using multi-level temperature thresholds:

| Temperature Condition |        System Response           |
|-----------------------|----------------------------------|
|   Temperature < 32°C  | Both LEDs OFF (Normal Condition) |
|   Temperature ≥ 32°C  |        Warning LED ON            |
|   Temperature ≥ 34°C  | Warning LED ON + Alert LED ON    |

The program continuously reads the temperature value from the sensor and updates the LED states accordingly.

---

## System Result

The system was tested under different temperature conditions to verify the alert logic.

| Temperature |  System State  |   LED Status   |
|-------------|----------------|----------------|
|    26°C     |      Normal    |  Both LEDs OFF |
|    32°C     |     Warning    | Warning LED ON |
|    34°C     | Critical Alert |   Both LEDs ON |

These results confirm that the system successfully detects temperature changes and activates the correct alert level.


---

## Demonstration Video

Project Presentation Video:

https://youtu.be/XToy7RldGQM

---

## Conclusion

The Dual-LED Temperature Alert System successfully demonstrates a simple embedded monitoring system capable of detecting temperature changes and triggering visual alerts. This project highlights the integration of sensor input, microcontroller processing, and output indicators.

Future improvements could include:

- Adding an LCD display
- IoT connectivity for remote monitoring
- Data logging for temperature analysis

---

## Author

Lim Yong Ping  
Universiti Malaysia Terengganu
