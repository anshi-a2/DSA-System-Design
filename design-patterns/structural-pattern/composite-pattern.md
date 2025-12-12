🌿 Composite Pattern — Full Explanation
=======================================

📌 Intent
---------

Allow **individual objects** and **groups of objects** to be treated **uniformly**.

1\. **Real-World Analogy**
==========================

Your computer file system:

*   **File** → leaf
    
*   **Folder** → composite
    
*   A folder can contain:
    
    *   files
        
    *   folders
        
*   And you can perform an action (like _open_, _delete_) on both.
    

Composite = organize items _hierarchically_ and treat them the same.

2\. **Composite Pattern (Login Example)**
=========================================

Imagine your app needs to execute multiple security checks before login:

SecurityCheck (common interface)

*   PasswordStrengthCheck (leaf)
    
*   CaptchaCheck (leaf)
    
*   LocationCheck (leaf)
    
*   CompositeSecurityCheck (composite)
    
    *   runs all checks as a group
        

So you can do:

```java
securityCheck.validate(user);
```


Whether it's:

*   A single check, or
    
*   A group of multiple checks
    

→ It behaves the same.

3\. **UML Diagram — Composite Pattern (Login/Security Example)**
================================================================

```pgsql

                      Component
            ┌──────────────────────────┐
            │     SecurityCheck        │
            ├──────────────────────────┤
            │ + validate(user): bool   │
            └───────────▲─────────────┘
                        │
        ┌───────────────┼─────────────────────────────┐
        │                                               │
   Leaf Objects                                   Composite Object
┌──────────────────────┐                ┌────────────────────────────────┐
│ PasswordCheck         │                │ CompositeSecurityCheck        │
├──────────────────────┤                ├────────────────────────────────┤
│ validate() override  │                │ - List<SecurityCheck> checks  │
└──────────────────────┘                │ + add(check)                  │
                                        │ + validate(user) override     │
                                        └────────────────────────────────┘



```
4\. **Java Implementation**
===========================

**Component**
-------------

```java
public interface SecurityCheck {
    boolean validate(String user);
}
```


**Leaf 1**
----------

```java
public class PasswordCheck implements SecurityCheck {
    @Override
    public boolean validate(String user) {
        System.out.println("Password check done");
        return true;
    }
}

```


**Leaf 2**
----------

```java
public class OTPCheck implements SecurityCheck {
    @Override
    public boolean validate(String user) {
        System.out.println("OTP check done");
        return true;
    }
}
```


**Composite**
-------------

```java
import java.util.ArrayList;
import java.util.List;

public class CompositeSecurityCheck implements SecurityCheck {
    private final List<SecurityCheck> checks = new ArrayList<>();

    public void add(SecurityCheck check) {
        checks.add(check);
    }

    @Override
    public boolean validate(String user) {
        for (SecurityCheck c : checks) {
            if (!c.validate(user)) return false;
        }
        return true;
    }
}


```


**Client**
----------

```java
public class Main {
    public static void main(String[] args) {
        CompositeSecurityCheck composite = new CompositeSecurityCheck();
        composite.add(new PasswordCheck());
        composite.add(new OTPCheck());

        boolean result = composite.validate("anshi");
        System.out.println("Login checks passed: " + result);
    }
}


```


5\. **Where Composite Pattern is Used in Real Systems**
=======================================================

### ✔ UI frameworks

*   Components (buttons) inside containers/panels
    
*   Java Swing, Flutter, Android UI
    

### ✔ File Systems

*   File / Directory hierarchy
    

### ✔ Organization Hierarchy

*   Employee
    
*   Manager (who has employees)
    

### ✔ Menu Systems

*   Menu
    
*   Submenu
    
*   MenuItems
    

### ✔ Workflow Engines

*   Task
    
*   CompositeTask
    

### ✔ Cloud Resource Groups

*   Resource → group → group of groups
    

6\. **Pros and Cons**
=====================

### ⭐ Pros

*   Treat individual and grouped objects _uniformly_
    
*   No “if object is a group, do this else do that”
    
*   Makes hierarchical structures easy
    
*   Extensible—add new leaf types easily
    

### ❌ Cons

*   Can make system overly generic
    
*   Harder to enforce constraints(ex: preventing Composite from containing certain leaf types)
    
*   Debugging is tougher since actions become recursive
    

7\. **Quick Summary for Interviews**
====================================

**Composite lets you build tree structures where leaf and composite objects share the same interface.Client doesn’t care if it’s operating on a single object or an entire group.**

Perfect for hierarchical models.
