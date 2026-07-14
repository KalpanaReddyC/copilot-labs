---
title: Guided Demos
nav_order: 4
has_children: true
description: "Four presenter-led walkthroughs with complete runnable code embedded on each page."
---

# 🎬 Guided Demos
{: .no_toc }

Presenter-led walkthroughs, one per Copilot skill area. **Every demo page contains the full
starter code inline** — copy it into a file named as shown, follow the steps, and run.
A collapsible **solution** is included on each page so you can verify or unblock instantly.

{: .highlight }
> **No clone required.** Copy the code straight from the page. If you'd rather clone,
> the same files live in `cp-fundamentals/demos/` in the repo.

## Demo map

| Demo | Area | Language | File to create |
|---|---|---|---|
| [Demo 1 — Copilot overview](demo-1) | Ghost text / completions | Python | `orders.py` |
| [Demo 2 — Getting started in your IDE](demo-2) | Inline chat, NES, Ask, Plan, `/` commands | C++ | `tip_calculator.cpp` |
| [Demo 3 — Writing effective prompts](demo-3) | Prompt crafting, `@`/`#` refs, refinement | Java | `Catalog.java` |
| [Demo 4 — Tips and techniques](demo-4) | Refactor, docs, convert, `/tests`, MCP intro | C# → Dart | `Inventory.cs` |

## Which model / which mode (quick reference)

| Feature | Mode in VS Code | Recommended model |
|---|---|---|
| Ghost text / completions | Inline (just type) | Completion model (automatic) |
| Next Edit Suggestions (NES) | Inline (Tab to jump) | Completion model (automatic) |
| Inline chat | **Ctrl+I** in the editor | GPT-5.4 (fast base model) |
| Quick chat | **Ctrl+Shift+I** | GPT-5.4 |
| Ask mode | Chat panel → **Ask** | GPT-5.4 |
| Plan mode | Chat panel → **Plan** | A reasoning model (optional; GPT-5.4 is fine) |
| Edit (refactor / convert / docs) | Chat panel → **Edit** | GPT-5.4 |

{: .note }
> Enable **Next Edit Suggestions** first: Settings → search
> `github.copilot.nextEditSuggestions.enabled` → **On**.
