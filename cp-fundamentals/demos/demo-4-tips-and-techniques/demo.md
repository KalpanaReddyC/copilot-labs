# Demo 4 - Tips and Techniques

Language: C# (with conversion to Flutter/Dart)
File: Inventory.cs

## Setup

1. Open Inventory.cs.
2. Use Edit/Inline chat for refactor and conversion prompts.
3. Use Ask mode for concept and context prompts.

## Execution prompts

1. Context prompts:

```text
Using #Inventory.cs, list every method and its one-line purpose.
```

```text
Explain #NeedsReorder and when it returns true.
```

```text
Explain #selection like I'm new to the codebase.
```

2. Documentation prompt:

```text
Add an XML documentation comment above ReorderQuantity: a <summary> plus <param> and <returns>, explaining the par-level rule.
```

3. Refactor prompts:

```text
Refactor ReorderReport in #Inventory.cs to use LINQ (Where + Select). Keep the behavior and return value identical.
```

```text
Refactor TotalUnitsToOrder in #Inventory.cs to a single LINQ Sum(...) over ReorderQuantity. Do not change the result.
```

4. Convert prompt:

```text
Convert #Inventory.cs to equivalent Flutter/Dart code named inventory.dart. Keep the same class shape, method names, and logic for all four methods, and include a main() that prints the same checks.
```

5. Tests command:

```text
/tests
```

6. MCP concept prompt:

```text
In one paragraph, what is an MCP server and what would it let GitHub Copilot do that it can't do with just my open files? Keep it high level — no setup steps.
```

## Run

```bash
dotnet run
```

After conversion:

```bash
dart run inventory.dart
```

Expected: all checks print PASS.
