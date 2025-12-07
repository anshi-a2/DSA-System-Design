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
