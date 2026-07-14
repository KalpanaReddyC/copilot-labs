<h1 align="center">🛠️ Demo 4 — Tips and Techniques</h1>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C%23-239120?style=for-the-badge&logo=csharp&logoColor=white" alt="C#" />
  <img src="https://img.shields.io/badge/Convert-Flutter%2FDart-02569B?style=for-the-badge&logo=flutter&logoColor=white" alt="Flutter/Dart" />
  <img src="https://img.shields.io/badge/Focus-Tips%20%26%20Techniques-607D8B?style=for-the-badge" alt="Tips and Techniques" />
</p>

<hr>

**Agenda section:** Tips and techniques

**Covers:** Commands & Context · Refactoring · Documentation · **Multilingual (Convert code)** ·
Tests · Integrating & using an MCP server *(intro only)*

**Language:** **C#** → converted to **Flutter/Dart**  ·  **File:** [Inventory.cs](Inventory.cs)

---

## Setup

| Setting | Value |
|---|---|
| **Modes shown** | **Edit** / **Inline chat** (refactor, docs, convert), **Ask** (explain), `/tests` slash command, `#`/`@` context |
| **Model** | GPT-5.4 for everything here |
| **File** | `Inventory.cs` (a small, working class — 4 methods, all PASS) |

---

## Step 1 — Commands & context

Show the two building blocks before using them:

- Type `/` in Chat — the **command menu** appears (`/tests`, `/explain`, `/fix`, …).
- Type `#` — the **context picker** appears. Attach three different scopes:
  ```
  Using #Inventory.cs, list every method and its one-line purpose.
  ```
  ```
  Explain #NeedsReorder and when it returns true.
  ```
  (Select `ReorderQuantity` first, then:) `Explain #selection like I'm new to the codebase.`

---

## Step 2 — Documentation (Inline chat)

**Where:** select the whole `ReorderQuantity` method → press **Ctrl+I** (or Edit mode) → type:
```
Add an XML documentation comment above ReorderQuantity: a <summary> plus <param> and <returns>, explaining the par-level rule.
```

---

## Step 3 — Refactoring (Edit mode) — two quick wins

**3a · `ReorderReport` → LINQ:**
```
Refactor ReorderReport to use LINQ (Where + Select). Keep the behavior and return value identical.
```

**3b · `TotalUnitsToOrder` → LINQ:**
```
Refactor TotalUnitsToOrder to a single LINQ Sum(...) over ReorderQuantity. Do not change the result.
```

Re-run (`dotnet run`) — still `ALL PASS`. Point made: **refactoring changes shape, not behavior**,
and the checks prove it.

---

## Step 4 — Multilingual: convert to Flutter/Dart (Edit mode)

**Type this prompt:**
```
Convert this code to Flutter/Dart code named inventory.dart. Keep the same class shape, method names, and logic for all four methods, and include a main() that prints the same checks.
```
Save the output as `inventory.dart`. Show the same intent in another language — produced in seconds.

---

## Step 5 — Tests *(intro only)* (`/tests`)

**Where:** select `ReorderQuantity` → Chat → run:
```
/tests
```
---

## Run

```bash
# C# (inside a dotnet console project, Inventory.cs as Program.cs):
dotnet run

# after the convert step:
dart run inventory.dart
```

Expected C# output:

```
NeedsReorder    : PASS
ReorderReport   : PASS
ReorderQuantity : PASS
TotalUnitsOrder : PASS
ALL PASS
```
