UML State Diagram
=================

A **UML State Diagram** models the **lifecycle of an object** by showing:

*   The **states** it can be in
    
*   The **events** that trigger transitions
    
*   The **actions** that occur on transitions or within states
    

It answers:

*   **What states can an object have?**
    
*   **How does it move between states?**
    
*   **What events cause those changes?**
    

> Think of it as **how an object behaves over time**.

1️⃣ Purpose of a State Diagram
------------------------------

State diagrams are used to:

*   Model **object lifecycle**
    
*   Represent **event-driven behavior**
    
*   Describe **finite state machines**
    
*   Handle **complex state-dependent logic**
    

2️⃣ Core Elements of a State Diagram
------------------------------------

### 🔹 State

```pgsql
┌─────────────┐
│   State     │
└─────────────┘
```

*   Represents a **condition or situation**
    
*   Object remains in a state until an event occurs
    
*   Named using **nouns/adjectives**
    

### 🔹 Initial State

```pgsql
●
```


*   Filled black circle
    
*   Starting point
    
*   Exactly **one** per diagram
    

### 🔹 Final State

```pgsql
◎
```


*   Bull’s-eye symbol
    
*   Indicates termination of lifecycle
    

### 🔹 Transition

```pgsql
State A ─────▶ State B
```


*   Directed arrow
    
*   Triggered by an **event**
    

Format:

```pgsql
event [guard] / action
```

Example:

```pgsql
submit [valid] / save()
```


### 🔹 Event

*   Something that **happens**
    
*   Causes state change
    
*   Examples:
    
    *   Button click
        
    *   Timeout
        
    *   API call
        

### 🔹 Guard Condition

```pgsql
[event] [condition]
```


*   Boolean expression
    
*   Must be true for transition to occur
    

### 🔹 Action

*   Executed during transition
    
*   Written after /
    

3️⃣ Types of States
-------------------

### 🔹 Simple State

Basic state with no internal structure.

### 🔹 Composite State

```pgsql
┌───────────────────┐
│   Parent State    │
│ ┌──────────────┐ │
│ │ Sub-State A  │ │
│ └──────────────┘ │
└───────────────────┘
```


*   Contains nested states
    
*   Helps manage complexity
    

### 🔹 Sub-State (Nested State)

*   Exists only within a composite state
    

### 🔹 Final State (Inside Composite)

*   Marks completion of composite state
    

4️⃣ Entry, Exit, and Do Actions
-------------------------------

Inside a state:

```pgsql
entry / init()
do / process()
exit / cleanup()
```


| Action | When it runs        |
| ------ | ------------------- |
| entry  | When entering state |
| do     | While in state      |
| exit   | When leaving state  |


5️⃣ Self Transition
-------------------

```pgsql
State ──▶ State
```

*   State remains the same
    
*   Used for retries or refresh logic
    

6️⃣ How to Explain Any State Diagram (Interview Steps)
------------------------------------------------------

### Step 1: Identify the Object

*   What entity’s lifecycle is modeled?
    

### Step 2: Identify States

*   Stable conditions
    

### Step 3: Identify Events

*   What triggers changes?
    

### Step 4: Explain Transitions

*   Event + guard + action
    

### Step 5: Identify Start and End

*   Initial and final states
    

7️⃣ What State Diagrams Are NOT For
-----------------------------------

❌ Process workflows❌ Method call order❌ Class relationships❌ Data modeling

8️⃣ Common Mistakes (Interview Red Flags 🚨)
--------------------------------------------

❌ Using activities instead of states❌ Too many states without grouping❌ Missing guard conditions❌ Modeling system flow instead of object lifecycle

9️⃣ When to Use State Diagrams
------------------------------

✔ Order lifecycle✔ Payment lifecycle✔ Session management✔ Protocol modeling

🔟 Interview One-Liner (Very Useful)
------------------------------------

> A UML State Diagram models the lifecycle of an object by showing its states and the events that cause transitions between them.

11️⃣ Comparison with Other UML Diagrams
---------------------------------------

| Diagram  | Focus            |
| -------- | ---------------- |
| Activity | Workflow         |
| Sequence | Interaction      |
| State    | Object lifecycle |
| Class    | Structure        |


🧠 Bonus Interview Tip
----------------------

If asked:

> “Why not activity diagram?”

Answer:

> Activity diagrams model **process flow**, while state diagrams model **state-dependent behavior of an object**.

<img width="577" height="345" alt="image" src="https://github.com/user-attachments/assets/25e5d448-98c5-41ae-9a63-45c1003db05b" />
