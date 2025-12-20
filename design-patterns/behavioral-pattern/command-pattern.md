🕹️ Command Pattern — Complete Explanation
==========================================

📌 Intent
---------

Encapsulate a **request as an object**, thereby allowing you to **parameterize clients**, **queue or log requests**, and **support undo/redo**.

> Command turns a request into a first-class object.

1\. **Real-World Analogy**
==========================

🎮 **TV Remote Control**

*   Button → Command
    
*   TV → Receiver
    
*   Remote → Invoker
    

Remote doesn’t know _how_ TV works — it just issues commands.

2\. **Enterprise Login Example (Why Command?)**
===============================================

Suppose login actions need:

*   Audit logging
    
*   Retry capability
    
*   Async execution
    
*   Undo / rollback (logout)
    

Instead of calling methods directly, wrap them as **commands**.

3\. **UML Diagram — Command Pattern (Login Example)**
=====================================================

```pgsql
Client
   |
   ▼
┌──────────────┐
│   Invoker    │  (LoginController)
├──────────────┤
│ + execute()  │
└───────▲──────┘
        |
        ▼
┌──────────────────┐
│    Command       │ <<interface>>
├──────────────────┤
│ + execute()      │
│ + undo()         │
└───────▲──────────┘
        |
┌──────────────────────┐
│   LoginCommand       │
├──────────────────────┤
│ - receiver           │
│ + execute()          │
│ + undo()             │
└─────────▲────────────┘
          |
          ▼
┌──────────────────┐
│   LoginService   │  (Receiver)
├──────────────────┤
│ + login()        │
│ + logout()       │
└──────────────────┘
```



4\. **Java Implementation**
===========================

**Command Interface**
---------------------

```java
public interface Command {
    void execute();
    void undo();
}
```


**Receiver**
------------

```java
public class LoginService {

    public void login(String user) {
        System.out.println("User logged in: " + user);
    }

    public void logout(String user) {
        System.out.println("User logged out: " + user);
    }
}
```


**Concrete Command**
--------------------

```java
public class LoginCommand implements Command {

    private final LoginService service;
    private final String user;

    public LoginCommand(LoginService service, String user) {
        this.service = service;
        this.user = user;
    }

    @Override
    public void execute() {
        service.login(user);
    }

    @Override
    public void undo() {
        service.logout(user);
    }
}

```



**Invoker**
-----------

```java
public class LoginController {

    private Command command;

    public void setCommand(Command command) {
        this.command = command;
    }

    public void submit() {
        command.execute();
    }

    public void rollback() {
        command.undo();
    }
}

```


**Client Code**
---------------

```java
public class Main {
    public static void main(String[] args) {

        LoginService service = new LoginService();
        Command loginCommand = new LoginCommand(service, "anshi");

        LoginController controller = new LoginController();
        controller.setCommand(loginCommand);

        controller.submit();
        controller.rollback();
    }
}
```



5\. **Program Output**
======================

```pgsql
User logged in: anshi
User logged out: anshi

```


6\. **Where Command Pattern Is Used in Real Systems**
=====================================================

### ✔ UI Frameworks

*   Button clicks
    
*   Menu actions
    

### ✔ Job Queues

*   Kafka commands
    
*   SQS jobs
    

### ✔ Transaction Systems

*   Undo / rollback
    

### ✔ Microservices

*   CQRS
    
*   Command handling pipelines
    

7\. **Command vs Related Patterns**
===================================

```pgsql
User logged in: anshi
User logged out: anshi
```


8\. **Pros and Cons**
=====================

### ⭐ Pros

*   Decouples invoker and receiver
    
*   Supports undo/redo
    
*   Easy to add new commands
    
*   Enables logging and queuing
    

### ❌ Cons

*   Many small command classes
    
*   Increased complexity
    

9\. **Command vs Strategy (Important Interview Question)**
==========================================================

| Command               | Strategy                |
| --------------------- | ----------------------- |
| Represents an action  | Represents an algorithm |
| Can be queued, logged | Cannot be queued        |
| Has undo/redo         | No undo                 |
| Often stateful        | Usually stateless       |


10\. **Interview One-Liner**
============================

> Command Pattern encapsulates a request as an object, allowing clients to parameterize, queue, log, and undo operations while decoupling the sender from the receiver.
