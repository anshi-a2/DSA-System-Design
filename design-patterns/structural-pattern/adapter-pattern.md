🔹 Adapter Pattern — Full Explanation (Login Example)
=====================================================

❓ What is Adapter Pattern?
--------------------------

Adapter Pattern is a **structural design pattern** used to make **two incompatible interfaces work together**.

Think of it as:

> “A translator between two systems.”

It wraps an existing class to match the interface expected by the client.

📌 Real Login Example — Why Adapter?
====================================

Suppose your app uses a standard interface:

```java
public interface LoginService {
      boolean login(String username, String password);
  }
```

But you must integrate with a **third-party Google Login SDK** that has an entirely different method signature:

```java
public class GoogleAuthSDK {
      public boolean authenticateWithToken(String token) {
          return true;
      }
  }
```

Your app expects:

```java
login(username, password)
```

Google SDK provides:

```java
authenticateWithToken(token)
```

❌ Incompatible✔ Use Adapter to convert your interface → Google SDK format

🧩 UML Diagram — Adapter Pattern (Google Login Example)
=======================================================

```pgsql
                     ┌───────────────────────────────┐
                     │        LoginService            │ <<Target Interface>>
                     ├───────────────────────────────┤
                     │ + login(username, password)    │
                     └──────────────▲────────────────┘
                                    │
                                    │ implements
                                    │
                     ┌───────────────────────────────┐
                     │     GoogleLoginAdapter        │ <<Adapter>>
                     ├───────────────────────────────┤
                     │ - googleAuthSDK: GoogleAuthSDK │
                     ├───────────────────────────────┤
                     │ + login(username, password)    │
                     └──────────────▲────────────────┘
                                    │
                                    │ uses
                                    ▼
                     ┌───────────────────────────────┐
                     │        GoogleAuthSDK           │ <<Adaptee>>
                     ├───────────────────────────────┤
                     │ + authenticateWithToken(token) │
                     └───────────────────────────────┘

                                  Client
   ┌────────────────────────────────────────────────────────────────────────┐
   │ LoginService service = new GoogleLoginAdapter(new GoogleAuthSDK());     │
   │ service.login("anshi", "password");                                     │
   └────────────────────────────────────────────────────────────────────────┘


```


🎯 Adapter Pattern Java Code (Login Example)
============================================

🔹 Target Interface (used across your system)
---------------------------------------------

```java
public interface LoginService {
      boolean login(String username, String password);
  }
   ```

🔹 Adaptee (3rd-party SDK)
--------------------------

```java
public class GoogleAuthSDK {
      public boolean authenticateWithToken(String token) {
          System.out.println("Google authenticated with token");
          return true;
      }
  }
```

🔹 Adapter (converts your interface → adaptee interface)
--------------------------------------------------------

```java
public class GoogleLoginAdapter implements LoginService {
      private final GoogleAuthSDK googleAuthSDK;

      public GoogleLoginAdapter(GoogleAuthSDK googleAuthSDK) {
          this.googleAuthSDK = googleAuthSDK;
      }

      @Override
      public boolean login(String username, String password) {
          // Convert your system's login inputs into token
          String token = username + ":" + password; // simulate token
          return googleAuthSDK.authenticateWithToken(token);
      }
  }
```

🔹 Client Usage
---------------

```java
public class Client {
      public static void main(String[] args) {
          LoginService loginService = new GoogleLoginAdapter(new GoogleAuthSDK());
          loginService.login("anshi", "12345");
      }
  }
```

🟦 Why Adapter is useful (real systems)
=======================================

| Scenario                                     | How Adapter Helps                   |
| -------------------------------------------- | ----------------------------------- |
| Integrating 3rd-party services               | Unified interface for your system   |
| Replacing legacy systems                     | Wrap old classes into new interface |
| Migrating from old API to new API            | Backward compatibility              |
| Multi-provider login (Google, Facebook, SSO) | Each provider has its own adapter   |
| Avoiding code changes across microservices   | Maintain one common interface       |



🟩 Types of Adapter Pattern
===========================

### 1\. **Object Adapter** (Most common – uses composition)

We used this above.

### 2\. **Class Adapter** (Uses inheritance)

Only works in languages with multiple inheritance (not Java).

⭐ Pros & Cons
=============

✔ Advantages
------------

*   Makes incompatible interfaces work together
    
*   No need to modify existing code
    
*   Enables reuse of legacy/third-party code
    
*   Cleaner integration layer
    
*   Improves flexibility in plugging new providers
    

❗ Disadvantages
---------------

*   More classes in the system
    
*   Indirection may add slight complexity
    
*   If too many adapters → messy architecture
    

🎤 Interview 30–Second Summary
==============================

> Adapter Pattern allows two incompatible interfaces to work together by creating an adapter class that translates one interface into another. It is heavily used in integrating external libraries, legacy systems, and authentication providers like Google/Facebook.
