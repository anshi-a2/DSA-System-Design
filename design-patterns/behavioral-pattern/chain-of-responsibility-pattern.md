⛓️ Chain of Responsibility Pattern — Complete Explanation
=========================================================

📌 Intent
---------

Avoid coupling the sender of a request to its receiver by giving **multiple objects a chance to handle the request**, passing it along a **chain** until one handles it.

> A request travels through a chain of handlers.

1️⃣ Real-World Analogy
----------------------

📄 **Office Approval Process**

*   Manager → Director → VP
    
*   If Manager can’t approve → forwards
    

Each approver decides:

*   Handle
    
*   Or pass to next
    

2️⃣ Enterprise Login Example (Why Chain?)
-----------------------------------------

Before login succeeds, several checks must occur:

1.  Rate limit check
    
2.  Credential validation
    
3.  Account status check
    
4.  MFA verification
    

Each check:

*   Either **fails**
    
*   Or **passes to next**
    

Perfect use case for **Chain of Responsibility**.

3️⃣ UML Diagram — Chain of Responsibility (Login Example)
---------------------------------------------------------

```pgsql
              Client
                |
                ▼
        ┌──────────────────┐
        │   Handler        │ <<abstract>>
        ├──────────────────┤
        │ + setNext()      │
        │ + handle()       │
        └────────▲─────────┘
                 |
   ┌─────────────┼─────────────┐
   |             |             |
┌───────────┐ ┌───────────┐ ┌───────────┐
│ RateLimit │ │ Credential│ │ MFA       │
│ Handler   │ │ Handler   │ │ Handler   │
└───────────┘ └───────────┘ └───────────┘
```


4️⃣ Java Implementation
-----------------------

### **Handler (Abstract)**

```java
public abstract class LoginHandler {

    protected LoginHandler next;

    public LoginHandler setNext(LoginHandler next) {
        this.next = next;
        return next;
    }

    public abstract boolean handle(String user);
}
```


### **Concrete Handlers**

#### Rate Limit

```java
public class RateLimitHandler extends LoginHandler {

    @Override
    public boolean handle(String user) {
        System.out.println("Rate limit check");
        return next == null || next.handle(user);
    }
}
```


#### Credential Validation

```java
public class CredentialHandler extends LoginHandler {

    @Override
    public boolean handle(String user) {
        System.out.println("Credential validation");
        return next == null || next.handle(user);
    }
}
```


#### MFA

```java
public class MfaHandler extends LoginHandler {

    @Override
    public boolean handle(String user) {
        System.out.println("MFA verification");
        return true; // final handler
    }
}
```


### **Client Code**

```java
public class Main {
    public static void main(String[] args) {

        LoginHandler chain =
            new RateLimitHandler()
                .setNext(new CredentialHandler())
                .setNext(new MfaHandler());

        boolean success = chain.handle("anshi");
        System.out.println("Login success: " + success);
    }
}
```


5️⃣ Program Output
------------------

```pgsql
Rate limit check
Credential validation
MFA verification
Login success: true
```


6️⃣ Where Chain of Responsibility Is Used in Real Systems
---------------------------------------------------------

### ✔ Web Filters

*   Servlet filters
    
*   Spring Security filters
    

### ✔ Middleware Pipelines

*   Authentication
    
*   Validation
    
*   Logging
    

### ✔ Event Handling

*   UI event bubbling
    

### ✔ Workflow Engines

*   Approval chains
    

7️⃣ Chain vs Related Patterns
-----------------------------

| Pattern                     | Difference          |
| --------------------------- | ------------------- |
| **Chain of Responsibility** | Sequential handling |
| **Decorator**               | Adds behavior       |
| **Observer**                | Broadcast           |
| **Command**                 | Encapsulated action |



8️⃣ Pros and Cons
-----------------

### ⭐ Pros

*   Loose coupling
    
*   Easy to add/remove handlers
    
*   Clean pipeline logic
    
*   Follows Open/Closed principle
    

### ❌ Cons

*   Hard to debug
    
*   Request may go unhandled
    
*   Chain order matters
    

9️⃣ Interview One-Liner
-----------------------

> Chain of Responsibility Pattern lets multiple handlers process a request in sequence, decoupling the sender from the receiver.

🔟 Enterprise Interview Tip (🔥 Important)
------------------------------------------

*   **Spring Security Filter Chain** is a **classic Chain of Responsibility**
    
*   **Servlet Filters** too
    

Mentioning this gives **extra points**.
