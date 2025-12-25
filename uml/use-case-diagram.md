UML Use Case Diagram — General Explanation
==========================================

A **Use Case Diagram** represents the **functional behavior of a system from the user’s perspective**.

It answers:

*   **Who** can use the system?
    
*   **What** can they do with it?
    

It does **NOT** show:

*   Internal logic
    
*   Classes or code
    
*   Execution order
    

1️⃣ Core Purpose of Use Case Diagram
------------------------------------

Use Case Diagrams are used to:

*   Capture **requirements**
    
*   Define **system scope**
    
*   Communicate with **non-technical stakeholders**
    

> Think of it as a contract of _what the system provides_, not _how it does it_.

2️⃣ Main Elements of a Use Case Diagram
---------------------------------------

### 🔹 Actor

Represents a **role** that interacts with the system.

```pgsql
   👤 Actor
```


✔ Can be:

*   Human user
    
*   External system
    
*   Hardware device
    

❌ NOT a specific person❌ NOT an internal class

Example:

*   User
    
*   Admin
    
*   Payment Gateway
    

### 🔹 Use Case

Represents a **functionality** offered by the system.

```pgsql
( Perform Action )
```


✔ Describes an **action**✔ Named using **verb + noun**

Examples:

*   Login
    
*   Place Order
    
*   Generate Report
    

### 🔹 System Boundary

Defines **what is inside the system** and what is outside.

```pgsql
┌──────────────────────────┐
│        System            │
│  (Use Case A)            │
│  (Use Case B)            │
└──────────────────────────┘
```


Anything inside → system responsibilityAnything outside → actor responsibility

3️⃣ Relationships in Use Case Diagrams
--------------------------------------

### 🔹 Association (Actor ↔ Use Case)

```pgsql
Actor ───── (Use Case)
```


*   Actor participates in use case
    
*   No direction, no order
    

### 🔹 «include»

Used when a use case **always** includes another use case.

```pgsql
( A ) ──«include»──> ( B )
```


✔ Mandatory behavior✔ Reusable logic

Example meaning:

> Every time A runs, B must run

### 🔹 «extend»

Used when a use case **optionally extends** another.

```pgsql
( A ) ──«extend»──> ( B )
```


✔ Optional behavior✔ Conditional

Example meaning:

> B runs normally; A runs only if condition is met

### 🔹 Generalization (Inheritance)

```pgsql
Special Actor ─────▷ General Actor
```


or

```pgsql
( Specialized Use Case )
          ▽
( General Use Case )
```


✔ Inheritance of behavior✔ Used for specialization

4️⃣ «include» vs «extend» (Very Important)
------------------------------------------

| Feature     | «include»       | «extend»         |
| ----------- | --------------- | ---------------- |
| Mandatory   | ✅ Yes           | ❌ No             |
| Reusability | High            | Low              |
| Direction   | Base → Included | Extension → Base |
| Trigger     | Always          | Conditional      |



👉 Interview trick:

> If behavior is _always required_, use **include**.

5️⃣ How to Explain Any Use Case Diagram (Interview Flow)
--------------------------------------------------------

### Step 1: Identify Actors

*   Who interacts with the system?
    

### Step 2: Identify Use Cases

*   What functionality is provided?
    

### Step 3: Explain Relationships

*   Associations
    
*   Includes
    
*   Extends
    

### Step 4: Define System Boundary

*   What’s inside vs outside?
    

6️⃣ Common Mistakes (Interview Red Flags 🚨)
--------------------------------------------

❌ Using classes as actors❌ Showing internal logic❌ Overusing «extend»❌ Missing system boundary

7️⃣ What Use Case Diagrams Are NOT For
--------------------------------------

❌ Algorithm design❌ Object relationships❌ Code structure❌ Performance analysis

8️⃣ When to Use Use Case Diagrams
---------------------------------

✔ Requirement gathering✔ Stakeholder communication✔ Early design phase✔ Scope clarification

9️⃣ Interview One-Liner (Highly Useful)
---------------------------------------

> A UML Use Case Diagram shows the system’s functionality from the user’s perspective by modeling actors, use cases, and their interactions.

🔟 Bonus: Difference from Other UML Diagrams
--------------------------------------------

| Diagram  | Focus               |
| -------- | ------------------- |
| Use Case | What system does    |
| Class    | System structure    |
| Sequence | Runtime interaction |
| Activity | Workflow            |



<img width="802" height="395" alt="image" src="https://github.com/user-attachments/assets/577dc4c7-4926-4ddf-9109-435e9df97049" />
