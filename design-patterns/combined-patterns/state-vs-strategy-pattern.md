🔁 State Pattern vs Strategy Pattern
------------------------------------

### One-Line Difference (Memorize This)

> **Strategy**: Client decides _which behavior to use_ , 
> **State**: Object decides _how to behave based on its state_

1️⃣ Intent Comparison
---------------------

| Aspect               | Strategy Pattern                       | State Pattern                       |
| -------------------- | -------------------------------------- | ----------------------------------- |
| Purpose              | Encapsulate interchangeable algorithms | Encapsulate state-specific behavior |
| Who selects behavior | Client / Context setter                | Object itself                       |
| Trigger              | External choice                        | Internal state change               |
| State transitions    | ❌ No                                   | ✅ Yes                               |
| Typical use          | Algorithms                             | State machines                      |
| Behavior change      | Manual                                 | Automatic                           |


2️⃣ Login Example (Best Way to Explain in Interview)
----------------------------------------------------

### 🧠 Strategy Example (Client Chooses)

Login methods:

*   Password
    
*   OTP
    
*   OAuth
    

```java
context.setStrategy(new OtpStrategy());
context.login();
```


✔ Same context✔ Behavior chosen by **client**❌ No state transitions

### 🔄 State Example (Object Chooses)

User session states:

*   LoggedOut
    
*   LoggedIn
    
*   Locked
    

```java
context.login();   // behaves differently based on state
```


✔ Same call✔ Different behavior✔ **State transitions inside the object**

3️⃣ UML Difference (Conceptual)
-------------------------------

### Strategy

```pgsql
Client → Context → Strategy
```


### State

```pgsql
Context → CurrentState → NextState
```


👉 Strategy is **pluggable behavior**👉 State is **self-transitioning behavior**

4️⃣ Real-World Analogy (Easy to Remember)
-----------------------------------------

### Strategy 🧠

Choosing how to travel:

*   Car
    
*   Bike
    
*   Train
    

You decide **before starting**.

### State 🔄

Traffic light:

*   Red → Stop
    
*   Green → Go
    

Light decides behavior **automatically**.

5️⃣ Code Smell → Which Pattern?
-------------------------------

### If you see this:

```java
if (loginType == OTP) { ... }
else if (loginType == PASSWORD) { ... }
```

👉 **Strategy**

### If you see this:

```java
if (state == LOGGED_IN) { ... }
else if (state == LOCKED) { ... }
```


👉 **State**

6️⃣ Can Strategy Become State?
------------------------------

✅ **Yes**, very often.

### Example:

*   OTP attempts exceed limit
    
*   System moves to **LockedState**
    

👉 Strategy handles _how to login_👉 State handles _whether login is allowed_

Enterprise systems often use **both together**.

7️⃣ Pros & Cons Comparison
--------------------------

### Strategy

**Pros**

*   Runtime flexibility
    
*   Eliminates if-else
    
*   Easy to add new algorithms
    

**Cons**

*   Client must choose correctly
    
*   Many small classes
    

### State

**Pros**

*   Clean state transitions
    
*   Eliminates switch on state
    
*   Models real workflows
    

**Cons**

*   More classes
    
*   Slightly harder to trace
    

8️⃣ Interview Decision Rule (🔥 Very Important)
-----------------------------------------------

Ask yourself:

> **“Who decides the behavior?”**

*   **Client decides → Strategy**
    
*   **Object decides → State**
    

9️⃣ 30-Second Interview Answer (Perfect)
----------------------------------------

> Strategy Pattern encapsulates interchangeable algorithms and lets the client choose the behavior at runtime. State Pattern encapsulates state-specific behavior and allows an object to change its behavior automatically when its internal state changes. Strategy focuses on behavior selection, while State focuses on behavior evolution.

10️⃣ Common Interview Mistakes ❌
--------------------------------

❌ “Strategy and State are same”✔ They are structurally similar but **conceptually different**

❌ “State is Strategy with transitions”✔ State models **state machines**

❌ “Use Strategy for state handling”✔ That leads to bloated conditionals
