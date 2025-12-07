UML Diagram — Singleton + Abstract Factory + Factory Method (Login Service)
---------------------------------------------------------------------------

```pgsql

                    ┌────────────────────────────┐
                    │        LoginService        │ <<interface / Product>>
                    ├────────────────────────────┤
                    │ + login(username, password)│
                    └──────────────▲─────────────┘
                                   │
        ┌──────────────────────────┴─────────────────────────┐
        │                                                    │
┌─────────────────────────────┐                  ┌─────────────────────────────┐
│      EmailLoginService      │                  │     GoogleLoginService      │
├─────────────────────────────┤                  ├─────────────────────────────┤
│ + login(username, password) │                  │ + login(username, password) │
└─────────────────────────────┘                  └─────────────────────────────┘

┌─────────────────────────────┐                  ┌─────────────────────────────┐
│     MobileEmailLogin        │                  │   MobileGoogleLogin         │
├─────────────────────────────┤                  ├─────────────────────────────┤
│ + login(username, password) │                  │ + login(username, password) │
└─────────────────────────────┘                  └─────────────────────────────┘

                     ┌────────────────────────────┐
                     │       LoginFactory         │ <<Abstract Factory>>
                     ├────────────────────────────┤
                     │ + createEmailLogin()       │
                     │ + createGoogleLogin()      │
                     └──────────────▲─────────────┘
                                    │
              ┌─────────────────────┴─────────────────────┐
              │                                           │
┌─────────────────────────────┐                  ┌─────────────────────────────┐
│     WebLoginFactory         │ <<Singleton>>     │     MobileLoginFactory      │ <<Singleton>>
├─────────────────────────────┤                  ├─────────────────────────────┤
│ - instance: WebLoginFactory │                  │ - instance: MobileLoginFactory │
│ - WebLoginFactory()         │                  │ - MobileLoginFactory()      │
│ + getInstance(): WebLoginFactory │             │ + getInstance(): MobileLoginFactory │
│ + createEmailLogin()        │ <<Factory Method>>│ + createEmailLogin()        │ <<Factory Method>>
│ + createGoogleLogin()       │ <<Factory Method>>│ + createGoogleLogin()       │ <<Factory Method>>
└─────────────────────────────┘                  └─────────────────────────────┘

                           Client
┌──────────────────────────────────────────────────────────┐
│ LoginFactory factory = WebLoginFactory.getInstance();     │
│ LoginService emailLogin = factory.createEmailLogin();     │
│ LoginService googleLogin = factory.createGoogleLogin();  │
│ emailLogin.login("anshi", "pwd123");                     │
│ googleLogin.login("anshi", "pwd123");                    │
└──────────────────────────────────────────────────────────┘



```


### 🔹 Explanation

1.  **LoginService (Product Interface):** Defines a common interface for all login services.
    
2.  **Concrete Products:** Platform-specific and login-type-specific services (EmailLoginService, GoogleLoginService, MobileEmailLogin, etc.).
    
3.  **Abstract Factory (LoginFactory):** Declares creation methods for the family of login services (createEmailLogin(), createGoogleLogin()).
    
4.  **Concrete Factories (WebLoginFactory, MobileLoginFactory):**
    
    *   **Singleton:** Only one factory instance per platform (getInstance()).
        
    *   **Factory Method:** Each factory implements the methods to create specific login services.
        
5.  **Client:**
    
    *   Accesses the singleton factory (getInstance()).
        
    *   Uses factory methods to obtain platform-specific login services without knowing concrete classes.
        

### 🔹 Benefits of This Combined Pattern

| Benefit                         | Explanation                                                         |
| ------------------------------- | ------------------------------------------------------------------- |
| **Controlled Factory Instance** | Singleton ensures only one factory per platform exists.             |
| **Consistent Product Family**   | Each factory creates a family of login services that work together. |
| **Flexible Object Creation**    | Factory methods allow dynamic creation of products.                 |
| **Client Decoupling**           | Client is independent of concrete factories and products.           |
| **Extensible**                  | New platforms or login types can be added easily.                   |



### 🔹 Key Points for Interviews

*   **Singleton:** Ensures one instance of the factory exists.
    
*   **Abstract Factory:** Creates a family of related login services.
    
*   **Factory Method:** Each method in the factory decides which concrete product to instantiate.
    
*   **Use Case:** Large-scale apps supporting multiple platforms and login types with centralized management.
