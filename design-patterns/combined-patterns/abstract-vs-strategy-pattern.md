This is a **very common interview question**, and the key is to explain it **clearly, with intent + example**, not just definitions.

Below is a **crisp but deep comparison**, using your **login service domain**, plus a **1-minute interview answer** at the end.

Core Difference (One Line)
--------------------------

*   **Factory Pattern** decides **which object to create**
    
*   **Strategy Pattern** decides **which behavior to use**
    

> Factory is about **object creation**Strategy is about **object execution**

Intent Comparison
-----------------

| Aspect           | Factory Pattern              | Strategy Pattern            |
| ---------------- | ---------------------------- | --------------------------- |
| Purpose          | Encapsulate object creation  | Encapsulate algorithms      |
| Focus            | *Which class to instantiate* | *Which behavior to execute* |
| Problem Solved   | Avoid `new` + conditionals   | Avoid `if-else` in logic    |
| When chosen      | At creation time             | At runtime                  |
| Returns          | A concrete object            | Executes behavior           |
| Change frequency | Less frequent                | More frequent               |


Login Example (Best Way to Explain)
-----------------------------------

### Factory Pattern – _Creation_

You don’t know **which login service to create**:

```java
LoginService service =
    LoginServiceFactory.create("OTP");
```

Factory decides:

*   PasswordLoginService
    
*   OtpLoginService
    
*   OAuthLoginService
    

👉 **Client does not know the concrete class**

### Strategy Pattern – _Behavior_

You already have a login context but want **different authentication behaviors**:

```java
loginContext.setStrategy(new OtpLoginStrategy());
loginContext.login("anshi");
```


👉 **Object stays same, behavior changes**

UML-Level Difference
--------------------

### Factory

```pgsql
Client → Factory → ConcreteObject
```


### Strategy

```pgsql
Client → Context → Strategy
```


Factory producesStrategy executes

Real-World Analogy
------------------

### Factory 🏭

Ordering food:

*   You say “Pizza”
    
*   Factory gives you Pizza object
    

You don’t cook it.

### Strategy 🧠

Eating food:

*   Fork
    
*   Spoon
    
*   Chopsticks
    

Same food, different strategy.

Can They Be Used Together? (Very Important)
-------------------------------------------

✅ **YES – very common in enterprise systems**

```java
LoginStrategy strategy =
    LoginStrategyFactory.getStrategy(type);
loginContext.setStrategy(strategy);
```


*   Factory chooses the strategy
    
*   Strategy executes the behavior
    

This combo is **interview gold**.

Pros & Cons Comparison
----------------------

### Factory Pattern

**Pros**

*   Centralized object creation
    
*   Loose coupling
    
*   Hides instantiation logic
    

**Cons**

*   More classes
    
*   Harder to extend without modification (unless abstract factory)
    

### Strategy Pattern

**Pros**

*   Runtime flexibility
    
*   Eliminates conditionals
    
*   Easy to extend
    

**Cons**

*   Many small classes
    
*   Client must choose strategy
    

Common Interview Traps ❌
------------------------

❌ “Strategy creates objects”✔ No — Strategy **executes behavior**

❌ “Factory replaces Strategy”✔ No — They solve **different problems**

❌ “Use Strategy for creation”✔ Wrong abstraction

30-Second Interview Answer (Memorize This)
------------------------------------------

> Factory Pattern is used to encapsulate object creation logic, deciding which concrete class to instantiate. Strategy Pattern is used to encapsulate interchangeable algorithms, allowing behavior to change at runtime. Factory focuses on _creation_, while Strategy focuses on _execution_. They are often used together in enterprise systems.

Quick Decision Rule
-------------------

Ask yourself:

👉 **“Do I need to decide** _**what to create**_**?”**→ Factory

👉 **“Do I need to decide** _**how to behave**_**?”**→ Strategy
