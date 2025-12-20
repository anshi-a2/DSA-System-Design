🤝 Mediator Pattern — Complete Explanation
==========================================

📌 Intent
---------

Define an object that **encapsulates how a set of objects interact**, promoting **loose coupling** by preventing objects from referring to each other explicitly.

> Colleagues talk **only to the mediator**, not to each other.

1️⃣ Real-World Analogy
======================

✈️ **Air Traffic Control**

*   Planes do NOT talk to each other
    
*   All communication goes via control tower
    

Tower = **Mediator**Planes = **Colleagues**

2️⃣ Enterprise Login Example (Why Mediator?)
============================================

Login flow often involves many components:

*   Login UI
    
*   Auth Service
    
*   OTP Service
    
*   Notification Service
    
*   Audit Service
    

Without Mediator:

*   Each component directly calls others → **tight coupling**
    

With Mediator:

*   All communication goes via **LoginMediator**
    

3️⃣ UML Diagram — Mediator Pattern (Login Example)
==================================================

```pgsql
                     Client
                        |
                        ▼
                ┌──────────────────┐
                │    Mediator      │ <<interface>>
                ├──────────────────┤
                │ + notify()       │
                └────────▲─────────┘
                         |
                ┌────────────────────┐
                │  LoginMediator     │
                └────────▲───────────┘
                          |
        ┌─────────────────┼─────────────────┐
        |                 |                 |
┌─────────────┐   ┌─────────────┐   ┌─────────────┐
│ LoginUI     │   │ AuthService │   │ OtpService  │
│ (Colleague) │   │ (Colleague) │   │ (Colleague) │
└─────────────┘   └─────────────┘   └─────────────┘

```



4️⃣ Java Implementation
=======================

**Mediator Interface**
----------------------

```java
public interface LoginMediator {
    void notify(Component sender, String event);
}
```


**Abstract Colleague**
----------------------

```java
public abstract class Component {
    protected LoginMediator mediator;

    public Component(LoginMediator mediator) {
        this.mediator = mediator;
    }
}
```


**Concrete Colleagues**
-----------------------

```java
public class LoginUI extends Component {

    public LoginUI(LoginMediator mediator) {
        super(mediator);
    }

    public void submitLogin() {
        System.out.println("Login submitted");
        mediator.notify(this, "LOGIN_SUBMIT");
    }
}

public class AuthService extends Component {

    public AuthService(LoginMediator mediator) {
        super(mediator);
    }

    public void authenticate() {
        System.out.println("Authenticating user");
    }
}

public class OtpService extends Component {

    public OtpService(LoginMediator mediator) {
        super(mediator);
    }

    public void sendOtp() {
        System.out.println("Sending OTP");
    }
}
```



**Concrete Mediator**
---------------------

```java
public class ConcreteLoginMediator implements LoginMediator {

    private LoginUI ui;
    private AuthService auth;
    private OtpService otp;

    public void setUi(LoginUI ui) {
        this.ui = ui;
    }

    public void setAuth(AuthService auth) {
        this.auth = auth;
    }

    public void setOtp(OtpService otp) {
        this.otp = otp;
    }

    @Override
    public void notify(Component sender, String event) {

        if (sender == ui && event.equals("LOGIN_SUBMIT")) {
            auth.authenticate();
            otp.sendOtp();
        }
    }
}
```


**Client Code**
---------------

```java
public class Main {
    public static void main(String[] args) {

        ConcreteLoginMediator mediator = new ConcreteLoginMediator();

        LoginUI ui = new LoginUI(mediator);
        AuthService auth = new AuthService(mediator);
        OtpService otp = new OtpService(mediator);

        mediator.setUi(ui);
        mediator.setAuth(auth);
        mediator.setOtp(otp);

        ui.submitLogin();
    }
}
```


5️⃣ Program Output
==================

```pgsql
Login submitted
Authenticating user
Sending OTP
```


6️⃣ Where Mediator Pattern Is Used in Real Systems
==================================================

### ✔ UI Frameworks

*   Dialog controllers
    
*   Form coordination
    

### ✔ Microservices Orchestration

*   Saga orchestrators
    

### ✔ Workflow Engines

*   BPM systems
    

### ✔ Chat Systems

*   Message routing
    

7️⃣ Mediator vs Related Patterns
================================

| Pattern      | Difference                |
| ------------ | ------------------------- |
| **Mediator** | Centralized communication |
| **Observer** | Broadcast notifications   |
| **Facade**   | Simplified interface      |
| **Command**  | Encapsulated actions      |


8️⃣ Pros and Cons
=================

### ⭐ Pros

*   Reduces coupling
    
*   Centralizes logic
    
*   Easier maintenance
    
*   Cleaner colleagues
    

### ❌ Cons

*   Mediator can become god object
    
*   Complex mediator logic
    
*   Harder to test if bloated
    

9️⃣ Interview One-Liner
=======================

> Mediator Pattern centralizes object interactions into a mediator, reducing coupling and making systems easier to maintain.

🔟 Key Interview Insight
========================

*   **Facade** simplifies client access
    
*   **Mediator** simplifies internal communication
