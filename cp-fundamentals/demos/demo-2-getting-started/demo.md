# Demo 2 — Getting Started in Your IDE

**Agenda section:** Getting started in your IDE

**Covers:** Code completions (**ghost text, inline chat, quick chat, Next Edit Suggestions**) ·

Copilot chat modes (**Plan mode, Ask mode**) · Keyboard shortcuts (**/ and # commands**)
**Language:** **C++**  ·  **File:** [tip_calculator.cpp](tip_calculator.cpp)
---

## Setup

| Setting | Value |
|---|---|
| **Modes shown** | Ghost text · **Inline chat** (Ctrl+I) · **NES** · **Quick chat** (Ctrl+Shift+I) · **Ask** · **Plan**  |
| **Model** | GPT-5.4 for chat / inline chat; completion model (automatic) for ghost text & NES |
| **File** | `tip_calculator.cpp` |
| **Prep** | Enable NES: Settings → search `github.copilot.nextEditSuggestions.enabled` → **On**. Have `g++` ready. Run once — several checks **FAIL** until you demo. |

---

## What We Are Building

In [tip_calculator.cpp](tip_calculator.cpp), you're building a small **tip calculator / bill summary program** that does four things:

1. Calculates a tip from an amount and percentage.
2. Splits the bill across people, including a zero-people safety check.
3. Applies loyalty discounts, service fees, and formatting.
4. Combines everything into a final `grand_total` and prints a short bill summary.

---

## Step 1 — Ghost text (complete `calculate_tip`)

**Where:** in the editor, inside `calculate_tip`.
**Do:** delete `return 0.0; // let ghost text complete this`, then on the empty line type the seed and pause:

```cpp
    ret
```

Ghost text completes it to `return amount * percent / 100;`. Press **Tab**.

---

## Step 2 — Inline chat, Ctrl+I (edit in place)

Inline chat edits the code **where your cursor is**. Do all three — they get progressively harder.

### 2a · Guard `split_bill` (simple)

**Where:** click inside `split_bill`, press **Ctrl+I**.
**Type this prompt:**

```
Return 0 when people is zero or negative; otherwise split amount plus the tip evenly. Keep the signature the same.
```


### 2b · Implement `apply_discount` — tiered logic (harder)

**Where:** click inside `apply_discount`, press **Ctrl+I**.
**Type this prompt:**

```
Implement a loyalty discount on `amount` based on `loyalty_years`: 0 years = 0% off, 1-2 years = 5% off, 3-4 years = 10% off, 5 or more years = 15% off. Return the amount AFTER the discount. Use clean branching and keep the signature unchanged.
```

### 2c · Refactor a selection (bonus)

**Where:** **select** the body of `apply_discount`, press **Ctrl+I**.
**Type this prompt:**

```
Refactor this to use a lookup table or early returns so new tiers are easy to add later. Do not change the behavior.
```

---

## Step 3 — Next Edit Suggestions (Tab through predicted edits)

NES predicts the **next edit implied by your last one** — no prompt to type, just **Tab**.

### 3a · A rename that ripples across the file

**Where:** on the **definition** of `calculate_tip`, change the name to `tip_amount`.
**Do:** as you type the new name, NES lights up every call site — inside `split_bill`, `grand_total`,
and twice in `main`. Press **Tab** to jump to and accept each one; watch it walk you through all five
edits in order.


### 3b · Predict a repetitive edit

**Where:** in `main`, inside the `----- Bill Summary -----` block, click at the end of the
`Service fee` line and press **Enter**.
**Do:** type one new line for the discount:

```cpp
        std::cout << "Discount    : " << format_currency(apply_discount(bill, 3)) << "\n";
```

The moment you finish it, NES predicts the **next** line in the same pattern — a `Grand total` line
using `grand_total(...)`. Press **Tab** to accept it. You wrote one line; NES inferred its sibling.


---

## Step 4 — Quick chat, Ctrl+Shift+Alt+L (fast code question, no edit)

**Where:** press **Ctrl+Shift+I** (a floating one-off chat).
**Type this prompt (about the code you're in):**

```
In this tip calculator, what edge cases could make grand_total return a wrong or surprising value? Think negative amounts, huge loyalty_years, and floating-point rounding on money. Answer briefly.
```

You get a focused list of real risks (negative inputs, precision on currency, tier boundaries)
without touching the file — quick chat is for a fast answer you read and move on from.

Follow-up you can fire in the same quick chat:

 ```
 Which of those would you fix first, and why?
```

---

## Step 5 — Ask mode (explain, trace, compare — never edits)

Ask mode is read-only: it reasons about code but never changes it. Run all three so people see how
far it goes.

### 5a · Explain a selection

**Where:** **select** the whole `split_bill` function → open Chat → pick **Ask** mode.
**Type this prompt:**

```
Explain #selection step by step: what it computes, and how it handles zero or negative people.
```

### 5b · Trace the composition
**Where:** still in **Ask** mode.
**Type this prompt:**

```
Trace grand_total(200, 10, 3) call by call through #tip_calculator.cpp. Show the intermediate value after apply_discount, calculate_tip, and service_fee, then the final number.
```

Ask mode walks the math across functions — a strong "it actually understands the flow" moment.

### 5c · Compare and critique

**Where:** still in **Ask** mode.
**Type this prompt:**

```
Compare split_bill and grand_total in #tip_calculator.cpp: what does each include in the total, and when would each be the wrong function to call?
```

> Ask never writes to the file — for an applied change use inline chat or edit mode. Notice how
> `#selection`, `#file`, and a bare `#symbol` each scope the answer differently.

---

## Step 6 — Plan mode (outline before coding)

**Where:** Chat → switch to **Plan** mode.
**Type this prompt:**

```
Plan the steps to add a "round the per-person amount up to the nearest dollar" option to this tip calculator. List the steps only — do not write code yet.
```

You get an ordered plan and **no code** — good for scoping work before you let Copilot write it.

---

## Step 7 — `/` commands (shortcuts for common prompts)

Type `/` in Chat to open the command menu. Run all four so the menu isn't just theory.

### 7a · `/fix` the `service_fee` bug

**Where:** select the `service_fee` function → Chat → type `/`, pick `/fix`:

```
/fix service_fee returns a value 100x too small. It should be percent% of amount (e.g. 5% of 200 = 10.00). Fix it.
```

Apply the fix. The `service_fee` **and** `grand_total` checks turn green.

---

## Step 8 — Build & run (the payoff)

**Where:** terminal.


**Bash**
```bash
g++ -std=c++17 tip_calculator.cpp -o tip && ./tip
```

**Power shell**

```Powershell
g++ -std=c++17 tip_calculator.cpp -o tip; ./tip
```

Expected output:

```
calculate_tip  : PASS
split_bill     : PASS
guard          : PASS
service_fee    : PASS
format_currency: PASS
apply_discount : PASS
grand_total    : PASS

----- Bill Summary -----
Bill        : $200.00
Tip (10%) : $20.00
Service fee : $10.00
Per person  : $55.00
ALL PASS
```
