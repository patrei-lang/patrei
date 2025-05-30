# Syntax Rules

## 1. Top-level Construct

Defines a Control Module with a UUID, attached data/logic modules, and orchestration policies.

```Patrei
control <Name> { ... }
```

Defines a Data Blob with structured fields or unstructured memory buffers.

```Patrei
data <Name> { ... }
```

Defines a stateless Logic Module with inputs, outputs, and triggers.

```Patrei
logic <Name> (...) -> <Type> { ... }
```

## 2. Annotations

Specifies an event that activates a module (e.g., "on_request", "on_timer").

```Patrei
@trigger("<event>")
```

Scheduling metadata (e.g., "priority=high", "interval=1s").

```Patrei
@schedule("<hint>")
```

Embeds a state machine or orchestration logic within a Control Module.

```Patrei
@policy
```

## 3. Types

Basic types: int, string, bool, float.

Composite types

```Patrei
struct { ... }

array[<Type>]

map[<KeyType>]<ValueType>
```

Reference types

```Patrei
data <Name> // (references a Data Blob by name)
```

## 4. Statements

Variable declarations

```Patrei
var <name> <type> [= <expr>]; 
<name> := <expr>;
```

Control flow

```Patrei
if <cond> { ... } else { ... }

for { ... }

return <expr>;
```

Module interactions

```Patrei
call <LogicModule>(<args>);

read <DataModule>.<field>;

write <DataModule>.<field> = <expr>;
```

## 5. Expressions

Operators: +, -, *, /, ==, !=, <, >, <=, >=, &&, ||, !.

Literals: Integers (123), floats (3.14), strings ("hello"), booleans (true, false).

Member access

```Patrei
<DataModule>.<field>
<struct>.<field>
```

## 6. Comments

Comments: // (single-line), /**/ (multi-line)

Example program:

```Patrei
// Control Module: Orchestrates authentication service
@trigger("on_request") @schedule("priority=high")
control AuthService {
    uuid = "123e4567-e89b-12d3-a456-426614174000";
    data = [UserData, SessionData];
    logic = [AuthCheck, LogAccess];
    policy = {
        var result := call AuthCheck(read UserData, read SessionData);
        if result {
            call LogAccess(read UserData);
        } else {
            return Unauthorized();
        }
    }
}

// Data Blob: User information
data UserData {
    id int;
    name string;
    uuid = "987fcdeb-1234-5678-9012-345678901234";
}

// Data Blob: Session information
data SessionData {
    token string;
    valid bool;
    uuid = "456fcdeb-1234-5678-9012-345678901456";
}

// Logic Module: Authentication check
@trigger("on_request")
logic AuthCheck(user UserData, sess SessionData) -> bool {
    if user.id > 0 && sess.valid {
        return true;
    }
    return false;
}

// Logic Module: Logging access
@trigger("on_access")
logic LogAccess(user UserData) {
    // Simulate logging
    var log := "Access by " + user.name;
}
```
