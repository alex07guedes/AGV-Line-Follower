# 🚗 Autonomous Guided Vehicle (AGV) - Line Follower

## 📌 Project Overview
    This project was developed for the Laboratory of Integrated Systems (LABSI) course at ISEP. 
    It consists of an Autonomous Guided Vehicle (AGV) that follows a path using infrared sensors and detects obstacles. 
    The system is controlled by an ATmega328P and a L298N motor driver, with an LCD display providing real-time feedback.

## 🔧 Hardware Components
 
The AGV is built with the following components:
    
    Microcontroller:
      ATmega328P – Handles all control logic, sensor reading, and motor actuation.
    
    Sensors:
      TCRT5000 (x3) – Infrared line-following sensors to detect track boundaries.
      HC-SR04 – Ultrasonic sensor for obstacle detection.
      HC-020K (x2) – Rotary encoders for speed measurement.
    
    Motors and Driver:
      TT Gear Motors (x2) – DC motors with integrated gear reduction.
      L298N Motor Driver – Controls motor speed and direction using PWM.
    
    Display:
      LCD 16x2 with I2C Module – Displays speed and other important data.
    
    Power Supply:
      Li-ion Battery 7.4V – Provides power to motors and microcontroller.

## 💻 Software and Code Structure
    The software is developed in C and is structured into different modules for better organization.

## Main Features:
    ✔ Line-following algorithm using infrared sensors.
    ✔ Obstacle detection and avoidance with ultrasonic sensor.
    ✔ PWM motor control using the L298N driver.
    ✔ Speed measurement using rotary encoders.
    ✔ Real-time data display on an LCD.
