<h1 align="center">🎬 CP Fundamentals — Demos</h1>

<p align="center">
  <img src="https://img.shields.io/badge/GitHub%20Copilot-000000?style=for-the-badge&logo=githubcopilot&logoColor=white" alt="GitHub Copilot" />
  <img src="https://img.shields.io/badge/Type-Demos-8A2BE2?style=for-the-badge&logo=vlcmediaplayer&logoColor=white" alt="Demos" />
  <img src="https://img.shields.io/badge/Editor-VS%20Code-007ACC?style=for-the-badge&logo=visualstudiocode&logoColor=white" alt="VS Code" />
</p>

<hr>

Participant execution guide for demo examples used in fundamentals labs.

## Demo map

| Demo | Area | Language | File |
|---|---|---|---|
| [demo-1-copilot-overview](demo-1-copilot-overview/demo.md) | Copilot overview | Python | demo-1-copilot-overview/orders.py |
| [demo-2-getting-started](demo-2-getting-started/demo.md) | IDE basics | C++ | demo-2-getting-started/tip_calculator.cpp |
| [demo-3-effective-prompts](demo-3-effective-prompts/demo.md) | Prompting | Java | demo-3-effective-prompts/Catalog.java |
| [demo-4-tips-and-techniques](demo-4-tips-and-techniques/demo.md) | Tips and techniques | C# to Flutter/Dart | demo-4-tips-and-techniques/Inventory.cs |


## Which model / which mode (quick reference)

| Feature | Mode in VS Code | Recommended model |
|---|---|---|
| Ghost text / code completions | Inline (just type) | Completion model (automatic) |
| Next Edit Suggestions (NES) | Inline (Tab to jump) | Completion model (automatic) |
| Inline chat | **Ctrl+I** in the editor | GPT-5.4 (fast base model) |
| Quick chat | **Ctrl+Shift+I** | GPT-5.4 |
| Ask mode | Chat panel → **Ask** | GPT-5.4 |
| Plan mode | Chat panel → **Plan** | A reasoning model (e.g. GPT-5 / Claude Sonnet 4.5) — optional; GPT-5.4 is fine |
| Edit (refactor / convert / docs) | Chat panel → **Edit** | GPT-5.4 |

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
| Demo 3 | JavaScript | `node catalog.js` |
| Demo 4 | C# | `dotnet run` (Inventory.cs as Program.cs) |
| Demo 4 (after convert) | Flutter/Dart | `dart run inventory.dart` |
