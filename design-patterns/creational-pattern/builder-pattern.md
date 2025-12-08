🔹 What is Builder Pattern?
---------------------------

Builder Pattern is a **creational design pattern** used when:

*   An object has **many optional parameters**, or
    
*   Object creation should be **step-by-step**, or
    
*   To avoid **telescoping constructors (too many constructor arguments)**.
    

Instead of passing 10 arguments in the constructor,Builder lets you build the object in a **readable, controlled, and flexible way**.

🔹 Login Service Example (Builder Pattern)
------------------------------------------

Let’s say we need to build a **LoginRequest object** that will be sent to the login API:

Required fields:

*   username
    
*   password
    

Optional fields:

*   deviceId
    
*   location
    
*   ipAddress
    
*   loginMethod (Email / Google / OTP etc.)
    
*   rememberMe
    
*   captchaToken
    

Creating this object with a constructor becomes messy:

```java
LoginRequest req = new LoginRequest(
      "anshi", "12345", null, null, null, "Email", false, null
  );
```

❌ Hard to read❌ If new fields are added, constructor keeps growing

### ✔ Using Builder Pattern

```java
LoginRequest req = LoginRequest.Builder()
          .username("anshi")
          .password("12345")
          .loginMethod("Email")
          .deviceId("93847hdfhs83")
          .rememberMe(true)
          .build();
```

Readable — and we set only what we need.


✅ Java Code — Builder Pattern (LoginRequest)
--------------------------------------------

```java
public class LoginRequest {
      // Required fields
      private final String username;
      private final String password;
      // Optional fields
      private final String deviceId;
      private final String location;
      private final String ipAddress;
      private final String loginMethod;
      private final boolean rememberMe;
      private final String captchaToken;

      // Private constructor - only Builder can create instances
      private LoginRequest(Builder builder) {
          this.username = builder.username;
          this.password = builder.password;
          this.deviceId = builder.deviceId;
          this.location = builder.location;
          this.ipAddress = builder.ipAddress;
          this.loginMethod = builder.loginMethod;
          this.rememberMe = builder.rememberMe;
          this.captchaToken = builder.captchaToken;
      }

      // Static nested Builder class
      public static class Builder {

          // Required fields
          private final String username;
          private final String password;

          // Optional fields
          private String deviceId;
          private String location;
          private String ipAddress;
          private String loginMethod;
          private boolean rememberMe;
          private String captchaToken;

          // Builder constructor with mandatory fields
          public Builder(String username, String password) {
              this.username = username;
              this.password = password;
          }

          // Setter-style builder methods for optional fields
          public Builder deviceId(String deviceId) {
              this.deviceId = deviceId;
              return this;
          }
          public Builder location(String location) {
              this.location = location;
              return this;
          }
          public Builder ipAddress(String ipAddress) {
              this.ipAddress = ipAddress;
              return this;
          }
          public Builder loginMethod(String loginMethod) {
              this.loginMethod = loginMethod;
              return this;
          }
          public Builder rememberMe(boolean rememberMe) {
              this.rememberMe = rememberMe;
              return this;
          }
          public Builder captchaToken(String captchaToken) {
              this.captchaToken = captchaToken;
              return this;
          }

          // Final build method
          public LoginRequest build() {
              return new LoginRequest(this);
          }
      }

      // Getters (optional)
      public String getUsername() { return username; }
      public String getPassword() { return password; }
      public String getDeviceId() { return deviceId; }
      public String getLocation() { return location; }
      public String getIpAddress() { return ipAddress; }
      public String getLoginMethod() { return loginMethod; }
      public boolean isRememberMe() { return rememberMe; }
      public String getCaptchaToken() { return captchaToken; }
  }
```

🔥 How to Use the Builder
-------------------------

```java
LoginRequest request = new LoginRequest.Builder("anshi", "12345")
          .loginMethod("Email")
          .deviceId("D8293HF833")
          .rememberMe(true)
          .build();
   ```

Only relevant fields are set — no overloaded constructors and no nulls.

⭐ Optional Validation Example (If Needed)
-----------------------------------------

(Typically asked in senior interviews)

```java
public LoginRequest build() {
      if (username == null || username.isEmpty()) {
          throw new IllegalStateException("username is required");
      }
      if (password == null || password.isEmpty()) {
          throw new IllegalStateException("password is required");
      }
      return new LoginRequest(this);
  }
 ```

🔹 Notes for Interview
----------------------

| Point                   | Benefit                                             |
| ----------------------- | --------------------------------------------------- |
| Enforces immutability   | All fields `private` + object created once          |
| Improves readability    | Chain methods instead of multi-argument constructor |
| Scales well             | New optional fields don’t break old code            |
| Works well with DTO/API | Especially for REST, GraphQL, microservices         |



🔹 Structure of Builder Pattern (Login Example)
-----------------------------------------------


| Component            | Responsibility                            |
| -------------------- | ----------------------------------------- |
| **Product**          | Object to be built — `LoginRequest`       |
| **Builder**          | Provides stepwise API to configure fields |
| **Concrete Builder** | Implements building logic                 |
| **build()**          | Finally creates the completed object      |
| **Client**           | Uses builder to construct object          |






🔹 UML Diagram — Builder Pattern (Login Request)
------------------------------------------------

```pgsql

                        ┌───────────────────────────────┐
                        │        LoginRequest           │ <<Product>>
                        ├───────────────────────────────┤
                        │ - username                    │
                        │ - password                    │
                        │ - deviceId                    │
                        │ - location                    │
                        │ - ipAddress                   │
                        │ - loginMethod                 │
                        │ - rememberMe                  │
                        │ - captchaToken                │
                        ├───────────────────────────────┤
                        │ + Builder                     │ <<static inner class>>
                        └──────────────▲────────────────┘
                                       │ builds
                                       │
                     ┌─────────────────┴──────────────────┐
                     │          Builder                    │
                     ├─────────────────────────────────────┤
                     │ - username                          │
                     │ - password                          │
                     │ - deviceId                          │
                     │ - location                          │
                     │ - ipAddress                         │
                     │ - loginMethod                       │
                     │ - rememberMe                        │
                     │ - captchaToken                      │
                     ├─────────────────────────────────────┤
                     │ + username()                        │
                     │ + password()                        │
                     │ + deviceId()                        │
                     │ + location()                        │
                     │ + loginMethod()                     │
                     │ + rememberMe()                      │
                     │ + captchaToken()                    │
                     │ + build(): LoginRequest             │
                     └─────────────────────────────────────┘

                                   Client
      ┌────────────────────────────────────────────────────────────────┐
      │ LoginRequest req = LoginRequest.Builder()                       │
      │         .username("anshi")                                      │
      │         .password("12345")                                      │
      │         .loginMethod("Email")                                   │
      │         .rememberMe(true)                                       │
      │         .build();                                               │
      └────────────────────────────────────────────────────────────────┘


```

🔹 Pros & Cons
--------------

| Pros                                 | Cons                                       |
| ------------------------------------ | ------------------------------------------ |
| Avoids telescoping constructors      | More classes / boilerplate                 |
| Readable stepwise object creation    | Must call `build()` else object incomplete |
| Helps create immutable objects       | Harder to use for very simple objects      |
| Only required fields can be enforced | —                                          |



🔹 Where Builder Pattern Is Used in Real Systems
------------------------------------------------

| Area                 | Example                                                     |
| -------------------- | ----------------------------------------------------------- |
| HTTP Calls           | Request building (`OkHttp`, `Retrofit`, `Spring WebClient`) |
| Database Queries     | MongoDB / JPA Criteria Query builder                        |
| Message Building     | Kafka message builder, Email builder                        |
| UI Construction      | Flutter / Jetpack Compose widget builder                    |
| Complex DTO creation | Request objects with optional fields                        |
| Cloud SDKs           | AWS S3, DynamoDB client builders                            |



🔹 Short Interview Summary (30 sec)
-----------------------------------

> Builder Pattern is used when an object has many optional parameters or needs step-by-step construction. It avoids telescoping constructors by providing a fluent builder interface. The final object is created using a build() method. It is widely used in HTTP requests, DTOs, and configuration-heavy objects.
