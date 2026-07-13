# Demo 3 — Writing Effective Prompts  (Deck **Slide 42**)

**Agenda section:** Getting started / prompting
**Covers:** Crafting Good Prompts · **Using @ and # References** · Iterative Refinement
**Language:** **Java**  ·  **File:** [Catalog.java](Catalog.java)

Java keeps this demo about *the prompt*, not the syntax. There are **five stubbed methods**, each one
teaching a different prompting move — so the audience watches a weak prompt, a strong prompt, and a
few refinements turn red checks green, one technique at a time.

---

## Setup

| Setting | Value |
|---|---|
| **Mode** | **Ask** mode (explain / discuss) and **Edit** / **Inline chat** (apply the change) |
| **Model** | GPT-4.1 |
| **File** | `Catalog.java` |
| **Prep** | Open `Catalog.java` so `#Catalog.java` and `#selection` resolve. JDK 16+ installed (uses `record`). Run once — every check **FAILs** until you demo. |

> **The five tasks** (all start FAIL):
> `inStockSorted` · `inStockUnder` · `cheapestInStock` · `inStockInventoryValue` · `inStockCsv`

---

## Run the demo

| # | Technique | Mode | Target method | Outcome |
|---|---|---|---|---|
| 1 | **Weak → strong prompt** | Edit | `inStockSorted` | Weak prompt flops; strong prompt (goal + inputs + outputs + constraints) passes. |
| 2 | **Iterative refinement** | Edit | `inStockUnder` | Start broad, then add the price cap and the sort in follow-ups. |
| 3 | **Constraints & edge cases** | Edit | `cheapestInStock` | Prompt forces `Optional` + the empty-stock case. |
| 4 | **Precision constraint** | Edit | `inStockInventoryValue` | Prompt pins the rounding rule (2 decimals). |
| 5 | **Exact output format** | Edit | `inStockCsv` | Prompt spells out the exact string shape. |
| 6 | **`#` references** | Ask | — | `#selection`, `#Catalog.java`, `#symbol` ground the answer. |
| 7 | **`@` references** | Ask | — | `@workspace`, `@vscode`, `@terminal` widen the context. |
| 8 | **Run** | Terminal | — | `javac Catalog.java && java Catalog` → `ALL PASS`. |

---

## Step 1 — Weak → strong prompt (`inStockSorted`)

**Where:** click inside `inStockSorted`, open Inline chat (**Ctrl+I**) or Edit mode.

**1a · Weak prompt (show the bad result first):**
```
can you sort the products in this file and make the list a bit nicer for me
```
It mutates the list, ignores stock, or sorts the wrong field. **Point out why** — no goal, no
inputs, no output shape, no constraints.

**1b · Strong prompt (goal + inputs + outputs + constraints + `#`):**
```
In #Catalog.java implement inStockSorted(): return a NEW list (do not mutate PRODUCTS) containing only products where inStock is true, sorted by price ascending, breaking ties on equal price by product name A→Z.
```
`sorted` turns green. Read the **anatomy** aloud:

> **Anatomy of a strong prompt** — *Goal* (implement `inStockSorted`) · *Inputs* (`PRODUCTS`) ·
> *Output* (a new list) · *Constraints* (in-stock only, price asc, tie by name, don't mutate) ·
> *Context* (`#Catalog.java`).

---

## Step 2 — Iterative refinement (`inStockUnder`)

You rarely nail it in one shot. Prompt in small steps and watch each refinement land.

**2a · First pass (intentionally broad):**
```
Implement inStockUnder(double maxPrice) in #Catalog.java to return in-stock products no more expensive than maxPrice.
```

**2b · Refine — pin the sort so it matches the others:**
```
Sort the result by price ascending, then by name A→Z, and return a new list without mutating PRODUCTS.
```

**2c · Refine — confirm the boundary:**
```
Make the cap inclusive: price <= maxPrice, not strictly less than.
```
`under_cap` turns green (the check calls `inStockUnder(30.0)` → only `Mouse`).

> Talking point: each message is short and *builds on the last* — that's cheaper and clearer than one
> giant prompt.

---

## Step 3 — Constraints & edge cases (`cheapestInStock`)

**Where:** inside `cheapestInStock`.
**Type this prompt:**
```
Implement cheapestInStock() in #Catalog.java to return an Optional<Product> holding the lowest-priced in-stock product. Return Optional.empty() when nothing is in stock — do not throw and do not return null.
```
`cheapest` turns green. The lesson: **naming the edge case in the prompt** (empty stock, no null, no
throw) is what separates robust output from a happy-path guess.

---

## Step 4 — Precision constraint (`inStockInventoryValue`)

**Where:** inside `inStockInventoryValue`.
**Type this prompt:**
```
Implement inStockInventoryValue() in #Catalog.java: sum the price of every in-stock product and round the result to exactly 2 decimal places. Return the rounded double.
```
`value` turns green (45 + 25 + 45 = **115.00**). Show that an unspecified "add up the prices" prompt
would leave rounding to chance — **constraints remove ambiguity.**

---

## Step 5 — Exact output format (`inStockCsv`)

**Where:** inside `inStockCsv`.
**Type this prompt (spell the format out precisely):**
```
Implement inStockCsv() in #Catalog.java. Using inStockSorted() order, join each product as "name:price" where price is formatted to exactly 2 decimals. Separate entries with commas and no trailing comma. It must produce exactly: Mouse:25.00,Keyboard:45.00,Webcam:45.00
```
`csv_format` turns green. Lesson: when the shape matters, **give an example of the exact output** —
Copilot matches it.

---

## Step 6 — `#` references (Ask mode, no edits)

`#` attaches **specific context** so Copilot answers about your real code, not a guess.

**6a · `#selection` — the highlighted code**
Select the body of `cheapestInStock` → Ask:
```
Explain #selection and describe exactly what it returns when PRODUCTS has no in-stock items.
```

**6b · `#Catalog.java` — the whole file**
```
Using #Catalog.java, which methods duplicate the same sort logic and could share one helper?
```

**6c · `#<symbol>` — one named method**
```
Compare #inStockSorted and #inStockUnder — what do they share, and what is different?
```

---

## Step 7 — `@` references (Ask mode, no edits)

`@` brings in a **participant** (a broader source of context) rather than a single file.

```
@workspace where else in this project is product or catalog logic defined?
```
```
@vscode how do I configure a task to compile and run a single Java file?
```
```
@terminal what was the exact command that compiled and ran Catalog?
```

> `#` = *a thing* (file / selection / symbol). `@` = *a participant* (workspace, VS Code, terminal).
> Grounding a prompt in real context beats describing code from memory.

---

## Step 8 — Build & run (the payoff)

```bash
javac Catalog.java && java Catalog
```

---

## Prompt cheat-sheet

| Weak prompt | Why it flops | Strong rewrite |
|---|---|---|
| `sort this` | no goal / inputs / output / constraints | the full Step 1b prompt |
| `make it better` | subjective, no target | name the constraint (`round to 2 decimals`) |
| `fix the bug` | no context attached | add `#selection` or `#Catalog.java` |
| `add a filter` | filter on *what*? | `price <= maxPrice, cap inclusive` |

**Anatomy to repeat:** *Goal · Inputs · Output shape · Constraints · Context (`#`/`@`)*, then **refine**.

---

## Quick reference — technique → prompt

| # | Technique | Target | Exact prompt (short form) |
|---|---|---|---|
| 1a | Weak (bad) | `inStockSorted` | `sort this` |
| 1b | Strong + `#` | `inStockSorted` | `In #Catalog.java implement inStockSorted(): new list, in-stock only, price asc, ties by name A→Z, don't mutate.` |
| 2 | Refinement | `inStockUnder` | broad → `sort price asc then name` → `cap inclusive (<= maxPrice)` |
| 3 | Edge cases | `cheapestInStock` | `return Optional<Product>; Optional.empty() when none; no null, no throw.` |
| 4 | Precision | `inStockInventoryValue` | `sum in-stock prices, round to exactly 2 decimals.` |
| 5 | Exact format | `inStockCsv` | `"name:price" 2 decimals, comma-joined, must equal Mouse:25.00,Keyboard:45.00,Webcam:45.00` |
| 6 | `#` refs | — | `#selection`, `#Catalog.java`, `#inStockSorted` |
| 7 | `@` refs | — | `@workspace`, `@vscode`, `@terminal` |

---

## Talking points

- **Weak vs strong:** a good prompt states the **goal, inputs, output shape, and constraints**
  ("new list", "don't mutate", "round to 2 decimals", "must equal this exact string").
- **Iterative refinement:** you rarely get the perfect answer first — refine in small steps that each
  build on the last (Step 2 is the clearest example).
- **Edge cases & precision** live in the prompt: name the empty case, the rounding, the boundary.
- **`#` references** attach a specific file / selection / symbol; **`@` references** bring in a
  participant like `@workspace`. Grounding the prompt in real context beats memory.

---

## Run

```bash
javac Catalog.java && java Catalog
```

Expected output:

```
sorted     : PASS
under_cap  : PASS
cheapest   : PASS
value      : PASS
csv_format : PASS
ALL PASS
```
