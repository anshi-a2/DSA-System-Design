🎯 Strategy Pattern — Complete Explanation
==========================================

📌 Intent
---------

Define a **family of algorithms**, encapsulate each one, and make them **interchangeable at runtime**.

> Strategy lets the algorithm vary **independently** from the client that uses it.

1\. **Real-World Analogy**
==========================

💳 **Payment Method**

*   Credit Card
    
*   UPI
    
*   Net Banking
    

Checkout page doesn’t change — only the **strategy** does.

2\. **Enterprise Login Example (Why Strategy?)**
================================================

Different login methods:

*   Username + Password
    
*   OTP-based login
    
*   OAuth (Google, GitHub)
    

Instead of if-else or switch, use **Strategy Pattern**.

3\. **UML Diagram — Strategy Pattern (Login Example)**
======================================================

```pgsql
                    Client
                       |
                       ▼
                ┌──────────────────┐
                │ LoginContext     │
                ├──────────────────┤
                │ - strategy       │
                │ + login()        │
                └────────▲─────────┘
                         |
               ┌─────────┴─────────┐
               |                   |
     ┌─────────────────┐  ┌─────────────────┐
     │ LoginStrategy   │  │ LoginStrategy   │ <<interface>>
     ├─────────────────┤  ├─────────────────┤
     │ + authenticate()│  │ + authenticate()│
     └────────▲────────┘  └────────▲────────┘
              |                       |
 ┌────────────────────┐   ┌────────────────────┐
 │ PasswordStrategy   │   │ OtpStrategy         │
 └────────────────────┘   └────────────────────┘


```



4\. **Java Implementation**
===========================

**Strategy Interface**
----------------------

```java
public interface LoginStrategy {
    boolean authenticate(String username);
}
```


**Concrete Strategies**
-----------------------

```java
public class PasswordLoginStrategy implements LoginStrategy {
    @Override
    public boolean authenticate(String username) {
        System.out.println("Authenticating using password for " + username);
        return true;
    }
}

public class OtpLoginStrategy implements LoginStrategy {
    @Override
    public boolean authenticate(String username) {
        System.out.println("Authenticating using OTP for " + username);
        return true;
    }
}
```


**Context**
-----------

```java
public class LoginContext {

    private LoginStrategy strategy;

    public LoginContext(LoginStrategy strategy) {
        this.strategy = strategy;
    }

    public void setStrategy(LoginStrategy strategy) {
        this.strategy = strategy;
    }

    public boolean login(String username) {
        return strategy.authenticate(username);
    }
}
```


**Client Code**
---------------

```java
public class Main {
    public static void main(String[] args) {

        LoginContext context = new LoginContext(new PasswordLoginStrategy());
        context.login("anshi");

        context.setStrategy(new OtpLoginStrategy());
        context.login("anshi");
    }
}
```


5\. **Program Output**
======================

```pgsql
Authenticating using password for anshi
Authenticating using OTP for anshi

```


6\. **Where Strategy Pattern Is Used in Real Systems**
======================================================

### ✔ Authentication & Authorization

*   Multiple auth providers
    
*   Password vs OAuth vs Biometric
    

### ✔ Payment Systems

*   Card, Wallet, UPI
    

### ✔ Sorting Algorithms

*   QuickSort vs MergeSort
    

### ✔ Compression

*   ZIP vs RAR
    

### ✔ Routing Logic

*   Load balancing strategies
    

7\. **Strategy vs Related Patterns**
====================================

| Pattern       | Difference                     |
| ------------- | ------------------------------ |
| **Strategy**  | Switch algorithm               |
| **State**     | Switch behavior based on state |
| **Factory**   | Create objects                 |
| **Decorator** | Add responsibilities           |


8\. **Pros and Cons**
=====================

### ⭐ Pros

*   Eliminates if-else
    
*   Open/Closed principle
    
*   Runtime flexibility
    
*   Clean separation of concerns
    

### ❌ Cons

*   Many small classes
    
*   Client must know which strategy to use
    
*   Slight overhead
    

9\. **Interview One-Liner**
===========================

> Strategy Pattern encapsulates interchangeable algorithms behind a common interface, allowing behavior to be selected at runtime without modifying the client.

10\. **Strategy in Spring (Interview Bonus)**
=============================================

```java
@Component("otp")
class OtpStrategy implements LoginStrategy {}

@Autowired
Map<String, LoginStrategy> strategies;
```



Spring uses Strategy heavily via dependency injection.

🔑 Strategy vs Observer (Common Interview Trap)
===============================================

*   **Strategy** → Client chooses behavior
    
*   **Observer** → Behavior reacts automatically
