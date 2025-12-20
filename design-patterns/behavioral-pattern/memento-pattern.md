🕰️ Memento Pattern — Complete Explanation
==========================================

📌 Intent
---------

Without violating encapsulation, **capture and externalize an object’s internal state** so that it can be **restored later**.

> Memento enables **undo / rollback**.

1️⃣ Real-World Analogy
======================

💾 **Save Game**

*   Save current state
    
*   Play further
    
*   Reload previous save
    

Game doesn’t expose internals — state is restored safely.

2️⃣ Enterprise Login Example (Why Memento?)
===========================================

Login/session system needs:

*   Rollback login attempts
    
*   Restore session on failure
    
*   Undo state changes (e.g., failed MFA)
    

Instead of exposing internals, store snapshots via **Memento**.

3️⃣ UML Diagram — Memento Pattern (Login Example)
=================================================

```pgsql
              Client
                |
                ▼
        ┌──────────────────┐
        │   Caretaker      │
        │ (SessionManager)│
        └────────▲─────────┘
                 |
        ┌────────┴────────┐
        |                 |
┌──────────────────┐  ┌──────────────────┐
│    Originator    │  │    Memento       │
│  (LoginSession) │  │ (SessionState)   │
├──────────────────┤  ├──────────────────┤
│ + save()         │  │ - state          │
│ + restore()      │  └──────────────────┘
└──────────────────┘

```

4️⃣ Java Implementation
=======================

**Memento (State Snapshot)**
----------------------------

```java
public class SessionMemento {
    private final String state;

    public SessionMemento(String state) {
        this.state = state;
    }

    String getState() {
        return state;
    }
}
```


**Originator**
--------------

```java
public class LoginSession {

    private String state;

    public void setState(String state) {
        System.out.println("Session state set to: " + state);
        this.state = state;
    }

    public SessionMemento save() {
        return new SessionMemento(state);
    }

    public void restore(SessionMemento memento) {
        this.state = memento.getState();
        System.out.println("Session restored to: " + state);
    }
}
```


**Caretaker**
-------------

```java
import java.util.Stack;

public class SessionManager {

    private final Stack<SessionMemento> history = new Stack<>();

    public void save(LoginSession session) {
        history.push(session.save());
    }

    public void undo(LoginSession session) {
        if (!history.isEmpty()) {
            session.restore(history.pop());
        }
    }
}
```


**Client Code**
---------------

```java
public class Main {
    public static void main(String[] args) {

        LoginSession session = new LoginSession();
        SessionManager manager = new SessionManager();

        session.setState("LOGGED_OUT");
        manager.save(session);

        session.setState("LOGGED_IN");
        manager.save(session);

        session.setState("LOCKED");

        manager.undo(session);
        manager.undo(session);
    }
}
```


5️⃣ Program Output
==================

```pgsql
Session state set to: LOGGED_OUT
Session state set to: LOGGED_IN
Session state set to: LOCKED
Session restored to: LOGGED_IN
Session restored to: LOGGED_OUT
```


6️⃣ Where Memento Pattern Is Used in Real Systems
=================================================

### ✔ Editors

*   Undo / Redo
    

### ✔ Transaction Systems

*   Rollback
    

### ✔ Workflow Engines

*   Restore previous state
    

### ✔ Games

*   Save / Load
    

7️⃣ Memento vs Related Patterns
===============================

| Pattern       | Difference         |
| ------------- | ------------------ |
| **Memento**   | Restore state      |
| **Command**   | Execute actions    |
| **State**     | Behavior per state |
| **Prototype** | Clone objects      |



8️⃣ Pros and Cons
=================

### ⭐ Pros

*   Preserves encapsulation
    
*   Supports undo/redo
    
*   Clean rollback logic
    

### ❌ Cons

*   Memory heavy
    
*   Caretaker complexity
    
*   Performance overhead
    

9️⃣ Interview One-Liner
=======================

> Memento Pattern captures and restores an object’s state without exposing its internals, enabling undo and rollback functionality.

🔟 Key Interview Insight
========================

*   **Command** handles _what action to undo_
    
*   **Memento** handles _what state to restore_
    

They are often used **together**.
