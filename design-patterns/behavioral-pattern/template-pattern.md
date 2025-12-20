🧩 Template Method Pattern — Complete Explanation
=================================================

📌 Intent
---------

Define the **skeleton of an algorithm** in a base class, **deferring some steps to subclasses**.

> Template Method lets subclasses redefine **steps**, not the **overall algorithm**.

1️⃣ One-Line Definition (Interview Ready)
-----------------------------------------

> Template Method defines the structure of an algorithm once and allows subclasses to customize individual steps without changing the algorithm flow.

2️⃣ Real-World Analogy
----------------------

🍳 **Cooking Recipe**

*   Recipe steps are fixed:
    
    1.  Prepare ingredients
        
    2.  Cook
        
    3.  Serve
        

But:

*   Pasta recipe changes ingredients
    
*   Soup recipe changes ingredients
    

**Recipe = Template Method****Ingredients = Overridable steps**

3️⃣ Enterprise Login Example (Why Template?)
--------------------------------------------

All login flows follow the **same structure**:

1.  Validate request
    
2.  Authenticate
    
3.  Post-login actions
    
4.  Audit
    

But authentication differs:

*   Password
    
*   OTP
    
*   OAuth
    

👉 **Flow stays same, steps vary**

4️⃣ UML Diagram — Template Method (Login Example)
-------------------------------------------------

```pgsql
                ┌──────────────────────┐
                │ AbstractLoginFlow   │
                ├──────────────────────┤
                │ + login() (template)│
                │ - validate()        │
                │ - authenticate()*  │ (abstract)
                │ - postLogin()      │
                └─────────▲──────────┘
                          |
        ┌─────────────────┼─────────────────┐
        |                                   |
┌────────────────────┐        ┌────────────────────┐
│ PasswordLoginFlow  │        │ OtpLoginFlow       │
└────────────────────┘        └────────────────────┘

```


5️⃣ Java Implementation
-----------------------

### **Abstract Class (Template)**

```java
public abstract class AbstractLoginFlow {

    // Template method (final to prevent override)
    public final void login(String user) {
        validate(user);
        authenticate(user);
        postLogin(user);
        audit(user);
    }

    protected void validate(String user) {
        System.out.println("Validating request for " + user);
    }

    protected abstract void authenticate(String user);

    protected void postLogin(String user) {
        System.out.println("Post-login actions");
    }

    protected void audit(String user) {
        System.out.println("Audit log created");
    }
}

```


### **Concrete Implementations**

```java
public class PasswordLoginFlow extends AbstractLoginFlow {
    @Override
    protected void authenticate(String user) {
        System.out.println("Authenticating using password");
    }
}

public class OtpLoginFlow extends AbstractLoginFlow {
    @Override
    protected void authenticate(String user) {
        System.out.println("Authenticating using OTP");
    }
}
```


### **Client Code**

```java
public class Main {
    public static void main(String[] args) {

        AbstractLoginFlow login =
                new PasswordLoginFlow();
        login.login("anshi");

        System.out.println("-----");

        login = new OtpLoginFlow();
        login.login("anshi");
    }
}
```


6️⃣ Output
----------

```pgsql
Validating request for anshi
Authenticating using password
Post-login actions
Audit log created
-----
Validating request for anshi
Authenticating using OTP
Post-login actions
Audit log created
```


7️⃣ Template Method vs Strategy (🔥 VERY IMPORTANT)
---------------------------------------------------

| Aspect              | Template Method | Strategy   |
| ------------------- | --------------- | ---------- |
| Pattern type        | Behavioral      | Behavioral |
| Uses inheritance    | ✅ Yes           | ❌ No       |
| Uses composition    | ❌ No            | ✅ Yes      |
| Algorithm structure | Fixed           | Flexible   |
| Step customization  | Subclass        | Runtime    |
| Runtime switching   | ❌ No            | ✅ Yes      |



8️⃣ Simple Decision Rule
------------------------

Ask yourself:

👉 **Is the algorithm structure fixed?**→ **Template Method**

👉 **Do I want to switch behavior at runtime?**→ **Strategy**

9️⃣ Can They Be Used Together? (Yes!)
-------------------------------------

Very common in enterprise systems:

*   Template defines flow
    
*   Strategy handles a variable step
    

```java
authenticate() {
    authStrategy.authenticate();
}
```


This is **high-quality design**.

🔟 Pros and Cons
----------------

### ✅ Pros

*   Eliminates duplication
    
*   Enforces consistent workflow
    
*   Clear separation of steps
    

### ❌ Cons

*   Inheritance coupling
    
*   Harder to change algorithm structure
    
*   Less flexible than Strategy
    

🧠 Interview One-Liner (Perfect)
--------------------------------

> Template Method Pattern defines the skeleton of an algorithm in a base class and allows subclasses to customize specific steps without changing the overall flow.

❌ Common Interview Mistake
--------------------------

❌ “Template Method is same as Strategy”✔ **No** — Template uses inheritance, Strategy uses composition.
