🛡️ Proxy Pattern — Full Explanation
====================================

📌 Intent
---------

Provide a **substitute or placeholder** for another object to **control access** to it.

> Proxy looks like the real object but adds **extra control** before or after delegating the call.

1\. **Real-World Analogy**
==========================

Think of a **security guard**:

*   You don’t enter the building directly
    
*   Guard checks your ID → then allows access
    

The guard is the **proxy**.The building is the **real object**.

2\. **Login / Auth Example (Why Proxy?)**
=========================================

Suppose you have a UserService that:

*   Fetches sensitive user data
    
*   Makes DB calls
    
*   Must be protected
    

You want to:

*   Check authorization
    
*   Add logging
    
*   Cache results
    

**Without changing UserService**.

👉 Wrap it with a **Proxy**.

3\. **Types of Proxy (Important for Interviews)**
=================================================

| Proxy Type           | Purpose                                  |
| -------------------- | ---------------------------------------- |
| **Virtual Proxy**    | Lazy loading (create object when needed) |
| **Protection Proxy** | Access control / security                |
| **Caching Proxy**    | Cache results                            |
| **Remote Proxy**     | Represents remote service                |
| **Logging Proxy**    | Audit / monitoring                       |



4\. **UML Diagram — Proxy Pattern (UserService Example)**
=========================================================

```pgsql
                    Client
                       |
                       ▼
              ┌──────────────────────┐
              │      UserService     │ <<Subject>>
              ├──────────────────────┤
              │ + getUser(id)        │
              └─────────▲────────────┘
                        |
        ┌───────────────┼────────────────────────┐
        │                                           
┌──────────────────────┐              ┌────────────────────────┐
│  UserServiceProxy    │              │   RealUserService      │
├──────────────────────┤              ├────────────────────────┤
│ - real: UserService  │              │ + getUser(id)          │
│ + getUser(id)        │              └────────────────────────┘
└──────────────────────┘
```


5\. **Java Implementation**
===========================

**Subject Interface**
---------------------

```java
public interface UserService {
    String getUser(String userId);
}
```



**Real Subject**
----------------

```java
public class RealUserService implements UserService {

    @Override
    public String getUser(String userId) {
        System.out.println("Fetching user from database");
        return "User(" + userId + ")";
    }
}
```


**Proxy**
---------

```java
import java.util.HashMap;
import java.util.Map;

public class UserServiceProxy implements UserService {

    private final UserService realService = new RealUserService();
    private final Map<String, String> cache = new HashMap<>();

    @Override
    public String getUser(String userId) {

        // Access control
        if (!isAuthorized()) {
            throw new RuntimeException("Access denied");
        }

        // Caching
        if (cache.containsKey(userId)) {
            System.out.println("Returning cached user");
            return cache.get(userId);
        }

        // Delegate to real object
        String user = realService.getUser(userId);
        cache.put(userId, user);
        return user;
    }

    private boolean isAuthorized() {
        return true; // simulate auth check
    }
}
```


**Client Code**
---------------

```java
public class Main {
    public static void main(String[] args) {
        UserService service = new UserServiceProxy();

        System.out.println(service.getUser("101"));
        System.out.println(service.getUser("101"));
    }
}
```


6\. **Program Output**
======================

```pgsql
Fetching user from database
User(101)
Returning cached user
User(101)
```


Notice:

*   DB call happens only once
    
*   Second call served from proxy cache
    

7\. **Proxy vs Decorator vs Adapter (Very Common Question)**
============================================================

| Pattern       | Key Purpose          |
| ------------- | -------------------- |
| **Proxy**     | Controls access      |
| **Decorator** | Adds behavior        |
| **Adapter**   | Converts interface   |
| **Facade**    | Simplifies subsystem |


> Proxy and Decorator look similar structurallyIntent is what differentiates them

8\. **Where Proxy Pattern Is Used in Real Systems**
===================================================

### ✔ Spring Framework

*   @Transactional
    
*   @Cacheable
    
*   @Security
    

### ✔ Hibernate

*   Lazy loading proxies
    

### ✔ Microservices

*   API gateways
    
*   Service mesh
    

### ✔ RPC / gRPC

*   Client stubs
    

### ✔ Cloud SDKs

*   AWS clients
    

9\. **Pros and Cons**
=====================

### ⭐ Pros

*   Adds security without modifying real object
    
*   Lazy loading improves performance
    
*   Caching reduces expensive calls
    
*   Transparent to client
    

### ❌ Cons

*   Additional indirection
    
*   Debugging becomes harder
    
*   Can hide performance issues
    

10\. **30-Second Interview Summary**
====================================

> Proxy Pattern provides a surrogate for another object to control access to it. It is commonly used for security, caching, lazy loading, and remote access. Proxy keeps the same interface as the real object, making it transparent to the client.
