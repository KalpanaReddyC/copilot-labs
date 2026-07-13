# Demo 1 — GitHub Copilot Overview  (Deck **Slide 16**)

**Agenda section:** GitHub Copilot overview
**Covers:** Copilot Overview · **AI Assistance in Action** · Real-world Use Cases
**Language:** Python  ·  **File:** [orders.py](orders.py)

The goal of this first demo is the **"aha" moment** — the audience watches Copilot write real,
useful code from plain intent, and the payoff is a **fully formatted store receipt** printed by the
code Copilot just wrote. Keep it light: this is *seeing AI assistance in action*, not advanced
features.

---

## Setup

| Setting | Value |
|---|---|
| **Mode** | Inline **ghost text** (just type — no chat panel needed) |
| **Model** | Completion model (automatic — nothing to select) |
| **File** | `orders.py` |
| **Prep** | Open `orders.py`, make sure Copilot is signed in (status-bar icon is solid, not struck-through). Run it once — everything is `FAIL` until you fill the functions in. |

**The build-up:** five small functions are stubbed with `pass`. As you complete each one with ghost
text, you're building toward the finish — run the file and Copilot's code prints a boxed receipt with
subtotal, loyalty discount, tax, and total. That reveal is the eye-catching moment.

---

## Run the demo

| # | Feature | What you do | Expected result |
|---|---|---|---|
| 1 | **Ghost text** | Delete the `pass` under `order_total`, type `ret` (see seeds) and pause. | Grey inline code completes the function. Press **Tab**. |
| 2 | **Talk: AI in action** | Say: *"I described the intent in a comment — Copilot wrote the implementation."* | Audience sees the suggestion accepted. |
| 3 | **Cycle suggestions** | On `loyalty_discount`, type `ret` and press **Alt+]** / **Alt+[**. | Copilot offers alternatives (ternary vs if/else); pick one and **Tab**. |
| 4 | **Real-world use case** | Complete `apply_tax`, then `receipt_line` (note it follows the example in the comment). | A formatted receipt string is produced. |
| 5 | **Compose** | Complete `grand_total` — it *reuses* the functions above. | Show how Copilot chains your own helpers together. |
| 6 | **The reveal** | `python orders.py` | All 5 checks print `PASS`, then a **boxed receipt** prints. That's the wow. |

---

## Prompts to type

There is **no chat prompt** in this demo — the "prompt" is the **comment above each function**.
The comments are already in the file. **Ghost text can be slow to appear**, so the reliable way to
"wake it up" is to **delete the `pass` stub and start typing the first token** — the suggestion then
pops in almost instantly.

### Typing seeds — what to type to trigger ghost text

For each function: **delete the `pass` line**, put the cursor on the empty indented line, then type
the seed below and **pause** (don't keep typing). Grey ghost text completes the rest — press **Tab**.

| Function | Delete this | Type this seed (and pause) | Ghost text should complete to |
|---|---|---|---|
| `order_total` | the `pass  # ghost text ...` line | `    ret` | `return sum(i["price"] * i["qty"] for i in items)` |
| `loyalty_discount` | the `pass  # ...` line | `    ret` | `return subtotal * DISCOUNT_RATE / 100 if subtotal >= DISCOUNT_THRESHOLD else 0.0` |
| `apply_tax` | the `pass  # ...` line | `    ret` | `return amount + amount * rate / 100` |
| `receipt_line` | the `pass  # ...` line | `    tot` or `    ret` | a line like `Mechanical Keyboard   x2   $90.00` |
| `grand_total` | the `pass  # ...` line | `    sub` | subtotal − discount, then `apply_tax(..., TAX_RATE)` |

> **Tip:** if nothing appears after ~1 second, type one more character (e.g. `return s`) and pause
> again, or press **Alt+\\** to manually trigger an inline suggestion. Typing the seed is what
> "warms up" the completion — starting from a blank line with no keystrokes is the slowest case.

Example — the comment is the intent, the seed starts the line:

```python
# Return the subtotal: sum of price * qty for every item in the list
def order_total(items):
    ret        # <- type "ret" here and pause; ghost text fills in the rest
```

> If a completion produces a slightly different-but-correct formula, that's fine — the point is that
> Copilot writes working code from intent. The self-checks confirm the numbers.

---

## Talking points

- Copilot reads the **comment + function name + nearby constants** (`DISCOUNT_RATE`, `TAX_RATE`) to
  predict what you want — richer context, better suggestions.
- Grey text = a **suggestion**, not committed code. **Tab** accepts, **Esc** dismisses,
  **Alt+]/Alt+[** cycles alternatives.
- `grand_total` shows Copilot **composing your own functions** — not just single lines.
- This is the everyday, in-editor experience — "**AI assistance in action**" — before you ever open
  a chat window.

---

## Run

```bash
python orders.py
```

Expected output:

```
=== Self-checks ===
order_total     : PASS
loyalty_discount: PASS
apply_tax       : PASS
receipt_line    : PASS
grand_total     : PASS

ALL PASS - here's the receipt:

+--------------------------------------------+
|           InfoMagnus Tech Store            |
+--------------------------------------------+
| Mechanical Keyboard   x2   $90.00          |
| Wireless Mouse   x1   $25.00               |
| 4K Monitor   x1   $210.00                  |
| USB-C Cable   x4   $50.00                  |
+--------------------------------------------+
| Subtotal:  $                      375.00   |
| Discount: -$                       37.50   |
| Tax (8%):  $                       27.00   |
| TOTAL:     $                      364.50   |
+--------------------------------------------+
|      Thank you for shopping with us!       |
+--------------------------------------------+
```
