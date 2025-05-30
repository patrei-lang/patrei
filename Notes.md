# Notes

Forget the tree. We want semantic-first, macro-aware, graph-based compilation — where meaning matters more than tokens.

It is a paradigm shift.

- The input syntax maps directly to semantic declarations: components, systems, entity types, flows
- You don’t care about token order as much as their relations
- The compiler immediately constructs a graph or ECS-style plan instead of a tree
- You enable parallel execution, distributed deployment, and hardware synthesis

This is closer to dataflow programming, semantic IRs, and AI knowledge graphs than to C-style imperative languages.

## No tokens

We're defining a semantically-driven system, where meaning, not syntax, drives the compiler. The semantics is then compiled to a graph or a scheduling plan — not a stack of tokens.

We are not doing imperative control flow, we are not running anything line by line. This is a completely different paradigm.

In defining semantics you say:

- This system depends on that component
- This data flows into that transformation
- These parts are independent, schedule them in parallel
Rather than producing a parse tree or abstract syntax tree (AST), we directly generate a dependency graph or task graph.
