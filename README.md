# DSA-PROJECT
Dynamic Help Desk Ticket Management System
📌 Overview
This project implements a Dynamic Help Desk Ticket Management System using Data Structures and Algorithms in C++. The system simulates a customer-support environment where incoming tickets are stored, prioritized, and assigned to available support agents.

The system manages:

Dynamic ticket registration

Support agent management

Simulation of time

Priority-based ticket assignment

Automatic increase in ticket priority while waiting

Real-time system monitoring

⚙️ Main Features
Create new support tickets during runtime

Register new support agents

Remove agents who are currently available

Process the system using TICK

Automatically assign the highest-priority tickets

Increase ticket priority according to waiting time

Display the current status of tickets and agents

🧾 Ticket Structure
Every ticket contains the following information:

ticket_id → Unique identification number

arrival_time → Time at which the ticket entered the system

base_priority → Priority assigned when the ticket was created

wait_time → Number of time units the ticket has remained unassigned

status → WAITING / IN_PROGRESS / RESOLVED

Priority Calculation
The priority of a waiting ticket is calculated as:

Effective Priority = Base Priority + Waiting Time

Therefore, a ticket that has been waiting for a longer period can gradually become more important.

👨💻 Agent Structure
Each support agent contains:

agent_id → Unique identification number

status → AVAILABLE / BUSY

current_ticket → Ticket currently assigned to the agent

An agent can process only one ticket at a time.

🧠 Scheduling Strategy
The system follows a highest-priority-first scheduling strategy.

When an agent becomes available:

The system checks all waiting tickets.

The ticket with the greatest effective priority is selected.

If two tickets have the same priority, a consistent tie-breaking rule such as the smaller ticket ID can be used.

The selected ticket is assigned to an available agent.

A ticket requires exactly one unit of simulation time to complete.

As the simulation progresses, waiting tickets automatically gain priority.

🧱 Data Structures
The project uses the following DSA concepts:

Data Structure	Purpose
Max Heap / Priority Queue	Stores and selects the highest-priority waiting ticket
Set	Maintains available agents
Map	Keeps track of agents currently handling tickets
Set	Stores IDs of completed tickets

These structures allow the system to efficiently manage tickets and agents as the simulation changes.

⌨️ Available Commands
Command	Purpose
ADD_TICKET id priority	Creates a new support ticket
ADD_AGENT id	Adds a new support agent
REMOVE_AGENT id	Removes an available agent
TICK	Moves simulation time forward by one unit
QUERY	Displays the current system state

📥 Input Format
Commands are entered one per line. The program continues processing commands until the end of the input.

Example:

ADD_AGENT 1
ADD_AGENT 2
ADD_TICKET 201 6
ADD_TICKET 202 4
TICK
QUERY
TICK
ADD_TICKET 203 9
QUERY
TICK
QUERY

📤 Output Format
Whenever the QUERY command is entered, the system displays:

Current simulation time

Tickets currently waiting

Agents currently processing tickets

Tickets that have been completed

Example:

Time: 1
Waiting: []
Busy Agents: [(1,201),(2,202)]
Resolved: []

Time: 2
Waiting: []
Busy Agents: [(1,203)]
Resolved: [201,202]

Time: 3
Waiting: []
Busy Agents: []
Resolved: [201,202,203]

🔄 Working Process
The simulation operates according to the following process:

When ADD_TICKET is used
A new ticket is created with its ID, base priority, and arrival time. It is then placed into the waiting-ticket structure.

When ADD_AGENT is used
A new agent is registered as AVAILABLE and becomes eligible to receive a ticket.

When TICK is used
The simulation clock increases by one unit.

During this step:

Tickets currently being processed may be completed.

Completed tickets are moved to the resolved collection.

Agents handling completed tickets become available.

Waiting time of pending tickets increases.

Available agents are assigned tickets according to priority.

When REMOVE_AGENT is used
An agent can be removed only if the agent is currently available. Busy agents cannot be removed until their current work is finished.

When QUERY is used
The current state of the complete support system is displayed.

⏱ Complexity Analysis
Let:

N = number of tickets

M = number of agents

The approximate operations are:

Insert ticket: O(log N)

Remove/select highest-priority ticket: O(log N)

Add/remove agent: O(log M)

Assign ticket: O(log N + log M)

Display waiting tickets: O(N log N) if the heap must be temporarily copied and sorted/displayed

Overall, the use of a heap makes priority-based ticket selection efficient.

🚀 Compilation and Execution
Compile
g++ main.cpp -o ticket_system

Run
./ticket_system

Run using an input file
./ticket_system < input.txt

📚 DSA Concepts Demonstrated
This project demonstrates several important DSA concepts:

Max Heap / Priority Queue

Greedy Scheduling

Simulation

Dynamic Data Management

STL set

STL map

STL vector

Time-based priority adjustment

🎯 Project Objective
The main objective of this project is to demonstrate how heap-based priority scheduling can be combined with time simulation to create a dynamic support-ticket system.

The project provides a practical example of how DSA concepts can be applied to a real-world problem where tasks continuously arrive, priorities change over time, and limited resources such as support agents must be managed efficiently.
