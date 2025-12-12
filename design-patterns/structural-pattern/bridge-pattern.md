🌉 Bridge Pattern — Full Explanation
====================================

**Goal:** Decouple abstraction from implementation so both can change independently.

1\. **Real-World Analogy (Simple Understanding)**
=================================================

Think of a **Remote Control (Abstraction)** and a **TV (Implementation)**.

*   You can have different remotes: BasicRemote, AdvancedRemote
    
*   And different TVs: SonyTV, SamsungTV
    
*   Any remote works with any TV → They are **independent but connected via a bridge**.
    

**Bridge = remote has a reference to a TV implementation.**

2\. **Login Example (Bridge Pattern)**
======================================

Let’s use a **Login Process (Abstraction)** and **different Authentication Methods (Implementations)**:

### **Abstraction**

*   LoginManager
    
*   (refers to AuthenticationProvider)
    

### **Implementations**

*   PasswordAuthProvider
    
*   OTPAuthProvider
    
*   OAuthProvider
    

Because of Bridge, you can mix and match:

*   BasicLogin with PasswordAuth
    
*   BasicLogin with OTP
    
*   CorporateLogin with OAuth
    
*   MobileLogin with OTP
    

Without changing each other.

3\. **UML Diagram (Bridge Pattern – Login Example)**
====================================================

```pgsql

                               Abstraction
                    ┌────────────────────────────────┐
                    │        LoginManager             │
                    ├────────────────────────────────┤
                    │ - provider: Authentication      │
                    ├────────────────────────────────┤
                    │ + login(user, credential)       │
                    └───────────────────▲─────────────┘
                                        │
                        Refers to       │
                                        │
                 Implementor Interface  │
         ┌────────────────────────────────────────┐
         │        AuthenticationProvider           │
         ├────────────────────────────────────────┤
         │ + authenticate(user, data)              │
         └──────────────▲───────────▲─────────────┘
                        │           │
                        │           │
           ┌────────────┘           └──────────────┐
           │                                        │
┌─────────────────────────┐          ┌──────────────────────────┐
│   PasswordAuthProvider  │          │      OTPAuthProvider     │
├─────────────────────────┤          ├──────────────────────────┤
│ authenticate() override │          │ authenticate() override  │
└─────────────────────────┘          └──────────────────────────┘


```






4\. **Java Implementation**
===========================

### **Implementor Interface**

```java
public interface AuthenticationProvider {
    boolean authenticate(String userId, String data);
}
```



### **Concrete Implementors**

```java
public class PasswordAuthProvider implements AuthenticationProvider {
    @Override
    public boolean authenticate(String userId, String password) {
        return "pass123".equals(password);
    }
}

public class OTPAuthProvider implements AuthenticationProvider {
    @Override
    public boolean authenticate(String userId, String otp) {
        return "123456".equals(otp);
    }
}
```


### **Abstraction**

```java
public abstract class LoginManager {
    protected AuthenticationProvider provider;

    public LoginManager(AuthenticationProvider provider) {
        this.provider = provider;
    }

    public abstract boolean login(String userId, String credentials);
}

```


### **Refined Abstraction**

```java
public class BasicLoginManager extends LoginManager {

    public BasicLoginManager(AuthenticationProvider provider) {
        super(provider);
    }

    @Override
    public boolean login(String userId, String credentials) {
        return provider.authenticate(userId, credentials);
    }
}
```


### **Client Code**

```java
public class Main {
    public static void main(String[] args) {
        LoginManager login1 = new BasicLoginManager(new PasswordAuthProvider());
        System.out.println(login1.login("anshi", "pass123"));

        LoginManager login2 = new BasicLoginManager(new OTPAuthProvider());
        System.out.println(login2.login("anshi", "123456"));
    }
}
```



5\. **Where Bridge Pattern is Used in Real Systems?**
=====================================================

### ✔ Frameworks

*   JDBC API (Java)
    
    *   Abstraction: Connection, Statement
        
    *   Implementation: MySQL, PostgreSQL, Oracle drivers
        

### ✔ UI Frameworks

*   Abstraction: Button
    
*   Implementation: WindowsButton, MacButton, LinuxButton
    

### ✔ Message senders

*   Abstraction: Message
    
*   Implementation: SMS, Email, WhatsApp
    

### ✔ Payment Gateways

*   Abstraction: Payment
    
*   Implementation: PayPal, RazorPay, Stripe
    

### ✔ Cloud Storage Wrappers

*   Abstraction: StorageService
    
*   Implementation: S3, GCS, Azure Blob
    

6\. **Pros and Cons**
=====================

### ⭐ Advantages

*   **Abstraction & Implementation evolve independently**
    
*   **Avoids class explosion** (not like subclassing for every variant)
    
*   **Great for scaling** — add new auth methods without breaking login flow
    
*   **Supports composition over inheritance**
    

### ❌ Disadvantages

*   **More classes** than simple inheritance
    
*   **More complexity** for small use cases
    
*   Can be **overkill** if you have only 1 implementation
    

7\. Quick Summary
=================

**Bridge = Composition + Interfaces**It decouples:

*   _What you do_ (Login Manager)
    
*   _How it is done_ (Authentication Provider)
    

This makes the system **flexible**, **scalable**, and **extensible**.
