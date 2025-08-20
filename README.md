# 🚍 BigBrotherBus – Bus Line Simulator

This project was developed as the **final assignment for the course "Programming Lab I"** (C++).  
Its main goal is to model and simulate the operation of one of the largest bus lines in the city, **Line 60**, by applying key concepts of object-oriented programming, lists, inheritance, polymorphism, and dynamic memory management.  

---

## 📌 Project Overview

The bus company **Line 60** seeks to unify its tracking system to improve both safety and service organization.  
The **BigBrotherBus simulator** reproduces the behavior of buses, stops, and passengers throughout a full day, considering real-world constraints such as limited capacity, priority boarding, route assignments, and replacement of broken vehicles.  

### Main Features
- **Bus modeling**:
  - Modern buses with AC and electric steering  
  - Subtype: Articulated bus ("accordion")  
  - Older buses without AC and with hydraulic steering  
- **Passenger management**:
  - Boarding and exiting at specific stops  
  - Capacity check (no overloading allowed)  
  - Priority for passengers in wheelchairs  
  - Fare calculation based on number of stops traveled  
- **Stops**:
  - Each stop has an ID, a name, an address, and a waiting list of passengers  
- **Dynamic simulation**:
  - GPS system updates bus position every 5 minutes  
  - `TICK` method simulates the passage of time (minute by minute)  
  - Broken buses are replaced, transferring passengers between vehicles  
  - New routes are dynamically assigned at the final stop  
- **Daily summary**:
  - Number of passengers transported per bus and per route  
  - Total fare collected  
  - General statistics for the entire fleet  

---

## 🛠️ Technologies & Concepts
- Language: **C++**
- Paradigm: **Object-Oriented Programming (OOP)**
- Data structures: **static and dynamic lists**
- Dynamic memory management
- Discrete event simulation with `TICK`

---

## ▶️ How to Run the Project

1. Clone the repository:
   ```bash
   git clone https://github.com/PieriFra/TP_FINAL.git
   cd TP_FINAL

2.Compile the program:
  ```bash
  g++ -o BigBrotherBus main.cpp
  ```
3. Run the simulator:
  ```bash
  ./BigBrotherBus
  ```

## 📊 Example Output
At the end of the simulation, the program displays a summary like:
```yaml
Bus #12 – Route A
Passengers transported: 134
Total fare: $12,300

Bus #7 – Route B
Passengers transported: 98
Total fare: $9,450

TOTAL passengers: 232
TOTAL fare collected: $21,750
```

## 🎯 Learning Goals
This project helped put into practice:
- Design and implementation of classes in C++
- Inheritance and polymorphism
- Use of static and dynamic lists
- Simulation of discrete events
- Modular organization of a project
