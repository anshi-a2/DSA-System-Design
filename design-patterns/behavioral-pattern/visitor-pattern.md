🧳 Visitor Pattern — Complete Explanation
=========================================

📌 Intent
---------

Represent an **operation to be performed on elements of an object structure**, without changing the classes of the elements.

> Visitor lets you **add new operations** without modifying existing object classes.

1️⃣ Real-World Analogy
======================

🧑‍⚕️ **Doctor visiting patients**

*   Same doctor
    
*   Different patients
    
*   Doctor performs different actions per patient
    

Patients don’t change — **visitor does**.

2️⃣ Enterprise Login Example (Why Visitor?)
===========================================

After login, the system must perform **multiple operations** on different user types:

*   Admin user → audit + permissions check
    
*   Regular user → audit only
    
*   Guest user → limited tracking
    

Instead of adding logic to each user class, use **Visitor**.

3️⃣ UML Diagram — Visitor Pattern (User Example)
================================================

```pgsql
                    Client
                       |
                       ▼
                ┌──────────────────┐
                │     Visitor      │ <<interface>>
                ├──────────────────┤
                │ + visit(Admin)   │
                │ + visit(User)    │
                │ + visit(Guest)   │
                └────────▲─────────┘
                         |
              ┌────────────────────┐
              │   LoginVisitor     │
              └────────────────────┘

        ┌────────────────────┐
        │     UserElement    │ <<interface>>
        ├────────────────────┤
        │ + accept(Visitor) │
        └────────▲──────────┘
                 |
    ┌────────────┼────────────┐
    |             |            |
┌────────────┐ ┌────────────┐ ┌────────────┐
│ AdminUser  │ │ NormalUser │ │ GuestUser  │
└────────────┘ └────────────┘ └────────────┘
```


4️⃣ Java Implementation
=======================

**Visitor Interface**
---------------------

```java
public interface UserVisitor {
    void visit(AdminUser admin);
    void visit(NormalUser user);
    void visit(GuestUser guest);
}

```



**Element Interface**
---------------------

```java
public interface User {
    void accept(UserVisitor visitor);
}
```


**Concrete Elements**
---------------------

```java
public class AdminUser implements User {
    @Override
    public void accept(UserVisitor visitor) {
        visitor.visit(this);
    }
}

public class NormalUser implements User {
    @Override
    public void accept(UserVisitor visitor) {
        visitor.visit(this);
    }
}

public class GuestUser implements User {
    @Override
    public void accept(UserVisitor visitor) {
        visitor.visit(this);
    }
}
```


**Concrete Visitor**
--------------------

```java
public class LoginAuditVisitor implements UserVisitor {

    @Override
    public void visit(AdminUser admin) {
        System.out.println("Admin login audited with full permissions");
    }

    @Override
    public void visit(NormalUser user) {
        System.out.println("User login audited");
    }

    @Override
    public void visit(GuestUser guest) {
        System.out.println("Guest login tracked with limitations");
    }
}
```


**Client Code**
---------------

```java
public class Main {
    public static void main(String[] args) {

        List<User> users = List.of(
                new AdminUser(),
                new NormalUser(),
                new GuestUser()
        );

        UserVisitor visitor = new LoginAuditVisitor();

        for (User user : users) {
            user.accept(visitor);
        }
    }
}
```


5️⃣ Program Output
==================

```pgsql
Admin login audited with full permissions
User login audited
Guest login tracked with limitations
```


6️⃣ Where Visitor Pattern Is Used in Real Systems
=================================================

### ✔ Compilers

*   AST traversal
    
*   Syntax checking
    

### ✔ Reporting Engines

*   Generate PDF / HTML / CSV
    

### ✔ Analytics Pipelines

*   Run operations on diverse objects
    

### ✔ Policy Evaluation

*   Apply different rules per object type
    

7️⃣ Visitor vs Related Patterns
===============================

| Pattern       | Difference          |
| ------------- | ------------------- |
| **Visitor**   | Add new operations  |
| **Strategy**  | Switch algorithms   |
| **Command**   | Encapsulate actions |
| **Composite** | Tree structures     |



8️⃣ Pros and Cons
=================

### ⭐ Pros

*   Add new operations easily
    
*   Keeps element classes clean
    
*   Centralizes logic
    

### ❌ Cons

*   Hard to add new element types
    
*   Breaks Open/Closed for elements
    
*   Tight coupling with element structure
    

9️⃣ Interview One-Liner
=======================

> Visitor Pattern allows adding new operations to an object structure without modifying the elements, by moving the operation logic into visitor classes.

🔟 When NOT to Use Visitor
==========================

❌ When element types change frequently❌ When object structure is unstable❌ When simple polymorphism suffices

🧠 Interview Tip (High-Value Insight)
=====================================

Visitor is **Open for operations** but **Closed for element changes**.

If elements change often → **avoid Visitor**.
