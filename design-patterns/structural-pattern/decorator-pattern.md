🎀 Decorator Pattern — Full Explanation
=======================================

📌 Intent
---------

Add **new behavior** to an object **dynamically**, _without modifying its class_ and _without affecting other objects_ of the same class.

1\. **Real-World Analogy (Instant Understanding)**
==================================================

Think of a **coffee**:

*   Base: Black Coffee
    
*   Add-ons: Milk, Sugar, Cream, Caramel
    

You don’t modify the coffee machine class.Instead, you **wrap** the coffee with decorators.

Each decorator adds behaviour → cost, ingredients, taste.

Same idea in programming.

2\. **Login Example (Decorator Pattern)**
=========================================

Let’s decorate a LoginService with:

*   LoggingDecorator
    
*   RateLimitingDecorator
    
*   MetricsDecorator
    
*   MFARequiredDecorator
    

You can apply them independently or stack them:

```less
MFA( Logging( RateLimit( BasicLoginService ) ) )
```


Each decorator **wraps** the original service and adds features, without changing the base logic.

3\. **UML Diagram — Decorator Pattern (Login Example)**
=======================================================

```pgsql
                    Component
         ┌────────────────────────────────┐
         │        LoginService            │
         ├────────────────────────────────┤
         │ + login(user, pass): boolean   │
         └────────────────────────────────┘
                        ▲
                        │
                Concrete Component
         ┌────────────────────────────────┐
         │     BasicLoginService          │
         ├────────────────────────────────┤
         │ + login() override             │
         └────────────────────────────────┘
                        ▲
                 Decorator (abstract)
         ┌──────────────────────────────────────────┐
         │         LoginDecorator                   │
         ├──────────────────────────────────────────┤
         │ - wrappee: LoginService                  │
         │ + login() (delegates to wrappee)         │
         └──────────────────────────────────────────┘
                        ▲
     ┌──────────────────┼────────────────────────────┐
     │                  │                            │
┌───────────────┐ ┌───────────────┐           ┌────────────────────┐
│LoggingDecorator│ │RateLimitDecor │           │MFADecorator        │
├───────────────┤ ├───────────────┤           ├────────────────────┤
│+login override │ │+login override│           │+login override     │
└───────────────┘ └───────────────┘           └────────────────────┘
```



4\. **Java Implementation — Clean, Professional**
=================================================

**Component**
-------------

```java
public interface LoginService {
    boolean login(String user, String pass);
}
```


**Concrete Component**
----------------------

```java

public class BasicLoginService implements LoginService {
    @Override
    public boolean login(String user, String pass) {
        System.out.println("Validating username and password...");
        return "anshi".equals(user) && "123".equals(pass);
    }
}

```



**Base Decorator**
------------------

```java
public abstract class LoginDecorator implements LoginService {
    protected LoginService wrappee;

    public LoginDecorator(LoginService wrappee) {
        this.wrappee = wrappee;
    }

    @Override
    public boolean login(String user, String pass) {
        return wrappee.login(user, pass);
    }
}
```

**Concrete Decorators**
-----------------------

### Logging

```java
public class LoggingDecorator extends LoginDecorator {
    public LoggingDecorator(LoginService wrappee) {
        super(wrappee);
    }

    @Override
    public boolean login(String user, String pass) {
        System.out.println("Login attempt for: " + user);
        return super.login(user, pass);
    }
}
```

### Rate Limiting

```java
public class RateLimitDecorator extends LoginDecorator {
    public RateLimitDecorator(LoginService wrappee) {
        super(wrappee);
    }

    @Override
    public boolean login(String user, String pass) {
        System.out.println("Rate limiting check...");
        return super.login(user, pass);
    }
}
```

### MFA

```java
public class MFADecorator extends LoginDecorator {
    public MFADecorator(LoginService wrappee) {
        super(wrappee);
    }

    @Override
    public boolean login(String user, String pass) {
        System.out.println("MFA validation triggered...");
        return super.login(user, pass);
    }
}

```


**Client Code**
---------------

```java
public class Main {
    public static void main(String[] args) {

        LoginService service =
            new MFADecorator(
                new LoggingDecorator(
                    new RateLimitDecorator(
                        new BasicLoginService()
                    )
                )
            );

        service.login("anshi", "123");
    }
}
```



✅ **OUTPUT**
============

```yaml
Rate limiting check...
Login attempt for: anshi
MFA validation triggered...
Validating username and password...
```


If login succeeds, the final printed line from Main is:

```yaml
true
```
So the **full output** will be:

```yaml
Rate limiting check...
Login attempt for: anshi
MFA validation triggered...
Validating username and password...
true

```



🔍 Why this order?
==================

Each decorator wraps the next one:

```less
MFA(
   Logging(
      RateLimit(
         Basic
      )
   )
)
```


So execution flow is:

1.  **RateLimitDecorator.login()**
    
2.  → delegates to LoggingDecorator
    
3.  → delegates to MFADecorator
    
4.  → delegates to BasicLoginService
    
5.  → returns boolean back up the chain
    

This is exactly how the decorator pattern works:**Each decorator adds behavior before (or after) delegating to the wrapped object.**


5\. **Where Decorator is Used in Real Systems**
===============================================

### ✔ Java I/O

*   InputStream
    
*   BufferedInputStream
    
*   DataInputStream
    
*   ZipInputStream
    

All are decorators stacked over streams.

### ✔ Spring Boot

*   Filters
    
*   Interceptors
    
*   Handler Wrappers
    

### ✔ UI Toolkits

*   Scrollable window wraps plain window
    
*   Border decorator
    
*   Shadow decorator
    

### ✔ Logging and Monitoring Systems

*   Wrappers over services
    
*   Audit decorators
    

### ✔ Payments

*   Fraud check → Logging → Retry → Circuit breaker
    

6\. **Pros and Cons**
=====================

### ⭐ Pros

*   Add features _without modifying existing classes_
    
*   Add behavior _at runtime_
    
*   Avoids subclass explosion
    
*   Highly flexible (stackable decorators)
    

### ❌ Cons

*   Many small objects → more complexity
    
*   Debugging wrapper chains can be tricky
    
*   Hard to configure if chain becomes too long
    

7\. **Quick Summary (Interview Safe)**
======================================

**Decorator adds responsibilities to objects dynamically by wrapping them.It promotes composition over inheritance and is heavily used in I/O, logging, and framework-level extensibility.**
