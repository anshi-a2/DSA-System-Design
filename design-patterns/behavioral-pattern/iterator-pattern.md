🔁 Iterator Pattern — Full Explanation
======================================

📌 Intent
---------

Provide a way to **access elements of a collection sequentially** **without exposing its internal structure**.

> Iterator lets you traverse a collection **without knowing how it is implemented**.

1\. **Real-World Analogy**
==========================

Think of a **TV remote**:

*   You press **Next / Previous**
    
*   You don’t care how channels are stored (array, cable feed, satellite)
    

Remote = **Iterator**Channels = **Collection**

2\. **Login / Enterprise Example (Why Iterator?)**
==================================================

Suppose after login you must evaluate **multiple access policies**:

*   RolePolicy
    
*   LocationPolicy
    
*   DevicePolicy
    
*   TimeBasedPolicy
    

You want to:

*   Traverse policies one by one
    
*   Without exposing how they are stored (List, Set, DB cursor)
    

Iterator pattern solves this cleanly.

3\. **UML Diagram — Iterator Pattern (Policy Example)**
=======================================================

```pgsql

                    Client
                       |
                       ▼
                ┌──────────────────┐
                │    Iterator      │ <<interface>>
                ├──────────────────┤
                │ + hasNext()      │
                │ + next()         │
                └────────▲─────────┘
                         |
        ┌────────────────┼────────────────┐
        │                                   │
┌──────────────────────┐          ┌──────────────────────┐
│ PolicyIterator       │          │ PolicyCollection     │
├──────────────────────┤          ├──────────────────────┤
│ + hasNext()          │          │ + iterator()         │
│ + next()             │          │ - policies[]         │
└──────────────────────┘          └──────────────────────┘

```


4\. **Java Implementation**
===========================

**Iterator Interface**
----------------------

```java
public interface Iterator<T> {
    boolean hasNext();
    T next();
}

```

**Element**
-----------

```java
public interface Policy {
    boolean evaluate(String user);
}
```


**Concrete Elements**
---------------------

```java
public class RolePolicy implements Policy {
    @Override
    public boolean evaluate(String user) {
        System.out.println("Role policy checked");
        return true;
    }
}

public class LocationPolicy implements Policy {
    @Override
    public boolean evaluate(String user) {
        System.out.println("Location policy checked");
        return true;
    }
}
```



**Aggregate (Collection)**
--------------------------

```java
import java.util.List;

public class PolicyCollection {
    private final List<Policy> policies;

    public PolicyCollection(List<Policy> policies) {
        this.policies = policies;
    }

    public Iterator<Policy> iterator() {
        return new PolicyIterator(policies);
    }
}
```


**Concrete Iterator**
---------------------

```java
import java.util.List;

public class PolicyIterator implements Iterator<Policy> {

    private final List<Policy> policies;
    private int index = 0;

    public PolicyIterator(List<Policy> policies) {
        this.policies = policies;
    }

    @Override
    public boolean hasNext() {
        return index < policies.size();
    }

    @Override
    public Policy next() {
        return policies.get(index++);
    }
}

```



**Client Code**
---------------

```java
public class Main {
    public static void main(String[] args) {

        PolicyCollection collection = new PolicyCollection(
                List.of(new RolePolicy(), new LocationPolicy())
        );

        Iterator<Policy> iterator = collection.iterator();

        while (iterator.hasNext()) {
            iterator.next().evaluate("anshi");
        }
    }
}
```



5\. **Program Output**
======================

```pgsql
Role policy checked
Location policy checked

```


6\. **Where Iterator Pattern Is Used in Real Systems**
======================================================

### ✔ Java Collections

*   Iterator
    
*   ListIterator
    
*   Enhanced for-each
    

### ✔ Database Cursors

*   Row-by-row processing
    

### ✔ File Readers

*   Line-by-line iteration
    

### ✔ Message Processing

*   Kafka consumers
    
*   Event streams
    

### ✔ Security Pipelines

*   Policy chains
    
*   Validation steps
    

7\. **Iterator vs Related Patterns**
====================================

| Pattern                     | Key Difference                |
| --------------------------- | ----------------------------- |
| **Iterator**                | Traversal                     |
| **Composite**               | Tree structure                |
| **Chain of Responsibility** | Pass request until handled    |
| **Visitor**                 | Add behavior during traversal |



8\. **Pros and Cons**
=====================

### ⭐ Pros

*   Hides internal data structure
    
*   Single responsibility (traversal logic separated)
    
*   Supports multiple traversal strategies
    
*   Simplifies client code
    

### ❌ Cons

*   Extra classes
    
*   Overkill for simple collections
    
*   Can be inefficient if poorly implemented
    

9\. **30-Second Interview Summary**
===================================

> Iterator Pattern provides a uniform way to traverse elements of a collection without exposing its internal structure. It decouples traversal logic from the collection and is heavily used in Java collections, streams, and enterprise pipelines.
