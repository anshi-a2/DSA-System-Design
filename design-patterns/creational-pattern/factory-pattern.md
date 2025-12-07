🔹 What is the Factory Method Pattern?
--------------------------------------

Factory Method is a **creational design pattern** that provides a way to create objects **without exposing the creation logic to the client**.Instead of calling new directly, the object creation is handled by a **factory method**, allowing subclasses or separate factory classes to decide which object to create.

In simple words:**Factory Method delegates object creation to another method/class → helps in flexibility and loose coupling.**

🔹 Why Factory Method for Login Service?
----------------------------------------

Imagine an application offering **multiple login methods**:

*   Email/Password login
    
*   Google OAuth login
    
*   LinkedIn login
    
*   Phone OTP login
    

If we use new EmailLoginService(), new GoogleLoginService() everywhere, the code becomes rigid and hard to extend.

Factory Method fixes this by allowing:

*   Easy addition of new login types
    
*   Switching login providers based on config/user choice
    
*   Reduction of if/else or switch statements throughout the code
    

🔹 Login Service Example Using Factory Method
---------------------------------------------

### Step 1 — Create a LoginService Interface

```java
public interface LoginService {
      boolean login(String username, String password);
  }
   ```

### Step 2 — Implement Multiple Login Services

```java   
public class EmailLoginService implements LoginService {
      public boolean login(String username, String password) {
          System.out.println("Email login success for " + username);
          return true;
      }
  }
   ```

```java   
public class GoogleLoginService implements LoginService {
      public boolean login(String username, String password) {
          System.out.println("Google OAuth login success for " + username);
          return true;
      }
  }
   ```

### Step 3 — Factory Class to Create Login Services

```java
public class LoginServiceFactory {
      public static LoginService getLoginService(String type) {
          switch (type) {
              case "EMAIL": return new EmailLoginService();
              case "GOOGLE": return new GoogleLoginService();
              default: throw new IllegalArgumentException("Invalid login type");
          }
      }
  }
   ```

### Step 4 — Client Uses Factory Instead of new

```java
public class Main {
      public static void main(String[] args) {
          LoginService loginService =  LoginServiceFactory.getLoginService("GOOGLE");
          loginService.login("anshi", "password123");
      }
  }
   ```

Now if tomorrow we add LinkedInLoginService, only factory needs update — **client code doesn’t change**.🔹 UML Class Diagram — Factory Method for Login Service

```pgsql
                ┌────────────────────────┐
                │      LoginService      │  <<interface>>
                ├────────────────────────┤
                │ + login(username, pwd) │
                └───────────▲────────────┘
                            │
        ┌───────────────────┴────────────────────┐
        │                                        │
┌────────────────────────┐             ┌────────────────────────┐
│  EmailLoginService     │             │ GoogleLoginService     │
├────────────────────────┤             ├────────────────────────┤
│ + login(username, pwd) │             │ + login(username, pwd) │
└────────────────────────┘             └────────────────────────┘


                          ┌──────────────────────────┐
                          │   LoginServiceFactory    │  <<creator>>
                          ├──────────────────────────┤
                          │ + getLoginService(type)  │
                          └───────────┬──────────────┘
                                      │ uses
                                      ▼
                          ┌──────────────────────────┐
                          │     LoginService Obj     │
                          └──────────────────────────┘


Client Code
    │
    │ calls
    ▼
┌────────────────────────────┐
│  LoginServiceFactory.get() │
└────────────────────────────┘
         │
 returns │ LoginService instance
         ▼
┌────────────────────────────┐
│ EmailLoginService /        │
│ GoogleLoginService         │
└────────────────────────────┘

```





### 🔍 Explanation of UML Components

| Component                                                      | Responsibility                                                               |
| -------------------------------------------------------------- | ---------------------------------------------------------------------------- |
| **LoginService (interface)**                                   | Defines login method — common contract                                       |
| **EmailLoginService / GoogleLoginService (Concrete Products)** | Implement login behavior in their own way                                    |
| **LoginServiceFactory (Creator / Factory)**                    | Contains logic to decide which LoginService to create                        |
| **Client**                                                     | Requests login service from factory — does NOT directly instantiate services |



🔹 Pros of Factory Method
-------------------------

| Benefit              | Meaning                                                  |
| -------------------- | -------------------------------------------------------- |
| Loose coupling       | Client is independent of specific class implementations  |
| Easy to extend       | Add new object types without modifying client            |
| Cleaner code         | Removes repetitive `if/else` object creation logic       |
| Improves testability | Mocking becomes easier since object creation is isolated |


🔹 Cons of Factory Method
-------------------------

| Limitation               | Meaning                                                                                                  |
| ------------------------ | -------------------------------------------------------------------------------------------------------- |
| More files & abstraction | Many subclasses/factory classes may form                                                                 |
| Slight complexity        | Beginners take time to understand structure                                                              |
| Factory modification     | Factory needs update when adding new types (unless using advanced patterns like Reflection/Registration) |



🔹 Common Real-world Use Cases of Factory Method
------------------------------------------------

| Example                   | Description                          |
| ------------------------- | ------------------------------------ |
| Database driver selection | MySQL / PostgreSQL / Oracle          |
| Payment gateways          | Stripe / Razorpay / PayPal / PhonePe |
| Notification services     | SMS / Email / Push / WhatsApp        |
| UI components             | Button for Windows / macOS / Linux   |
| Parser selection          | XML / JSON / CSV parsers             |
| Vehicle booking           | Bike / Auto / Cab / Rental Car       |
| Storage service           | Local / AWS S3 / Azure Blob          |



🔹 When Should You Use Factory Method?
--------------------------------------

Use Factory Method when:

*   Object creation depends on conditions (login type, payment type, OS, region)
    
*   Client should not know which class to instantiate
    
*   Future extensibility is needed
    
*   Switching implementations dynamically is required
    

Avoid when:

*   Only one implementation exists and is unlikely to change
    
*   Object creation is simple and not conditional
    

🔥 One-line Interview Ready Definition
--------------------------------------

> Factory Method pattern delegates object creation to subclasses or factory classes, making systems flexible and allowing new object types to be introduced without modifying client code.
