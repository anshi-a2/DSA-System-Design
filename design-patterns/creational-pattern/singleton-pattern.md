Singleton Design Pattern — Login Service Example
------------------------------------------------

### What is the Singleton Pattern?

The Singleton pattern ensures **only one instance of a class exists throughout the application** and provides a **global access point** to it.

### Why Singleton for Login Service?

A login/authentication module manages:

*   User authentication
    
*   Token / session handling
    
*   Validation
    

If multiple instances exist, it may lead to:

*   Conflicting session states
    
*   Inconsistent authentication
    
*   Higher memory usage
    

So, a **single shared LoginService instance** improves consistency and control.

Basic Example — Lazy Initialization Singleton (Login Service)
-------------------------------------------------------------

```java
public class LoginService {
      private static LoginService instance;
      private LoginService() {}
      public static synchronized LoginService getInstance() {
          if (instance == null) {
              instance = new LoginService();
          }
          return instance;
      }
      public boolean login(String username, String password) {
          System.out.println("User authenticated: " + username);
          return true;
      }
  }
   ```

Different Styles of Singleton Implementation
--------------------------------------------

### 1\. Eager Initialization (Simple)

Instance is created at class loading time.

```java
public class LoginService {
      private static final LoginService instance = new LoginService();
      private LoginService() {}
      public static LoginService getInstance() {
          return instance;
      }
  }
   ```

**Pros:** Simple, thread-safe**Cons:** Instance is created even if never used

### 2\. Lazy Initialization (Not Thread-Safe)

Instance is created only when needed.

```java
public class LoginService {
      private static LoginService instance;
      private LoginService() {}
      public static LoginService getInstance() {
          if (instance == null) instance = new LoginService();
          return instance;
      }
  }
   ```

**Pros:** Saves memory**Cons:** Unsafe in multithreading

### 3\. Lazy Initialization — Thread-Safe (Synchronized)

```java
public class LoginService {
      private static LoginService instance;
      private LoginService() {}
      public static synchronized LoginService getInstance() {
          if (instance == null) instance = new LoginService();
          return instance;
      }
  }
   ```

**Pros:** Safe for multithreading**Cons:** Synchronization slows performance

### 4\. Double-Checked Locking (High Performance)

```java   
public class LoginService {
      private static volatile LoginService instance;
      private LoginService() {}
      public static LoginService getInstance() {
          if (instance == null) {
              synchronized (LoginService.class) {
                  if (instance == null) instance = new LoginService();
              }
          }
          return instance;
      }
  }
   ```

**Pros:** Thread-safe + fast**Cons:** Slightly complex

### 5\. Bill Pugh Inner Static Helper Class (Most Recommended)

```java
public class LoginService {
      private LoginService() {}
      private static class Helper {
          private static final LoginService INSTANCE = new LoginService();
      }
      public static LoginService getInstance() {
          return Helper.INSTANCE;
      }
  }
```

**Pros:** Thread-safe, no synchronization penalty, clean code**Cons:** None major (ideal in most cases)

### 6\. Enum-based Singleton (Most Secure)

```java
public enum LoginService {
      INSTANCE;
      public boolean login(String username, String password) {
          System.out.println("User authenticated: " + username);
          return true;
      }
  }
   ```

**Pros:** Thread-safe, prevents reflection attacks, auto handles serialization**Cons:** Cannot inherit classes

UML DAIGRAM (LOGIN SERVICE) :
-----------------------

                    ┌────────────────────────────┐
                    │       LoginService         │  <<Singleton>>
                    ├────────────────────────────┤
                    │ - instance: LoginService   │  <<static>>
                    │ - LoginService()           │  <<private>>
                    ├────────────────────────────┤
                    │ + getInstance(): LoginService │
                    │ + login(username, password)  │
                    └──────────────▲─────────────┘
                                   │
                                   │ single global instance
                                   ▼
                        ┌─────────────────────────┐
                        │       Client Code       │
                        ├─────────────────────────┤
                        │ loginService = LoginService.getInstance() │
                        │ loginService.login("anshi", "pwd")        │
                        └─────────────────────────┘


Advantages of Singleton
-----------------------

*   Controlled shared resource (single authentication manager)
    
*   Memory efficient (only one instance)
    
*   Global access from anywhere
    
*   Consistent logic and state
    

Disadvantages of Singleton
--------------------------

*   Hard to unit test (difficult to mock/replace)
    
*   Hidden dependencies (global state)
    
*   Tight coupling between classes
    
*   Needs careful handling in multithreaded applications
    

When to Use Singleton for Login Service
---------------------------------------

**Use when:**

*   You want a central authentication controller
    
*   Session/token store is global
    
*   Object creation is heavy (DB/API auth)
    

**Avoid when:**

*   Each user/session requires independent instance
    
*   Unit tests need isolated copies



### ✅ Practical Use Cases of Singleton Strategy

#### 1\. **Database Connection Manager**

Only one connection pool should be created to:

*   Avoid excessive DB connections
    
*   Improve performance and resource management
    

_(Most ORMs internally use Singleton for connection pooling)_

#### 2\. **Logger / Audit Service**

A logging service must be globally accessible and consistent across modules:

*   Avoid multiple log files
    
*   Ensure synchronized logging
    

#### 3\. **Configuration / Properties Manager**

Loading config from a file or server should happen once:

*   Same configuration shared system-wide
    
*   Avoid reloading values repeatedly
    

#### 4\. **Cache Manager**

Application-level caching (like Redis, in-memory map) needs single access point:

*   Prevent cache inconsistency
    
*   Reduce memory duplication
    

#### 5\. **Thread Pool Manager**

Thread pools are expensive to create and must be centrally managed:

*   Prevent unlimited threads creation
    
*   Keep resources stable
    

#### 6\. **API/Service Client Instance**

External API clients (e.g., AWS client, Payment Gateway client, SMTP client)

*   Maintain one instance for performance
    
*   Use shared authentication and session state
    

#### 7\. **Application State Manager / Session Context**

Used in UI frameworks and web apps to track:

*   Logged in user details
    
*   Active session tokens
    
*   Selected global theme or preferences
    

#### 8\. **File System / Resource Manager**

Shared access to files, IO resources, and disk operations must be synchronized:

*   Prevent conflicts and file corruption
    

#### 9\. **Analytics & Telemetry Service**

Sending events to analytics providers:

*   Single instance batches and sends events
    
*   Efficient network usage
    

#### 10\. **Game Engine Controllers (in gaming)**

Examples:

*   Game score tracker
    
*   Global sound manager
    
*   Level/world controller

    

### 🔥 Summary You Can Use in Interviews

Singleton is used when:

*   **Only one instance should exist**
    
*   **Instance is expensive to create**
    
*   **Data/state must be shared across the application**
    
*   **Global access to an object makes sense**
