# Demo 2 — Getting Started in Your IDE  (Deck **Slide 32**)

**Agenda section:** Getting started in your IDE
**Covers:** Code completions (**ghost text, inline chat, quick chat, Next Edit Suggestions**) ·
Copilot chat modes (**Plan mode, Ask mode**) · Keyboard shortcuts (**/ and # commands**)
**Language:** **C++**  ·  **File:** [tip_calculator.cpp](tip_calculator.cpp)

C++ is used here because completions, inline-chat edits, a rename→NES jump, a `/fix` bug, and a
`/doc` target are all crisp and obvious in a statically-typed file. Every function below exists to
exercise **one specific Copilot surface** — so you can show them back-to-back.

---

## Setup

| Setting | Value |
|---|---|
| **Modes shown** | Ghost text · **Inline chat** (Ctrl+I) · **NES** · **Quick chat** (Ctrl+Shift+I) · **Ask** · **Plan** · `/fix` `/tests` `/explain` `/doc` · `#selection` `#<symbol>` `#file` |
| **Model** | GPT-4.1 for chat / inline chat; completion model (automatic) for ghost text & NES |
| **File** | `tip_calculator.cpp` |
| **Prep** | Enable NES: Settings → search `github.copilot.nextEditSuggestions.enabled` → **On**. Have `g++` ready. Run once — several checks **FAIL** until you demo. |

> **How to read this guide:** every step says **where** (which surface / shortcut), and gives the
> **exact text to type**. Text in a code block is what you paste into ghost text / inline chat / the
> chat box.

---

## Step 1 — Ghost text (complete `calculate_tip`)

**Where:** in the editor, inside `calculate_tip`.
**Do:** delete `return 0.0; // let ghost text complete this`, then on the empty line type the seed and pause:

```cpp
    ret
```

Ghost text completes it to `return amount * percent / 100;`. Press **Tab**.

> If it's slow, type `return a` and pause, or press **Alt+\\** to trigger a suggestion manually.

---

## Step 2 — Inline chat, Ctrl+I (edit in place)

Inline chat edits the code **where your cursor is**. Do all three — they get progressively harder.

### 2a · Guard `split_bill` (simple)

**Where:** click inside `split_bill`, press **Ctrl+I**.
**Type this prompt:**

```
Return 0 when people is zero or negative; otherwise split amount plus the tip evenly. Keep the signature the same.
```

Accept the diff. The `guard` check turns green.

### 2b · Implement `apply_discount` — tiered logic (harder)

**Where:** click inside `apply_discount`, press **Ctrl+I**.
**Type this prompt:**

```
Implement a loyalty discount on `amount` based on `loyalty_years`: 0 years = 0% off, 1-2 years = 5% off, 3-4 years = 10% off, 5 or more years = 15% off. Return the amount AFTER the discount. Use clean branching and keep the signature unchanged.
```

Copilot writes the whole multi-branch body from one sentence. Accept it — the `apply_discount` check
passes. This is the "wow" moment: a plain-English rule becomes real branching logic.

### 2c · Refactor a selection (bonus)

**Where:** **select** the body of `apply_discount`, press **Ctrl+I**.
**Type this prompt:**

```
Refactor this to use a lookup table or early returns so new tiers are easy to add later. Do not change the behavior.
```

Show the diff, then **Accept** or **Discard** — the point is inline chat can restructure a selection
without changing the result. Re-run the build to prove the checks still pass.

---

## Step 3 — Next Edit Suggestions (Tab through predicted edits)

NES predicts the **next edit implied by your last one** — no prompt to type, just **Tab**.

### 3a · A rename that ripples across the file

**Where:** on the **definition** of `calculate_tip`, change the name to `tip_amount`.
**Do:** as you type the new name, NES lights up every call site — inside `split_bill`, `grand_total`,
and twice in `main`. Press **Tab** to jump to and accept each one; watch it walk you through all five
edits in order.

> Rename it back to `calculate_tip` afterwards, or leave it — the checks still pass either way.

### 3b · Predict a repetitive edit

**Where:** in `main`, inside the `----- Bill Summary -----` block, click at the end of the
`Service fee` line and press **Enter**.
**Do:** type one new line for the discount:

```cpp
        std::cout << "Discount    : " << format_currency(apply_discount(bill, 3)) << "\n";
```

The moment you finish it, NES predicts the **next** line in the same pattern — a `Grand total` line
using `grand_total(...)`. Press **Tab** to accept it. You wrote one line; NES inferred its sibling.

> This is NES's superpower: after one structural edit it offers the *parallel* edit you'd type next.

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

### 5b · Trace the composition (harder)

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

### 7b · `/tests` for `grand_total`

**Where:** select `grand_total` → Chat → run:

```
/tests cover the loyalty tiers (0, 2, 4, 10 years), a zero amount, and a negative amount.
```

Copilot generates a test function. Read it, then drop it into a new file or discard it — the point is
`/tests` turns a selection into real test cases in seconds.

### 7c · `/explain` the trickiest function

**Where:** select `apply_discount` → Chat → run:

```
/explain
```

Copilot narrates the tiered logic in plain English — handy for reviewers or onboarding.

### 7d · `/doc` the `format_currency` function

**Where:** select `format_currency` → Chat → run:

```
/doc
```

Copilot adds a documentation comment above the function.

> `/` = **commands** (`/fix`, `/tests`, `/explain`, `/doc`) — fast paths for prompts you'd otherwise
> type by hand.

---

## Step 8 — `#` commands (attach the right context)

`#` pulls **context** into your prompt so Copilot answers about the exact thing you mean. Show three
scopes in Chat (Ask mode is fine):

### 8a · `#selection` — just the highlighted code

**Where:** select the body of `apply_discount` → Chat:

```
Are the tier boundaries in #selection correct and non-overlapping? Point out any off-by-one.
```

### 8b · `#<symbol>` — one named function anywhere in the file

**Where:** Chat (no selection needed):

```
What does #grand_total include that #split_bill does not?
```

### 8c · `#file` — the whole file

**Where:** Chat:

```
Give a one-paragraph overview of #tip_calculator.cpp and list every function with a one-line purpose.
```

> Also worth naming: `#codebase` (search the whole repo) and `#changes` (your pending edits).
> `/` runs an action; `#` supplies the context that action runs against.

---

## Step 9 — Build & run (the payoff)

**Where:** terminal.

```bash
g++ -std=c++17 tip_calculator.cpp -o tip && ./tip
```

Once every step is done you get `ALL PASS` plus a formatted **Bill Summary**.

---

## Quick reference — every surface & its prompt

| # | Surface | Shortcut / where | Exact prompt (or action) |
|---|---|---|---|
| 1 | Ghost text | type in editor | type `ret` and pause → **Tab** |
| 2a | Inline chat | **Ctrl+I** in `split_bill` | `Return 0 when people is zero or negative; otherwise split amount plus the tip evenly. Keep the signature the same.` |
| 2b | Inline chat (harder) | **Ctrl+I** in `apply_discount` | `Implement a loyalty discount on amount based on loyalty_years: 0y=0%, 1-2y=5%, 3-4y=10%, 5+y=15% ...` |
| 2c | Inline chat (refactor) | select body → **Ctrl+I** | `Refactor this to use a lookup table or early returns ... Do not change the behavior.` |
| 3a | NES rename | rename in editor → **Tab** | rename `calculate_tip` → `tip_amount`, Tab all 5 sites |
| 3b | NES predict | type one summary line | add a `Discount` line → **Tab** accepts the `Grand total` line |
| 4 | Quick chat | **Ctrl+Shift+I** | `In this tip calculator, what edge cases could make grand_total return a wrong value ...` |
| 5a | Ask + `#selection` | select code → Ask | `Explain #selection step by step ...` |
| 5b | Ask (trace) | Ask | `Trace grand_total(200, 10, 3) call by call through #tip_calculator.cpp ...` |
| 5c | Ask (compare) | Ask | `Compare split_bill and grand_total in #tip_calculator.cpp ...` |
| 6 | Plan | Chat → Plan | `Plan the steps to add a "round the per-person amount up to the nearest dollar" option ... steps only.` |
| 7a | `/fix` | select `service_fee` | `/fix service_fee returns a value 100x too small ...` |
| 7b | `/tests` | select `grand_total` | `/tests cover the loyalty tiers (0, 2, 4, 10 years), a zero amount, and a negative amount.` |
| 7c | `/explain` | select `apply_discount` | `/explain` |
| 7d | `/doc` | select `format_currency` | `/doc` |
| 8 | `#` context | Chat | `#selection`, `#grand_total`, `#file` scope the answer |

---

## Talking points

- **Ghost text** = passive suggestions as you type. **Inline chat (Ctrl+I)** = edit in place — from a
  one-line guard up to a full tiered-discount rule and a refactor. **Quick chat (Ctrl+Shift+I)** =
  fast one-off *code* question. **Ask** = explain, trace, and compare — never edits.
  **Plan** = outline the steps before writing code.
- **NES** predicts the *next* edit implied by your last one — a rename that ripples to all five call
  sites, or the parallel summary line you were about to type. Accept with **Tab**.
- `/` gives **commands** (`/fix`, `/tests`, `/explain`, `/doc`); `#` **attaches context**
  (`#selection`, `#<symbol>`, `#file`) so Copilot answers about the exact code you mean.

---

## Run

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
