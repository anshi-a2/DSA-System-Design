UML Activity Diagram
====================

A **UML Activity Diagram** models the **workflow of actions** in a system.

It answers:

*   **What steps happen?**
    
*   **In what order?**
    
*   **Where are decisions, loops, and parallel flows?**
    

It focuses on **control flow**, not objects or messages.

> Think of it as a **flowchart with UML semantics**.

1️⃣ Purpose of an Activity Diagram
----------------------------------

Activity diagrams are used to:

*   Visualize **business processes**
    
*   Describe **use case flows**
    
*   Model **algorithms and workflows**
    
*   Show **parallel execution**
    

2️⃣ Core Elements of an Activity Diagram
----------------------------------------

### 🔹 Initial Node (Start)

```pgsql
●
```


*   Solid filled circle
    
*   Exactly **one** per activity
    
*   Entry point of the workflow
    

### 🔹 Action / Activity

```pgsql
┌─────────────┐
│  Do Action  │
└─────────────┘
```


*   Represents a **step** in the workflow
    
*   Named with **verb + noun**
    
*   Atomic unit of work
    

### 🔹 Control Flow

```pgsql
──────▶
```

*   Shows transition between actions
    
*   Direction matters
    

### 🔹 Decision Node (Branch)

```pgsql
      ◇
```


*   Diamond shape
    
*   Represents **conditional branching**
    

Example:

```pgsql
      ◇
   [yes]  [no]
```


### 🔹 Merge Node

```pgsql
      ◇
```


*   Same symbol as decision
    
*   Used to **merge alternate paths**
    
*   No condition labels
    

### 🔹 Fork (Parallel Start)

```pgsql
━━━━━━━
```


*   Thick horizontal or vertical bar
    
*   Splits flow into **parallel activities**
    

### 🔹 Join (Parallel End)

```pgsql
━━━━━━━
```


*   Same symbol as fork
    
*   Synchronizes parallel flows
    

### 🔹 Final Node (End)

```pgsql
◎
```


*   Bull’s eye symbol
    
*   Terminates the activity
    

3️⃣ Decision vs Merge (Important)
---------------------------------

| Node     | Purpose                       |
| -------- | ----------------------------- |
| Decision | Choose **one** path           |
| Merge    | Combine **alternative** paths |



👉 They look the same but have **different semantics**.

4️⃣ Swimlanes (Responsibility Partitioning)
-------------------------------------------

Swimlanes show **who is responsible** for which action.

```pgsql
┌──────────┬──────────┐
│ User     │ System   │
├──────────┼──────────┤
│ Action A │ Action B │
└──────────┴──────────┘
```


✔ Improves clarity✔ Common in business workflows

5️⃣ Tokens Concept (Execution Model)
------------------------------------

*   A token starts at the **initial node**
    
*   Moves along control flows
    
*   Fork creates **multiple tokens**
    
*   Join waits for **all tokens**
    

Interview-friendly explanation:

> Activity diagrams are token-driven.

6️⃣ How to Explain Any Activity Diagram (Interview Steps)
---------------------------------------------------------

### Step 1: Identify Start and End

*   Initial node
    
*   Final node
    

### Step 2: Follow the Flow

*   Top to bottom or left to right
    

### Step 3: Identify Decisions

*   Conditions
    
*   Alternate paths
    

### Step 4: Identify Parallelism

*   Forks and joins
    

### Step 5: Explain Responsibility

*   Swimlanes
    

7️⃣ What Activity Diagrams Are NOT For
--------------------------------------

❌ Class structure❌ Message sequencing❌ Object lifecycles❌ System architecture

8️⃣ Common Mistakes (Interview Red Flags 🚨)
--------------------------------------------

❌ Using decision node instead of fork❌ Missing join after fork❌ Too many actions (over-detailed)❌ No clear start or end

9️⃣ When to Use Activity Diagrams
---------------------------------

✔ Business process modeling✔ Workflow engines✔ Use case detailing✔ Algorithm explanation

🔟 Interview One-Liner (Very Useful)
------------------------------------

> A UML Activity Diagram represents the flow of control in a system, showing actions, decisions, and parallel execution.

11️⃣ Comparison with Other UML Diagrams
---------------------------------------

```pgsql
| Diagram  | Focus                   |
| -------- | ----------------------- |
| Use Case | What system does        |
| Sequence | Interaction over time   |
| Activity | Workflow / control flow |
| State    | Object lifecycle        |
```


🧠 Bonus Interview Tip
----------------------

If asked:

> “When would you prefer activity over sequence?”

Answer:

> When the focus is on **workflow and decision logic**, not object interaction.

Diagram without swimlane :
---------------------------

<img width="580" height="699" alt="image" src="https://github.com/user-attachments/assets/a1c9de60-20ab-42bc-9c2a-b6b6d8bc6926" />


Diagram with swimlane :
-----------------------


<img width="577" height="666" alt="image" src="https://github.com/user-attachments/assets/4b60f207-9feb-413c-a1a4-c3e085029745" />

