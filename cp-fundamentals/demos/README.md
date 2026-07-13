# CP-Fundamental — Demos

> Internal facilitator notes. Not intended as a participant handout.

Instructor demos for the **GitHub Copilot Fundamentals** deck. Each demo maps to a **Demo Time**
slide and to an agenda section. Every folder has a **`demo.md`** (mode, model, exact prompts, steps,
expected result) plus one **sample code file** you complete live with Copilot.

> **One language per demo.** Instead of five parallel files, each demo uses the *single* language
> that shows the feature most clearly. Across the four demos this covers all five languages:
> **Demo 1 = Python, Demo 2 = C++, Demo 3 = Java, Demo 4 = C# → converted to Flutter/Dart.**
> The same prompts work in any language — swap the sample file if your audience prefers another.

## Demo → agenda map

| Demo | Agenda section | Language | Feature focus |
|---|---|---|---|
| [demo-1-copilot-overview](demo-1-copilot-overview/demo.md) | GitHub Copilot overview | **Python** | Copilot Overview, **AI Assistance in Action**, Real-world Use Cases (ghost text) |
| [demo-2-getting-started](demo-2-getting-started/demo.md) | Getting started in your IDE | **C++** | Code completions (**ghost text, inline chat, quick chat, NES**), chat modes (**Ask, Plan**), shortcuts (**/ and #**) |
| [demo-3-effective-prompts](demo-3-effective-prompts/demo.md) | Getting started / prompting | **Java** | Crafting good prompts, **@ and # references**, iterative refinement |
| [demo-4-tips-and-techniques](demo-4-tips-and-techniques/demo.md) | Tips and techniques | **C# → Flutter/Dart** | Commands & context, refactoring, documentation, **multilingual (convert code)**, tests, MCP (intro) |

## Scope — Fundamentals only

These demos stay on **everyday, single-developer** features. Demo 4 gives a **light, one-prompt
taste** of refactoring, tests, and MCP so the audience knows they exist — the **deep dive
(Agent mode, MCP servers, unit-test generation, refactoring, optimization) is the Intermediate
course**, not here.

## Which model / which mode (quick reference)

| Feature | Mode in VS Code | Recommended model |
|---|---|---|
| Ghost text / code completions | Inline (just type) | Completion model (automatic) |
| Next Edit Suggestions (NES) | Inline (Tab to jump) | Completion model (automatic) |
| Inline chat | **Ctrl+I** in the editor | GPT-4.1 (fast base model) |
| Quick chat | **Ctrl+Shift+I** | GPT-4.1 |
| Ask mode | Chat panel → **Ask** | GPT-4.1 |
| Plan mode | Chat panel → **Plan** | A reasoning model (e.g. GPT-5 / Claude Sonnet 4.5) — optional; GPT-4.1 is fine |
| Edit (refactor / convert / docs) | Chat panel → **Edit** | GPT-4.1 |

> Model names are a guide — pick any *base* model for everyday tasks and a *reasoning* model when
> you want more careful planning. Enable **Next Edit Suggestions** first:
> Settings → search `github.copilot.nextEditSuggestions.enabled` → **On**.

## Keyboard shortcuts used

| Action | Windows / Linux |
|---|---|
| Accept ghost text | **Tab** |
| Dismiss suggestion | **Esc** |
| Next / previous suggestion | **Alt+]** / **Alt+[** |
| Accept word only | **Ctrl+→** |
| Inline chat | **Ctrl+I** |
| Quick chat | **Ctrl+Shift+I** |
| Open Chat view | **Ctrl+Alt+I** |

## Run the sample code

| Demo | Language | Command |
|---|---|---|
| Demo 1 | Python | `python orders.py` |
| Demo 2 | C++ | `g++ -std=c++17 tip_calculator.cpp -o tip && ./tip` |
| Demo 3 | Java | `javac Catalog.java && java Catalog` |
| Demo 4 | C# | `dotnet run` (Inventory.cs as Program.cs) |
| Demo 4 (after convert) | Flutter/Dart | `dart run inventory.dart` |
