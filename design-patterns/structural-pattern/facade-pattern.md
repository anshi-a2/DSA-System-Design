🧱 Facade Pattern — Full Explanation
====================================

📌 Intent
---------

Provide a **simple, unified interface** to a **complex subsystem**.

> Facade hides complexity and exposes **only what the client needs**.

1\. **Real-World Analogy**
==========================

Think of a **hotel reception desk**:

*   You don’t talk to housekeeping, billing, room service directly
    
*   You talk to **one reception desk**
    
*   Reception internally coordinates multiple systems
    

Reception = **Facade**

2\. **Login Example (Facade Pattern)**
======================================

A real login flow involves many subsystems:

*   UserService (fetch user)
    
*   PasswordService (validate password)
    
*   OTPService (verify OTP)
    
*   TokenService (generate JWT)
    
*   AuditService (log event)
    

Without Facade, the client must call **all** of them.

With Facade:

```pgsql
loginFacade.login(username, password, otp)
```


Client sees **one method**, complexity stays hidden.

3\. **UML Diagram — Facade Pattern (Login Example)**
====================================================

```scss
                         Client
                            │
                            ▼
               ┌────────────────────────────┐
               │        LoginFacade          │
               ├────────────────────────────┤
               │ + login(u,p,otp): Token     │
               └───────────▲────────────────┘
                           │
     ┌─────────────────────┼───────────────────────────────┐
     │                     │                               │
┌─────────────┐    ┌─────────────┐     ┌─────────────┐   ┌─────────────┐
│ UserService │    │ PasswordSvc │     │ OTPService  │   │ TokenService│
└─────────────┘    └─────────────┘     └─────────────┘   └─────────────┘
                                            │
                                     ┌─────────────┐
                                     │ AuditService│
                                     └─────────────┘

```


4\. **Java Implementation**
===========================

**Subsystem Classes**
---------------------

### UserService

```java
public class UserService {
    public String getUser(String username) {
        System.out.println("Fetching user from DB");
        return username;
    }
}
```


### PasswordService

```java
public class PasswordService {
    public boolean validate(String user, String password) {
        System.out.println("Validating password");
        return "123".equals(password);
    }
}
```



### OTPService

```java
public class OTPService {
    public boolean verify(String otp) {
        System.out.println("Verifying OTP");
        return "999999".equals(otp);
    }
}
```


### TokenService

```java
public class TokenService {
    public String generate(String user) {
        System.out.println("Generating JWT token");
        return "jwt-token-for-" + user;
    }
}
```


### AuditService

```java
public class AuditService {
    public void log(String user) {
        System.out.println("Logging login event");
    }
}
```


**Facade**
----------

```java
public class LoginFacade {

    private final UserService userService = new UserService();
    private final PasswordService passwordService = new PasswordService();
    private final OTPService otpService = new OTPService();
    private final TokenService tokenService = new TokenService();
    private final AuditService auditService = new AuditService();

    public String login(String username, String password, String otp) {

        String user = userService.getUser(username);

        if (!passwordService.validate(user, password)) {
            throw new RuntimeException("Invalid password");
        }

        if (!otpService.verify(otp)) {
            throw new RuntimeException("Invalid OTP");
        }

        auditService.log(user);
        return tokenService.generate(user);
    }
}
```

**Client Code**
---------------

```java
public class Main {
    public static void main(String[] args) {
        LoginFacade facade = new LoginFacade();
        String token = facade.login("anshi", "123", "999999");
        System.out.println("Login successful: " + token);
    }
}
```


5\. **Program Output**
======================

```pgsql
Fetching user from DB
Validating password
Verifying OTP
Logging login event
Generating JWT token
Login successful: jwt-token-for-anshi
```


6\. **Where Facade Pattern is Used in Real Systems**
====================================================

### ✔ Spring Framework

*   JdbcTemplate
    
*   RestTemplate
    
*   KafkaTemplate
    

### ✔ API Gateways

*   Single entry point → many microservices
    

### ✔ SDKs

*   AWS SDK hides hundreds of API calls
    

### ✔ Video Encoding

*   One method → many codecs and configurations
    

### ✔ Banking Systems

*   processPayment() internally talks to risk, ledger, notification
    

7\. **Facade vs Related Patterns (Very Important)**
===================================================

| Pattern       | Purpose             |
| ------------- | ------------------- |
| **Facade**    | Simplifies usage    |
| **Adapter**   | Converts interfaces |
| **Decorator** | Adds behavior       |
| **Proxy**     | Controls access     |



> Facade **does NOT change behavior**It **only hides complexity**

8\. **Pros and Cons**
=====================

### ⭐ Pros

*   Simplifies client code
    
*   Reduces coupling
    
*   Improves readability
    
*   Easier onboarding for new devs
    

### ❌ Cons

*   Can become a **god class**
    
*   May hide too much functionality
    
*   Changes in subsystem can affect facade
    

9\. **30-Second Interview Summary**
===================================

**Facade provides a unified, simplified interface to a complex subsystem, hiding implementation details and reducing coupling. It is commonly used in frameworks, SDKs, and API layers.**
