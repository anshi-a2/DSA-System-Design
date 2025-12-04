📌 Overview
-----------

This document explains how OOPS concepts and SOLID principles are applied to a **Login/Authentication System** that supports multiple login types:

*   Email/Password
    
*   OTP
    
*   Google OAuth
    
*   GitHub OAuth
    
*   More methods can be added easily
    

The design is extensible, testable, and production-ready.

🧠 **OOPS Concepts Used**
=========================

**1\. Abstraction**
-------------------

We define a simple interface:

```java
public interface Authenticator {      boolean authenticate(String userId, String secret);  }
```

Clients only know **what** the system does, not **how** authentication works internally.

**2\. Encapsulation**
---------------------

Each authenticator hides its own internal login logic.

```java
public class PasswordAuthenticator implements Authenticator {
@Override
  public boolean authenticate(String userId, String password) {
          // hashing + verification inside
          return true;
      }
  }
```

Sensitive operations (password hashing, token validation) remain private.

**3\. Inheritance**
-------------------

All authentication methods share the same base interface.

```java
public class OTPAuthenticator implements Authenticator {
   ...
}

public class GoogleOAuthAuthenticator implements Authenticator {
 ...
}
```

They inherit the same contract.

**4\. Polymorphism**
--------------------

At runtime, the system picks the appropriate authenticator dynamically:

```java
Authenticator auth = AuthenticatorFactory.getAuthMethod(type);
 auth.authenticate(userId, secret);
```

The same function behaves differently for each login type.

🧩 **SOLID Principles Applied**
===============================

**S — Single Responsibility Principle (SRP)**
---------------------------------------------

Each class does **one job**.

| Class                      | Responsibility          |
| -------------------------- | ----------------------- |
| `PasswordAuthenticator`    | Validate password login |
| `OTPAuthenticator`         | Validate OTP login      |
| `GoogleOAuthAuthenticator` | Validate Google login   |
| `LoginService`             | Orchestrate login flow  |
| `UserAttemptTracker`       | Track failed attempts   |
| `NotificationService`      | Send login alerts       |

**O — Open/Closed Principle (OCP)**
-----------------------------------

New login methods can be added **without changing any existing code**.

Add a class:

Plain textANTLR4BashCC#CSSCoffeeScriptCMakeDartDjangoDockerEJSErlangGitGoGraphQLGroovyHTMLJavaJavaScriptJSONJSXKotlinLaTeXLessLuaMakefileMarkdownMATLABMarkupObjective-CPerlPHPPowerShell.propertiesProtocol BuffersPythonRRubySass (Sass)Sass (Scss)SchemeSQLShellSwiftSVGTSXTypeScriptWebAssemblyYAMLXML`   public class AppleAuthenticator implements Authenticator { ... }   `

No change in LoginService.

**L — Liskov Substitution Principle (LSP)**
-------------------------------------------

All authenticators must be interchangeable.

Authenticator interface guarantees a consistent behavior:

Plain textANTLR4BashCC#CSSCoffeeScriptCMakeDartDjangoDockerEJSErlangGitGoGraphQLGroovyHTMLJavaJavaScriptJSONJSXKotlinLaTeXLessLuaMakefileMarkdownMATLABMarkupObjective-CPerlPHPPowerShell.propertiesProtocol BuffersPythonRRubySass (Sass)Sass (Scss)SchemeSQLShellSwiftSVGTSXTypeScriptWebAssemblyYAMLXML`   Authenticator a = new PasswordAuthenticator();  Authenticator b = new GoogleOAuthAuthenticator();   `

Both work seamlessly with the same code.

**I — Interface Segregation Principle (ISP)**
---------------------------------------------

The interface has only **one responsibility**:

Plain textANTLR4BashCC#CSSCoffeeScriptCMakeDartDjangoDockerEJSErlangGitGoGraphQLGroovyHTMLJavaJavaScriptJSONJSXKotlinLaTeXLessLuaMakefileMarkdownMATLABMarkupObjective-CPerlPHPPowerShell.propertiesProtocol BuffersPythonRRubySass (Sass)Sass (Scss)SchemeSQLShellSwiftSVGTSXTypeScriptWebAssemblyYAMLXML`   boolean authenticate(String userId, String secret);   `

We don’t force classes to implement unused methods.

**D — Dependency Inversion Principle (DIP)**
--------------------------------------------

High-level modules depend on interfaces, not implementation.

Plain textANTLR4BashCC#CSSCoffeeScriptCMakeDartDjangoDockerEJSErlangGitGoGraphQLGroovyHTMLJavaJavaScriptJSONJSXKotlinLaTeXLessLuaMakefileMarkdownMATLABMarkupObjective-CPerlPHPPowerShell.propertiesProtocol BuffersPythonRRubySass (Sass)Sass (Scss)SchemeSQLShellSwiftSVGTSXTypeScriptWebAssemblyYAMLXML`   Authenticator auth = AuthenticatorFactory.getAuthMethod(method);   `

LoginService depends on the abstraction (Authenticator).

🧱 **Complete Code Example**
============================

**Authenticator Interface**
---------------------------

Plain textANTLR4BashCC#CSSCoffeeScriptCMakeDartDjangoDockerEJSErlangGitGoGraphQLGroovyHTMLJavaJavaScriptJSONJSXKotlinLaTeXLessLuaMakefileMarkdownMATLABMarkupObjective-CPerlPHPPowerShell.propertiesProtocol BuffersPythonRRubySass (Sass)Sass (Scss)SchemeSQLShellSwiftSVGTSXTypeScriptWebAssemblyYAMLXML`   public interface Authenticator {      boolean authenticate(String userId, String secret);  }   `

**Concrete Authenticators**
---------------------------

Plain textANTLR4BashCC#CSSCoffeeScriptCMakeDartDjangoDockerEJSErlangGitGoGraphQLGroovyHTMLJavaJavaScriptJSONJSXKotlinLaTeXLessLuaMakefileMarkdownMATLABMarkupObjective-CPerlPHPPowerShell.propertiesProtocol BuffersPythonRRubySass (Sass)Sass (Scss)SchemeSQLShellSwiftSVGTSXTypeScriptWebAssemblyYAMLXML`   public class PasswordAuthenticator implements Authenticator {      public boolean authenticate(String userId, String password) {          // verify hashed password          return true;      }  }  public class OTPAuthenticator implements Authenticator {      public boolean authenticate(String userId, String otp) {          // verify OTP          return true;      }  }  public class GoogleOAuthAuthenticator implements Authenticator {      public boolean authenticate(String userId, String token) {          // validate Google OAuth token          return true;      }  }   `

**Factory Pattern (OCP + DIP)**
-------------------------------

Plain textANTLR4BashCC#CSSCoffeeScriptCMakeDartDjangoDockerEJSErlangGitGoGraphQLGroovyHTMLJavaJavaScriptJSONJSXKotlinLaTeXLessLuaMakefileMarkdownMATLABMarkupObjective-CPerlPHPPowerShell.propertiesProtocol BuffersPythonRRubySass (Sass)Sass (Scss)SchemeSQLShellSwiftSVGTSXTypeScriptWebAssemblyYAMLXML`   public class AuthenticatorFactory {      public static Authenticator getAuthMethod(String type) {          return switch (type) {              case "PASSWORD" -> new PasswordAuthenticator();              case "OTP" -> new OTPAuthenticator();              case "GOOGLE" -> new GoogleOAuthAuthenticator();              default -> throw new IllegalArgumentException("Invalid type");          };      }  }   `

**Login Service**
-----------------

Plain textANTLR4BashCC#CSSCoffeeScriptCMakeDartDjangoDockerEJSErlangGitGoGraphQLGroovyHTMLJavaJavaScriptJSONJSXKotlinLaTeXLessLuaMakefileMarkdownMATLABMarkupObjective-CPerlPHPPowerShell.propertiesProtocol BuffersPythonRRubySass (Sass)Sass (Scss)SchemeSQLShellSwiftSVGTSXTypeScriptWebAssemblyYAMLXML`   public class LoginService {      private final UserAttemptTracker tracker = new UserAttemptTracker();      private final NotificationService notifier = new NotificationService();      public boolean login(String method, String userId, String secret) {          Authenticator auth = AuthenticatorFactory.getAuthMethod(method);          boolean success = auth.authenticate(userId, secret);          tracker.track(userId, success);          if (success) {              generateJWT(userId);          } else if (tracker.exceededLimit(userId)) {              notifier.sendAlert(userId);          }          return success;      }      private void generateJWT(String userId) {          // generate JWT logic      }  }   `

🎤 **Interview Summary (Copy-Paste)**
=====================================

> I designed a login module using OOPS + SOLID. Each login method implements a common Authenticator interface and follows SRP. The LoginService depends on this interface, not implementations, satisfying DIP. New login methods like Apple or GitHub OAuth can be added without modifying existing code, ensuring OCP. The interface exposes only required methods (ISP), and all authenticators can substitute each other without breaking functionality, following LSP.
