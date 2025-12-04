**DRY Principle (Don’t Repeat Yourself)**
=========================================

**Definition:**The DRY principle states that **every piece of knowledge or logic should exist in a single, unambiguous place in the codebase**.

Simply put:

> **Avoid duplicate logic → put it in one reusable location.**

✅ **Why DRY Is Important**
==========================

### **1\. Reduces Bugs**

If logic is duplicated, you must fix bugs in multiple places.

Example: Password validation repeated in 5 classes → if rules change, you must update everywhere.

### **2\. Improves Maintainability**

When you update logic in ONE place → whole system gets updated.

### **3\. Improves Readability**

Shared logic kept in one class makes the system predictable and cleaner.

### **4\. Reduces Code Size**

Less code = less complexity = fewer errors.

➕ When Should You Use DRY?
==========================

Use DRY when:

### **1\. The logic is repeated across multiple modules**

e.g., email validation repeated inside login, signup, forgot password.

### **2\. The logic is stable & not changing frequently**

e.g., hashing algorithm, JWT token generator.

### **3\. The shared logic truly belongs to a common abstraction**

e.g., AuthUtils, PasswordHasher, ValidationService.

### **4\. You want a clean architecture**

Reusable components help with scaling and testing.

➖ When NOT to Use DRY
=====================

Avoid DRY when:

### ❌ **1\. Forcing DRY adds unnecessary coupling**

Example: login, signup, OTP verification all use slightly different validation.Forcing them into one function can make code confusing.

### ❌ **2\. Early-stage development (premature optimization)**

If a feature is new and unstable, don't over-abstract immediately.

Prototype first → DRY later when patterns emerge.

### ❌ **3\. Copying is simpler for one-off edge cases**

Do not create a common class for logic that won’t be reused later.

### ❌ **4\. Replacement of simple code with over-engineered DRY abstractions**

Making 10 small interfaces and utilities for the sake of DRY → BAD.

🔥 DRY Principle Using Login Flow Example
=========================================

❌ **Bad Code (Repeating Logic in Multiple Places)**
---------------------------------------------------

### Email validation duplicated everywhere:

```java
class LoginService {
      public boolean login(String email, String password) {
          if (!email.contains("@")) return false;
          // login logic ...
         return true;
      }
  }
  class SignupService {
      public boolean signup(String email, String password) {
          if (!email.contains("@")) return false;
          // signup logic ...
          return true;
      }
  }
  class ForgotPasswordService {
      public boolean reset(String email) {
          if (!email.contains("@")) return false;
          // reset logic ...
          return true;
      }
  }
```

🔴 Problems:

*   Email validation copy-pasted in 3 places
    
*   If rule changes (e.g., regex added), must update everywhere
    
*   Easy to forget updating one file → bugs in production
    

✅ **Good Code (Applying DRY)**
------------------------------

Extract duplicate validation logic:

```   
class EmailValidator {
      public static boolean isValid(String email) {
          return email != null && email.matches("^[^@]+@[^@]+\\.[^@]+$");
      }
  }
```

Now use this in all flows:

```   
class LoginService {
      public boolean login(String email, String password) {
          if (!EmailValidator.isValid(email)) return false;
          // login logic
          return true;
      }
  }
  class SignupService {
      public boolean signup(String email, String password) {
          if (!EmailValidator.isValid(email)) return false;
          // signup logic
          return true;
      }
  }
  class ForgotPasswordService {
      public boolean reset(String email) {
          if (!EmailValidator.isValid(email)) return false;
          // reset logic
          return true;
      }
  }
```

🔥 Benefits:

*   Email rule updated in **one place**
    
*   All flows follow same validation
    
*   Easier testing
    
*   Consistency across system
    

✔ DRY Applied to Password Hashing (Login Example)
=================================================

Before DRY:

```java
String hashed = sha256(password);
```

Repeated in 4–5 different places.

After DRY:

```java   
class PasswordHasher {
      public String hash(String password) {
          // bcrypt or Argon2 logic
      }
  }
```

❗ Example of When NOT to Use DRY in Login Flow
==============================================

Let’s say:

*   Login needs simple password validation
    
*   Signup needs strong password validation (uppercase, digits, special chars)
    
*   Change Password needs even stricter rules
    

If we force DRY:

```java
class PasswordValidator {
      public boolean validate(String pass, int level) { ... }
 }
```

This becomes confusing, overloaded & complex.

Better to have separate validators:

```java
class LoginPasswordValidator { ... }
class SignupPasswordValidator { ... }
class ChangePasswordValidator { ... }
```

➡ **Don’t DRY when the logic** _**looks similar**_ **but isn’t actually the same use case.**

🎯 Summary
==========

**DRY — “Don’t Repeat Yourself”** means **avoid duplicating logic**.

In a login system, instead of repeating email validation in Login, Signup, and Forgot Password, we put it in a single EmailValidator class.This ensures **consistency**, makes updates easier, and reduces bugs.

⚠ But don’t force DRY. If rules differ slightly—like password strength in Signup vs Change Password—keep them separate to avoid over-complicating code.

> **Key:** Reuse logic where it’s truly the same; otherwise, keep flows independent.
