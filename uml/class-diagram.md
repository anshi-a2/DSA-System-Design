UML Class Diagram
=================

A **UML Class Diagram** represents the **static structure** of a system:

*   What classes exist
    
*   What data they hold
    
*   What behavior they expose
    
*   How they relate to each other
    

It does **NOT** show runtime flow (that’s sequence diagrams).

1️⃣ Class Box Structure
-----------------------

A UML class is shown as a rectangle with **3 sections**:

```pgsql
┌─────────────────────┐
│   ClassName         │   ← Class name
├─────────────────────┤
│ - field1 : Type     │   ← Attributes
│ + field2 : Type     │
├─────────────────────┤
│ + method(): Return  │   ← Methods
│ - helper(): void    │
└─────────────────────┘
```


### Sections Explained

### 🔹 Class Name (Top)

*   Name of the class or interface
    
*   Abstract classes → _italic_
    
*   Interfaces → <\>
    

### 🔹 Attributes / Fields (Middle)

Format:

```pgsql
visibility name : type
```


Example:

```pgsql
- next : Handler
```


#### Visibility Symbols

| Symbol | Meaning   |
| ------ | --------- |
| `+`    | public    |
| `-`    | private   |
| `#`    | protected |
| `~`    | package   |



### 🔹 Methods / Operations (Bottom)

Format:

```pgsql
visibility methodName(param: Type) : ReturnType
```


Example:

```pgsql
+ handle(request: String) : boolean
```


2️⃣ Interfaces vs Abstract Classes
----------------------------------

### Interface

```pgsql
<<interface>>
LoginService
```


*   Only method declarations
    
*   No state (mostly)
    
*   Shown with <\>
    

### Abstract Class

*   May have fields + partial implementations
    
*   Name often italicized
    

3️⃣ Relationships Between Classes
---------------------------------

This is the **most important part** of UML.

### 🔹 Inheritance (IS-A)

```pgsql
Child ─────▷ Parent
```


*   Solid line + hollow triangle
    
*   Child **extends** parent
    

Example:

```pgsql
EmailLoginService ─────▷ LoginService
```

### 🔹 Interface Implementation

```pgsql
Class ─ ─ ─▷ Interface
```


*   Dashed line + hollow triangle
    
*   Class **implements** interface
    

### 🔹 Association (USES / KNOWS)

```pgsql
A ───────── B
```


*   One class uses or knows another
    
*   No ownership
    

Example:

```pgsql
Order ───────── Customer
```


### 🔹 Aggregation (HAS-A, weak)

``` pgsql
Whole ◇──────── Part
```
*   Hollow diamond
    
*   Part can exist independently
    

Example:

```pgsql
Team ◇──────── Player
```


### 🔹 Composition (HAS-A, strong)

```pgsql
Whole ◆──────── Part
```


*   Filled diamond
    
*   Part **cannot exist without whole**
    

Example:

```pgsql
House ◆──────── Room
```


### 🔹 Dependency (Temporary Use)

```pgsql
A - - - - > B
```

*   Method parameter or local variable
    
*   Weakest relationship
    

4️⃣ Multiplicity (Cardinality)
------------------------------

Shows **how many objects** are involved.

| Notation | Meaning     |
| -------- | ----------- |
| `1`      | Exactly one |
| `0..1`   | Optional    |
| `*`      | Many        |
| `1..*`   | One or more |


Example:

```pgsql
Order ─── 1..* ─── Item
```


5️⃣ Direction of Relationship
-----------------------------

Arrow direction shows:

*   Who **knows about** whom
    
*   Who depends on whom
    

Rule of thumb:

> Arrow points toward the **more abstract / stable** element

6️⃣ How to Explain Any UML Diagram in Interview (Step-by-Step)
--------------------------------------------------------------

When interviewer shows a diagram:

### Step 1: Identify Abstractions

*   Interfaces
    
*   Abstract classes
    

### Step 2: Identify Concrete Implementations

*   Classes extending or implementing
    

### Step 3: Explain Relationships

*   Inheritance
    
*   Composition
    
*   Dependency
    

### Step 4: Explain Responsibility Distribution

*   What each class is responsible for
    
*   Why separation exists
    

7️⃣ Common UML Mistakes (Interview Red Flags 🚨)
------------------------------------------------

❌ Confusing aggregation with composition❌ Missing visibility❌ Using inheritance where composition is better❌ No interfaces in extensible systems

8️⃣ Interview One-Liner (Very Useful)
-------------------------------------

> A UML class diagram shows the static structure of a system, including classes, their attributes, operations, and the relationships between them.
