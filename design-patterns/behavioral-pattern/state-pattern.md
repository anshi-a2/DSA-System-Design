🔄 State Pattern — Complete Explanation
=======================================

📌 Intent
---------

Allow an object to **alter its behavior when its internal state changes**.The object will appear to **change its class at runtime**.

> State encapsulates **state-specific behavior** and makes state transitions explicit.

1\. **Real-World Analogy**
==========================

🚦 **Traffic Light**

*   Red → Stop
    
*   Yellow → Slow
    
*   Green → Go
    

Same traffic light object, different behavior depending on **current state**.

2\. **Enterprise Login Example (Why State?)**
=============================================

A user session behaves differently depending on state:

*   **LoggedOut**
    
*   **LoggedIn**
    
*   **Locked**
    
*   **Expired**
    

Instead of massive if-else:

```java
if (state == LOGGED_IN) { ... }
else if (state == LOCKED) { ... }
```


Use **State Pattern**.

3\. **UML Diagram — State Pattern (Login Example)**
===================================================

```pgsql
                    Context
              ┌──────────────────┐
              │   LoginContext   │
              ├──────────────────┤
              │ - state          │
              │ + login()        │
              │ + logout()       │
              └────────▲─────────┘
                       |
        ┌──────────────┼──────────────┐
        |              |              |
┌────────────────┐ ┌────────────────┐ ┌────────────────┐
│ LoggedOutState │ │ LoggedInState  │ │ LockedState    │
├────────────────┤ ├────────────────┤ ├────────────────┤
│ + login()      │ │ + login()      │ │ + login()      │
│ + logout()     │ │ + logout()     │ │ + logout()     │
└────────────────┘ └────────────────┘ └────────────────┘

```


4\. **Java Implementation**
===========================

**State Interface**
-------------------

```java
public interface LoginState {
    void login(LoginContext context);
    void logout(LoginContext context);
}
```


**Concrete States**
-------------------

### LoggedOutState

```java
public class LoggedOutState implements LoginState {

    @Override
    public void login(LoginContext context) {
        System.out.println("Login successful");
        context.setState(new LoggedInState());
    }

    @Override
    public void logout(LoginContext context) {
        System.out.println("Already logged out");
    }
}
```


### LoggedInState

```java
public class LoggedInState implements LoginState {

    @Override
    public void login(LoginContext context) {
        System.out.println("Already logged in");
    }

    @Override
    public void logout(LoginContext context) {
        System.out.println("Logged out successfully");
        context.setState(new LoggedOutState());
    }
}
```


### LockedState

```java
public class LockedState implements LoginState {

    @Override
    public void login(LoginContext context) {
        System.out.println("Account locked. Contact support.");
    }

    @Override
    public void logout(LoginContext context) {
        System.out.println("Cannot logout. Account is locked.");
    }
}
```


**Context**
-----------

```java
public class LoginContext {

    private LoginState state;

    public LoginContext() {
        this.state = new LoggedOutState();
    }

    public void setState(LoginState state) {
        this.state = state;
    }

    public void login() {
        state.login(this);
    }

    public void logout() {
        state.logout(this);
    }
}
```


**Client Code**
---------------

```java
public class Main {
    public static void main(String[] args) {

        LoginContext context = new LoginContext();

        context.login();
        context.login();
        context.logout();
        context.logout();
    }
}
```


5\. **Program Output**
======================

```pgsql
Login successful
Already logged in
Logged out successfully
Already logged out
```


6\. **Where State Pattern Is Used in Real Systems**
===================================================

### ✔ Authentication / Authorization

*   Login sessions
    
*   MFA flows
    

### ✔ Order Processing

*   CREATED → PAID → SHIPPED → DELIVERED
    

### ✔ Workflow Engines

*   Approval states
    

### ✔ Network Protocols

*   CONNECTED / DISCONNECTED
    

7\. **State vs Strategy (VERY Important Interview Topic)**
==========================================================

| Aspect                 | State                 | Strategy        |
| ---------------------- | --------------------- | --------------- |
| Who changes behavior   | Object itself         | Client          |
| Trigger                | Internal state change | External choice |
| State transition       | Yes                   | No              |
| Object aware of states | Yes                   | No              |

👉 **If behavior changes automatically → State**👉 **If client chooses behavior → Strategy**

8\. **Pros and Cons**
=====================

### ⭐ Pros

*   Eliminates large conditional blocks
    
*   Makes state transitions explicit
    
*   Open/Closed principle
    
*   Cleaner, maintainable code
    

### ❌ Cons

*   Many state classes
    
*   Slight complexity increase
    

9\. **Interview One-Liner**
===========================

> State Pattern allows an object to change its behavior when its internal state changes, encapsulating state-specific logic into separate classes.

10\. **Enterprise Tip (How to Spot State Pattern)**
===================================================

If you see:

*   Enum-based state checks
    
*   Huge switch(state)
    
*   Repeated conditionals
    

👉 State Pattern is the fix.
