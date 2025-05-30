# Patrei

Patrei is a programming language that has **micro-modular compute fabric** at its foundation. Every function compiles to an isolated WASM module. Instead of monolithic binaries, which esentially act as black boxes, programs become thousands of composable, verifiable modules running in parallel across CPUs, GPUs, and AI inference engines. There is no limit to the size of the programs but the number of machines you have.

It's not a specific tool, this is a long awaited change to the software side of engineering, and it can be used generally for anything.

## Core Principles

1. **Pure Functions as Modules**: Every function is deterministic and isolated
2. **Declarative Dataflow**: Data flows between modules explicitly  
3. **Static Validation**: All interfaces verified at compile time
4. **Massive Parallelism**: Thousands of modules execute concurrently
5. **Safety by Design**: Impossible to have data races or undefined behavior

## Syntax

```patrei
// Each function becomes a WASM module
fun validate_email(email) {
    email.has("@") && email.has(".")
}

fun process_user(user) -> int {
    {
        id: user.id,
        email: validate_email(user.email),
        score: calc_score(user.activity)
    }
}

// AI inference module  
fun classify_image(image) {
    ai.classify(image, "resnet50")
}
```
