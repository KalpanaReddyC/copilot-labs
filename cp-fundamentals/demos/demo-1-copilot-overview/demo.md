# Demo 1 - GitHub Copilot Overview

Language: Python
File: orders.py

## Setup

1. Open orders.py.
2. Use inline ghost text completions.
3. For each function body, delete the pass line, type the seed, pause, then press Tab to accept.

## Execution prompts

There is no chat prompt in this demo. The prompt is the comment above each function.

Type these seeds:

| Function | Seed |
|---|---|
| order_total | `ret` |
| loyalty_discount | `ret` |
| apply_tax | `ret` |
| receipt_line | `tot` or `ret` |
| grand_total | `sub` |

If suggestion is slow, type one more character and pause.

## Run

```bash
python orders.py
```

Expected: all checks print PASS.
