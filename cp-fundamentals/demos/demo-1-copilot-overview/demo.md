<p align="center">
  <img src="../../../assets/infomagnus-banner.svg" alt="InfoMagnus" height="56" />
</p>

<h1 align="center">🐍 Demo 1 — GitHub Copilot Overview</h1>

<p align="center">
  <img src="https://img.shields.io/badge/Language-Python-3776AB?style=for-the-badge&logo=python&logoColor=white" alt="Python" />
  <img src="https://img.shields.io/badge/Mode-Ghost%20Text-000000?style=for-the-badge&logo=githubcopilot&logoColor=white" alt="Ghost Text" />
  <img src="https://img.shields.io/badge/Difficulty-Beginner-4CAF50?style=for-the-badge" alt="Beginner" />
</p>

<hr>

**Agenda section:** GitHub Copilot overview

**Covers:** Copilot Overview · **AI Assistance in Action**.

**Language:** Python  ·  **File:** [orders.py](orders.py)

The goal is to complete the 5 stubbed functions in `orders.py` using **ghost text** (inline suggestions) — no chat panel needed.
---

## Setup

| Setting | Value |
|---|---|
| **Mode** | Inline **ghost text** (just type — no chat panel needed) |
| **Model** | Completion model (automatic — nothing to select) |
| **File** | `orders.py` |
| **Prep** | Open `orders.py`, make sure Copilot is signed in (status-bar icon is solid, not struck-through). Run it once — everything is `FAIL` until you fill the functions in. |

---

## Prompts to type

For each function: **delete the `pass` line**, put the cursor on the empty indented line, then type
the seed below and **pause** (don't keep typing). Grey ghost text completes the rest — press **Tab**.

| Function | Delete this | Type this seed (and pause) | Ghost text should complete to |
|---|---|---|---|
| `order_total` | the `pass  # ghost text ...` line | `    ret` | `return sum(i["price"] * i["qty"] for i in items)` |
| `loyalty_discount` | the `pass  # ...` line | `    ret` | `return subtotal * DISCOUNT_RATE / 100 if subtotal >= DISCOUNT_THRESHOLD else 0.0` |
| `apply_tax` | the `pass  # ...` line | `    ret` | `return amount + amount * rate / 100` |
| `receipt_line` | the `pass  # ...` line | `    ret` | `return f"{item['name']}   x{item['qty']}   ${item['price'] * item['qty']:.2f}"` (three literal spaces as separators — e.g. `Mechanical Keyboard   x2   $90.00`) |
| `grand_total` | the `pass  # ...` line | `    sub` | subtotal − discount, then `apply_tax(..., TAX_RATE)` |

> **`receipt_line` — exact spacing matters:** its self-check compares against a fixed string, so use
> **three literal spaces** as separators — not `:<20` column padding. Target:
> `f"{item['name']}   x{item['qty']}   ${item['price'] * item['qty']:.2f}"`. Padding to a width
> (e.g. `:<20`) makes the gap depend on the name length and FAILs for `Mechanical Keyboard`
> (19 chars → only 2 spaces, so you get `Mechanical Keyboard  x2` instead of `Mechanical Keyboard   x2`).
> If ghost text suggests a padded version adjust it to use literal spaces.


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
