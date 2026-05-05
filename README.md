# Collision Avoidance Robot

A simple robot that automatically stops when an obstacle is detected within 20cm.

<img width="300" height="400" alt="robot" src="https://github.com/user-attachments/assets/0de96723-451d-4223-9de1-72768fe8c7f9" />


## How It Works

The HC-SR04 ultrasonic sensor continuously measures the distance to objects in front of the robot. When an obstacle is detected within 20cm, the Arduino sends a signal to the L298N motor driver to stop the motors. When the path is clear, the robot resumes moving forward.

## Components

| Component | Quantity | Details |
|---|---|---|
| Microcontroller | 1 | Arduino Uno R3 |
| Motor Driver | 1 | L298N |
| Ultrasonic Sensor | 1 | HC-SR04 |
| Chassis | 1 | 2WD Robot Chassis |
| Power Supply | 1 | 12V Battery |

## Circuit Diagram
*[Add schematic here]*

## Scope and Limitations
- Stop/go logic only — no steering around obstacles
- Detection range capped at 20cm
- Forward-facing sensor only, no peripheral detection

## Built With
- Arduino IDE
- C++

## Designer
Elohim Dzangare — 05.2026
