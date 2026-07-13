# Demo 4 — Tips and Techniques  (Deck **Slide 72**)

**Agenda section:** Tips and techniques
**Covers:** Commands & Context · Refactoring · Documentation · **Multilingual (Convert code)** ·
Tests · Integrating & using an MCP server *(intro only)*
**Language:** **C#** → converted to **Flutter/Dart**  ·  **File:** [Inventory.cs](Inventory.cs)

> **Fundamentals scope — light touch.** This demo *introduces* refactoring, documentation, tests,
> and MCP so the audience knows they exist. The **deep dive — Agent mode, MCP servers, unit-test
> generation, refactoring, and optimization — is the Intermediate course.** Keep each step to
> ~1 minute; do not go down a rabbit hole.

C# is the source here and the **convert step targets Flutter/Dart**, so this single demo also
covers the 5th language your list asked for. The class now has **four working methods**
(`NeedsReorder`, `ReorderQuantity`, `ReorderReport`, `TotalUnitsToOrder`) so each technique has a
real target — but it still ships **green**: run it first to show the passing baseline.

---

## Setup

| Setting | Value |
|---|---|
| **Modes shown** | **Edit** / **Inline chat** (refactor, docs, convert), **Ask** (explain), `/tests` slash command, `#`/`@` context |
| **Model** | GPT-4.1 for everything here |
| **File** | `Inventory.cs` (a small, working class — 4 methods, all PASS) |
| **Prep** | Have `Inventory.cs` open; run it once first so the room sees `ALL PASS`. |

> **Targets at a glance:** docs → `ReorderQuantity` · refactor → `ReorderReport` + `TotalUnitsToOrder`
> · `/tests` → `ReorderQuantity` · convert → the whole file.

---

## Run the demo

| # | Technique | Mode / command | What you do | Expected result |
|---|---|---|---|---|
| 0 | **Baseline** | Terminal | `dotnet run` before touching anything. | `ALL PASS` — proves the starting point works. |
| 1 | **Commands & context** | Chat | Type `/` (see commands); attach `#Inventory.cs`, `#selection`, `#NeedsReorder`. | The `/` menu and `#` context picker appear and scope the chat. |
| 2 | **Documentation** | **Inline chat** (Ctrl+I) | Select `ReorderQuantity`, ask for an XML doc comment. | An XML `<summary>` doc comment explains the par-level rule. |
| 3 | **Refactoring** | **Edit** | Send the two refactor prompts. | `ReorderReport` → LINQ `Where/Select`; `TotalUnitsToOrder` → LINQ `Sum` — behavior unchanged. |
| 4 | **Multilingual — convert** | **Edit** | Send the convert prompt; save output as `inventory.dart`. | Equivalent Flutter/Dart code with all four methods. |
| 5 | **Tests** *(intro)* | `/tests` | Select `ReorderQuantity`, run `/tests`. | Cases for needs-reorder, well-stocked (0), and the boundary. Say: *"deep dive in Intermediate."* |
| 6 | **MCP** *(intro)* | Ask | Ask the MCP question below. | A short explanation of what an MCP server adds — **concept only**, no setup. |
| 7 | **Re-run** | Terminal | `dotnet run` (and/or `dart run inventory.dart`). | Still `ALL PASS` — refactors kept behavior identical. |

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

> `/` = an **action**; `#` = the **context** that action runs against. Precise requests need both.

---

## Step 2 — Documentation (Inline chat)

**Where:** select the whole `ReorderQuantity` method → press **Ctrl+I** (or Edit mode) → type:
```
Add an XML documentation comment above ReorderQuantity: a <summary> plus <param> and <returns>, explaining the par-level rule.
```
Copilot adds an XML `<summary>` describing the **par-level rule** (order back up to `2 × ReorderAt`,
`0` when stocked). Good target because the rule isn't obvious from the signature alone.

> **Note:** `/doc` isn't a Copilot Chat slash command — ask for the doc comment in plain language
> instead. The built-in ones are `/tests`, `/fix`, and `/explain`.

---

## Step 3 — Refactoring (Edit mode) — two quick wins

**3a · `ReorderReport` → LINQ:**
```
Refactor ReorderReport in #Inventory.cs to use LINQ (Where + Select). Keep the behavior and return value identical.
```

**3b · `TotalUnitsToOrder` → LINQ:**
```
Refactor TotalUnitsToOrder in #Inventory.cs to a single LINQ Sum(...) over ReorderQuantity. Do not change the result.
```

Re-run (`dotnet run`) — still `ALL PASS`. Point made: **refactoring changes shape, not behavior**,
and the checks prove it.

---

## Step 4 — Multilingual: convert to Flutter/Dart (Edit mode)

**Type this prompt:**
```
Convert #Inventory.cs to equivalent Flutter/Dart code named inventory.dart. Keep the same class shape, method names, and logic for all four methods, and include a main() that prints the same checks.
```
Save the output as `inventory.dart`. Show the same intent in another language — produced in seconds.

---

## Step 5 — Tests *(intro only)* (`/tests`)

**Where:** select `ReorderQuantity` → Chat → run:
```
/tests
```
`ReorderQuantity` is a better test target than a plain boolean — it has three interesting cases:
needs reorder (returns a positive number), well-stocked (returns `0`), and the boundary
(`OnHand == ReorderAt`). Skim the generated cases, then say the line: **"full test generation is the
Intermediate course."**

---

## Step 6 — MCP *(intro, concept only)*

**Ask mode:**
```
In one paragraph, what is an MCP server and what would it let GitHub Copilot do that it can't do with just my open files? Keep it high level — no setup steps.
```
One paragraph, no setup. Just plant the concept — MCP is taught fully in **Agents & MCP**.

---

## Prompts to type (quick copy)

| Technique | Mode / cmd | Prompt |
|---|---|---|
| Doc | Inline chat | select `ReorderQuantity` → `Add an XML doc comment (<summary>/<param>/<returns>) explaining the par-level rule.` |
| Refactor 3a | Edit | `Refactor ReorderReport in #Inventory.cs to use LINQ (Where + Select). Keep behavior identical.` |
| Refactor 3b | Edit | `Refactor TotalUnitsToOrder in #Inventory.cs to a single LINQ Sum(...). Do not change the result.` |
| Convert | Edit | `Convert #Inventory.cs to Flutter/Dart named inventory.dart. Keep all four methods and a main() that prints the checks.` |
| Tests | `/tests` | select `ReorderQuantity` → `/tests` |
| MCP | Ask | `In one paragraph, what is an MCP server ... keep it high level — no setup steps.` |

---

## Talking points

- **`/` commands** (`/tests`, `/explain`, `/fix`) are shortcuts; **`#` references**
  (`#file`, `#selection`, `#symbol`) give Copilot the right context; **`@`** brings in participants
  like `@workspace`. Together they make requests precise.
- **Refactor twice, re-run once:** the green checks are the proof that behavior didn't drift — that's
  the safety net that makes AI refactoring trustworthy.
- **Convert** shows Copilot is **multilingual** — same intent, another language (C# → Dart), in seconds.
- Refactoring, test generation, and MCP are **previewed here** and **taught fully in Intermediate /
  Agents & MCP** — say that out loud so expectations are set.

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
