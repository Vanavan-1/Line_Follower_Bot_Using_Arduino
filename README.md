#  Line Follower Robot

## Overview

This project was developed as part of a Semester 2 project and presented in an inter-college robotics competition. The goal was to design and build an autonomous robot capable of following a predefined path using line detection.

Through this project, we gained hands-on experience in embedded systems, motor control, and control algorithms.

---

## Components Used

* Arduino Uno
* L298N Motor Driver
* N20 DC Motors
* IR Line Sensors
* Chassis + Wheels
* Power Supply (Battery)

---

## ⚙️ Working Principle

The robot uses IR sensors to detect the line (black/white contrast). Based on sensor input, the controller adjusts motor speeds to stay on track.

We implemented two control strategies:

### 🔹 Bang-Bang Control

* Simple ON/OFF logic
* If robot deviates → sharp correction
* Easy to implement but less smooth

### 🔹 PID Control

* Proportional–Integral–Derivative control
* Provides smooth and stable movement
* Reduces oscillations and improves accuracy

---

## 📂 Project Structure

* `code/` → Arduino programs
* `images/` → Robot and track images
* `docs/` → Circuit diagram and explanation

---

## ▶️ How to Run

1. Connect components as per circuit diagram
2. Upload Arduino code using Arduino IDE
3. Place robot on track
4. Power ON and observe line following

---

## 📸 Output


<img width="960" height="1280" alt="image" src="https://github.com/user-attachments/assets/e59b15f9-4092-4531-b6eb-4e61430118d5" />


---

## 🎯 Learning Outcomes

* Basics of robotics and embedded systems
* Motor control using L298N
* Implementation of control algorithms (Bang-Bang & PID)
* Real-world problem solving in competitions

---

## 👥 Team / Author
Vanavan U
Santhosh P
Shanjay S

SSN College Of Engineering
Your Name
(You can add teammates if any)

---

## 📜 License

This project is licensed under the MIT License.
