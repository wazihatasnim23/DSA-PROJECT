# DSA_Project  
Dynamic ticket management system using heap-based priority scheduling and time simulation in C++

---

# Dynamic Support Ticket Management System (DSA Project)

## 📌 Overview  
This project implements a Dynamic Support Ticket Management System using Data Structures and Algorithms (DSA). It simulates a real-world support system where tickets arrive over time and are assigned to available agents based on priority.

The system dynamically manages:
- Ticket assignment  
- Agent availability  
- Time progression  

---

## ⚙️ Features  
- Add support tickets dynamically  
- Add and remove support agents  
- Time-based simulation using TICK  
- Priority-based ticket scheduling  
- Automatic priority increase over waiting time  
- Track system state in real time  

---

## 🧾 Ticket Model  
- ticket_id: Unique identifier  
- arrival_time: Time when ticket is created  
- base_priority: Initial priority  
- wait_time: Time spent waiting  
- status: WAITING / IN_PROGRESS / RESOLVED  

---

## 👨‍💻 Agent Model  
- agent_id: Unique identifier  
- status: AVAILABLE / BUSY  
- current_ticket: Assigned ticket  

---

## 🧠 Scheduling Logic  

Each agent handles only one ticket at a time.

Tickets are assigned based on:

Effective Priority = base_priority + wait_time

Higher effective priority gets processed first.

Each ticket is resolved in exactly 1 time unit.

Priority increases automatically as time passes.

---

## 🧱 Data Structures Used  
- Max Heap → for ticket priority management  
- Set → for available agents  
- Map → for busy agents tracking  
- Set → for resolved tickets  

---

## ⌨️ Commands  

| Command | Description |
|--------|-------------|
| ADD_TICKET id priority | Add a new ticket |
| ADD_AGENT id | Add a new agent |
| REMOVE_AGENT id | Remove an available agent |
| TICK | Advance time by 1 unit |
| QUERY | Display system status |

---

## 📥 Input Format  
Commands are given line by line until EOF.

---

## 📤 Output Format (QUERY)  
For each QUERY, output:

- Current time  
- Waiting tickets (priority, ticket_id)  
- Busy agents with tickets  
- Resolved tickets  

---

## 🧪 Example  

### Input
ADD_AGENT 1  
ADD_AGENT 2  
ADD_TICKET 101 5  
ADD_TICKET 102 3  
TICK  
QUERY  
TICK  
ADD_TICKET 103 10  
QUERY  
TICK  
QUERY  

---

### Output
Time: 1  
Waiting: []  
Busy Agents: [(1,101),(2,102)]  
Resolved: []  

Time: 2  
Waiting: []  
Busy Agents: [(1,103)]  
Resolved: [101,102]  

Time: 3  
Waiting: []  
Busy Agents: []  
Resolved: [101,102,103]  

---

## ⏱ Complexity  
- Ticket insertion: O(log N)  
- Assignment: O(log N)  
- Agent operations: O(log M)  
- Query: O(N log N)  

---

## 🚀 How to Run  

### Compile
g++ main.cpp -o system  

### Run
./system  

### Or using file input
./system < input.txt  

---

## 📚 Concepts Used  
- Heap (Priority Queue)  
- Greedy Scheduling  
- Simulation  
- STL (set, map, vector)  
