🔹 What is the Prototype Pattern?
---------------------------------

Prototype Pattern is a **creational design pattern** used when:

*   You want to **create a new object by copying an existing one instead of creating from scratch**
    
*   Object creation is **expensive / slow / complex**
    
*   A system needs **cloning at runtime** without knowing the exact class type
    

Prototype enables:

> Creating objects via **clone()** instead of **new**

🔥 Login Example — Why Prototype?
---------------------------------

Imagine you have a UserSession object built after:

*   Authentication
    
*   Token generation
    
*   Permissions / roles loading
    
*   Device info mapping
    
*   Security metadata creation
    

This object is **heavy to construct**, but for each new request from the same user, we want something similar with **only small modifications**.

Instead of rebuilding the whole object again → we **clone it**.

✅ Java Example — Prototype Pattern (UserSession)
------------------------------------------------

### 🔹 Prototype Interface

```java
public interface Prototype {
      T clone();
  }
```

### 🔹 Concrete Prototype (UserSession)

```java
public class UserSession implements Prototype {
      private String username;
      private String token;
      private String deviceId;
      private String ipAddress;
      private List roles; // heavy data from DB

      public UserSession(String username, String token, String deviceId, String ipAddress, List roles) {
          this.username = username;
          this.token = token;
          this.deviceId = deviceId;
          this.ipAddress = ipAddress;
          this.roles = roles;
      }

      @Override
      public UserSession clone() {
          return new UserSession(
                  this.username,
                  this.token,
                  this.deviceId,
                  this.ipAddress,
                  new ArrayList<>(this.roles) // deep copy
          );
      }
  }
   ```

### 🔹 Client Usage

```java
UserSession original = new UserSession("anshi", "jwt-token", "D8272F", "123.44.9.1", rolesFromDb);
  UserSession cloned = original.clone();
  cloned.setIpAddress("8.8.8.8"); // only update what changed
  System.out.println("Original IP: " + original.getIpAddress());
  System.out.println("Cloned IP: " + cloned.getIpAddress());
```

✔ No expensive DB calls again✔ All roles & metadata already available✔ Only changed fields are updated

🧩 UML Diagram — Prototype Pattern (UserSession)
------------------------------------------------

```pgsql


                      ┌───────────────────────────────┐
                      │      Prototype<T>              │ <<interface>>
                      ├───────────────────────────────┤
                      │ + clone(): T                   │
                      └──────────────▲────────────────┘
                                     │
                                     │ implements
                                     │
                      ┌───────────────────────────────┐
                      │        UserSession            │ <<Concrete Prototype>>
                      ├───────────────────────────────┤
                      │ - username                    │
                      │ - token                       │
                      │ - deviceId                    │
                      │ - ipAddress                   │
                      │ - roles: List<String>         │
                      ├───────────────────────────────┤
                      │ + clone(): UserSession        │
                      └───────────────────────────────┘

                               Client
     ┌────────────────────────────────────────────────────────────┐
     │ UserSession original = new UserSession(...);                │
     │ UserSession cloned = original.clone();                      │
     │ cloned.setIpAddress("new-ip");                              │
     └────────────────────────────────────────────────────────────┘





```

🔍 When Prototype Pattern makes sense
-------------------------------------

| Good Fit                                             | Not a Good Fit                  |
| ---------------------------------------------------- | ------------------------------- |
| Object creation is slow / complex                    | Object is simple                |
| Needs partial modification                           | Values always differ completely |
| Object has many nested attributes                    | Object is primitive             |
| System needs runtime object creation without factory | No cloning requirement          |



🌟 Advantages
-------------

| Benefit                   | Explanation                                      |
| ------------------------- | ------------------------------------------------ |
| Faster object creation    | Cloning avoids recalculating / reloading         |
| Reduces memory & CPU cost | No repeated expensive operations                 |
| Runtime flexibility       | New prototype instances can be added dynamically |
| Avoids subclass explosion | Reduces need for multiple factories              |



⚠ Disadvantages
---------------

| Drawback                        | Reason                                          |
| ------------------------------- | ----------------------------------------------- |
| Deep copy is tricky             | Nested mutable objects must be cloned carefully |
| Requires careful design         | If object has circular references               |
| Cloning may break encapsulation | If exposed incorrectly                          |




🏢 Where Prototype Is Used in Real Systems
------------------------------------------

| Domain                 | Usage                                         |
| ---------------------- | --------------------------------------------- |
| Video games            | Clone characters / NPC templates              |
| Banking                | Clone risk profiles, loan products            |
| Authentication systems | Clone user session / security metadata        |
| AI/ML                  | Clone model config / inference context        |
| Game dev engines       | Scene, power-up, weapon templates             |
| Web frameworks         | Copy HTTP request context for multi-threading |



🚀 30-Second Interview Summary
------------------------------

> Prototype Pattern creates new objects by cloning an existing one instead of building from scratch. Useful when object creation is expensive. It supports shallow or deep copy, and allows runtime object duplication without knowing the exact class type. Common in authentication, gaming, and ML systems.
