🪶 Flyweight Pattern — Full Explanation
=======================================

📌 Intent
---------

**Reduce memory usage** by sharing **common (intrinsic) state** between many objects instead of duplicating it.

> Flyweight focuses on **object reuse** when you have **a large number of similar objects**.

1\. **Real-World Analogy**
==========================

Think of **characters in a document editor**:

*   Each letter has:
    
    *   Shape (font, glyph) → **shared**
        
    *   Position (x, y), color → **unique**
        

You don’t create a new object for every “A”.You reuse one “A” object and supply position externally.

2\. **Login / Security Example (Why Flyweight?)**
=================================================

Imagine a system with **millions of logged-in users**, each having:

*   Role permissions
    
*   Access policies
    
*   Feature flags
    

These are **identical for users with the same role**.

❌ Without FlyweightEvery session stores its own copy → huge memory waste

✅ With FlyweightStore **one shared RolePermission object**, reuse it across sessions.

3\. **Key Concepts (Very Important for Interview)**
===================================================

| Term                  | Meaning                           |
| --------------------- | --------------------------------- |
| **Intrinsic State**   | Shared, immutable data            |
| **Extrinsic State**   | User-specific, supplied by client |
| **Flyweight**         | Shared object                     |
| **Flyweight Factory** | Manages creation & reuse          |



4\. **UML Diagram — Flyweight Pattern (Role Example)**
======================================================

```pgsql
                    Client (Login Session)
                            |
                            ▼
                ┌──────────────────────────┐
                │   RolePermissionFactory  │
                ├──────────────────────────┤
                │ + getRole(role): RolePerm│
                └───────────▲──────────────┘
                            |
                            | returns shared object
                            |
               ┌──────────────────────────┐
               │    RolePermission         │ <<Flyweight>>
               ├──────────────────────────┤
               │ - roleName (intrinsic)    │
               │ - permissions (intrinsic)│
               ├──────────────────────────┤
               │ + hasPermission(p)        │
               └──────────────────────────┘


```
5\. **Java Implementation**
===========================

**Flyweight (Shared Object)**
-----------------------------

```java
import java.util.Set;

public class RolePermission {
    private final String roleName;
    private final Set<String> permissions;

    public RolePermission(String roleName, Set<String> permissions) {
        this.roleName = roleName;
        this.permissions = permissions;
    }

    public boolean hasPermission(String permission) {
        return permissions.contains(permission);
    }
}
```


**Flyweight Factory**
---------------------

```java
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class RolePermissionFactory {

    private static final Map<String, RolePermission> cache = new HashMap<>();

    public static RolePermission getRole(String role) {
        return cache.computeIfAbsent(role, r -> {
            System.out.println("Creating RolePermission for " + r);
            return new RolePermission(r, loadPermissions(r));
        });
    }

    private static Set<String> loadPermissions(String role) {
        if ("ADMIN".equals(role)) {
            return Set.of("READ", "WRITE", "DELETE");
        }
        return Set.of("READ");
    }
}
```


**Client (Login Session – Extrinsic State)**
--------------------------------------------

```java
public class UserSession {
    private final String userId;        // extrinsic
    private final String ipAddress;     // extrinsic
    private final RolePermission role;  // intrinsic (shared)

    public UserSession(String userId, String ipAddress, String roleName) {
        this.userId = userId;
        this.ipAddress = ipAddress;
        this.role = RolePermissionFactory.getRole(roleName);
    }

    public boolean canAccess(String permission) {
        return role.hasPermission(permission);
    }
}
```


**Client Usage**
----------------

```java
public class Main {
    public static void main(String[] args) {

        UserSession u1 = new UserSession("u1", "10.0.0.1", "ADMIN");
        UserSession u2 = new UserSession("u2", "10.0.0.2", "ADMIN");
        UserSession u3 = new UserSession("u3", "10.0.0.3", "USER");

        System.out.println(u1.canAccess("DELETE"));
        System.out.println(u2.canAccess("DELETE"));
        System.out.println(u3.canAccess("DELETE"));
    }
}
```


6\. **Program Output**
======================

```rust
Creating RolePermission for ADMIN
Creating RolePermission for USER
true
true
false
```


Notice:

*   ADMIN role object created **only once**
    
*   USER role object created **only once**
    

7\. **Where Flyweight Pattern Is Used**
=======================================

### ✔ JVM Internals

*   **String pool**
    
*   Integer cache (-128 to 127)
    

### ✔ UI Rendering

*   Glyphs, fonts, icons
    

### ✔ Game Engines

*   Trees, bullets, particles
    

### ✔ Authentication / Authorization

*   Roles & permissions
    
*   Policy objects
    

### ✔ Map / GIS Systems

*   Roads, symbols, markers
    

8\. **Pros and Cons**
=====================

### ⭐ Pros

*   Massive memory savings
    
*   Faster object creation
    
*   Centralized object management
    
*   Ideal for large-scale systems
    

### ❌ Cons

*   Adds complexity
    
*   Requires clear separation of intrinsic/extrinsic state
    
*   Debugging shared state can be tricky
    

9\. **30-Second Interview Summary**
====================================

> Flyweight Pattern reduces memory usage by sharing common, immutable state across many objects. It separates intrinsic and extrinsic state and uses a factory to manage object reuse. Commonly used in JVM, UI rendering, games, and authorization systems.
