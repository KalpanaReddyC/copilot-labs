# Demo 3 — Writing Effective Prompts  (Deck **Slide 42**)

**Agenda section:** Getting started / prompting

**Covers:** Crafting Good Prompts · **Using @ and # References** · Iterative Refinement

**Language:** **Java**  ·  **File:** [Catalog.java](Catalog.java)

---

## What This Script Does

In [Catalog.java](Catalog.java), you're building a small **product catalog utility** that does five things:

1. Get in-stock products sorted by price, then name.
2. Filter in-stock products under a price cap.
3. Find the cheapest in-stock product safely with `Optional`.
4. Calculate the total value of in-stock inventory.
5. Export the in-stock catalog as a correctly formatted CSV string.

---

## Setup

| Setting | Value |
|---|---|
| **Mode** | **Ask** mode (explain / discuss) and **Edit** / **Inline chat** (apply the change) |
| **Model** | GPT-5.4 |
| **File** | `Catalog.java` |

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
Implement inStockSorted(): return a NEW list (do not mutate PRODUCTS) containing only products where inStock is true, sorted by price ascending, breaking ties on equal price by product name A→Z.
```
`sorted` turns green. Read the **anatomy** aloud:

> **Anatomy of a strong prompt** — *Goal* (implement `inStockSorted`) · *Inputs* (`PRODUCTS`) ·
> *Output* (a new list) · *Constraints* (in-stock only, price asc, tie by name, don't mutate) ·
> *Context* (`#Catalog.java`).

---

## Step 2 — Iterative refinement (`inStockUnder`)

### Option A — One big prompt (works, but hard to steer)

```
Implement inStockUnder(double maxPrice): return a NEW list (do not mutate PRODUCTS) of in-stock products whose price is less than or equal to maxPrice, sorted by price ascending, ties broken by name A→Z.
```

> **Point out:** this is fine for a method you fully understand up-front, but what if the
> requirement is fuzzy, or you want to verify each piece before moving on?

### Option B — Iterative refinement (recommended)

Break the same task into bite-sized prompts, reviewing after each one:

**2a · First pass (intentionally broad):**
```
Implement inStockUnder(double maxPrice) to return in-stock products no more expensive than maxPrice.
```
Review the output — it probably works but the sort order is missing or wrong.

**2b · Refine — pin the sort so it matches the others:**
```
Sort the result by price ascending, then by name A→Z, and return a new list without mutating PRODUCTS.
```
Now the sort matches `inStockSorted()`. Check the diff before accepting.

**2c · Refine — confirm the boundary:**
```
Make the cap inclusive: price <= maxPrice, not strictly less than.
```
`under_cap` turns green (the check calls `inStockUnder(30.0)` → only `Mouse`).

> **Takeaway:** each message is short and *builds on the last*. You catch mistakes earlier, keep
> context small, and can course-correct at every step — that's iterative refinement.

---

## Step 3 — Naming edge cases in your prompt (`cheapestInStock`)

Without explicit constraints, Copilot defaults to the happy path. This step shows how
**calling out edge cases by name** changes the quality of the generated code.

**Where:** inside `cheapestInStock`.

**3a · Vague prompt (show what you get without edge-case guidance):**
```
Get the cheapest in-stock product.
```
Copilot may return `null`, throw an exception, or skip the empty-list scenario entirely.
**Point out** that the prompt never said what to do when there are no in-stock products.

**3b · Strong prompt (name every edge case explicitly):**
```
Implement cheapestInStock() to return an Optional<Product> holding the lowest-priced in-stock product. Return Optional.empty() when nothing is in stock — do not throw and do not return null.
```

> **Prompting lesson:** spelling out *"do not throw, do not return null, return
> Optional.empty()"* forces Copilot to handle the edge case. If you don't name it,
> Copilot guesses — and guesses are bugs.

---

## Step 4 — Adding precision constraints (`inStockInventoryValue`)

A prompt that says "add up the prices" is technically correct but leaves rounding,
data types, and formatting to chance. This step teaches the audience to **include
precision rules** whenever numbers matter.

**Where:** inside `inStockInventoryValue`.

**4a · Loose prompt (show the ambiguity):**
```
Sum the prices of in-stock products.
```
The result may be an `int`, a `float`, or an unrounded `double`. **Point out** that
there is no mention of rounding or decimal places.

**4b · Precise prompt (add the constraint):**
```
Implement inStockInventoryValue() sum the price of every in-stock product and round the result to exactly 2 decimal places. Return the rounded double.
```

> **Prompting lesson:** numeric constraints ("round to 2 decimal places", "return as
> double") remove ambiguity. Without them the output *might* be right — but you can't
> count on it.

---

## Step 5 — Specifying exact output format (`inStockCsv`)

When the shape of the output matters (APIs, file exports, test assertions), vague
prompts lead to wrong delimiters, missing decimals, or trailing separators. This step
shows how **providing a concrete example** locks the format down.

**Where:** inside `inStockCsv`.

**5a · Vague prompt (show the format drift):**
```
Export in-stock products as CSV.
```
Copilot may use headers, tabs, or a different field order. **Point out** that "CSV"
alone does not define the exact shape.

**5b · Format-locked prompt (give an example of the expected output):**
```
Implement inStockCsv() Using inStockSorted() order, join each product as "name:price" where price is formatted to exactly 2 decimals. Separate entries with commas and no trailing comma. It must produce exactly: Mouse:25.00,Keyboard:45.00,Webcam:45.00
```

> **Prompting lesson:** when the output format matters, **show a concrete example** in
> the prompt. Copilot pattern-matches against it — no guessing required.

---


## Step 6 — `@` references (Ask mode, no edits)

`@` brings in a **participant** (a broader source of context) rather than a single file.

```
@vscode how do I configure a task to compile and run a single Java file?
```
```
@terminal what was the exact command that compiled and ran Catalog?
```

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
