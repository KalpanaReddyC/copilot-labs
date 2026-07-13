# Demo 2 - Getting Started in Your IDE

Language: C++
File: tip_calculator.cpp

## Setup

1. Open tip_calculator.cpp.
2. Enable Next Edit Suggestions in VS Code.
3. Use the prompts below in the specified mode.

## Execution prompts

1. Ghost text seed in calculate_tip:

```cpp
ret
```

2. Inline chat prompt in split_bill:

```text
Return 0 when people is zero or negative; otherwise split amount plus the tip evenly. Keep the signature the same.
```

3. Inline chat prompt in apply_discount:

```text
Implement a loyalty discount on `amount` based on `loyalty_years`: 0 years = 0% off, 1-2 years = 5% off, 3-4 years = 10% off, 5 or more years = 15% off. Return the amount AFTER the discount. Use clean branching and keep the signature unchanged.
```

4. Optional inline refactor prompt (select apply_discount body):

```text
Refactor this to use a lookup table or early returns so new tiers are easy to add later. Do not change the behavior.
```

5. Quick chat prompt:

```text
In this tip calculator, what edge cases could make grand_total return a wrong or surprising value? Think negative amounts, huge loyalty_years, and floating-point rounding on money. Answer briefly.
```

6. Optional quick chat follow-up:

```text
Which of those would you fix first, and why?
```

7. Ask mode prompts:

```text
Explain #selection step by step: what it computes, and how it handles zero or negative people.
```

```text
Trace grand_total(200, 10, 3) call by call through #tip_calculator.cpp. Show the intermediate value after apply_discount, calculate_tip, and service_fee, then the final number.
```

```text
Compare split_bill and grand_total in #tip_calculator.cpp: what does each include in the total, and when would each be the wrong function to call?
```

8. Plan mode prompt:

```text
Plan the steps to add a "round the per-person amount up to the nearest dollar" option to this tip calculator. List the steps only — do not write code yet.
```

9. Slash command prompts:

```text
/fix service_fee returns a value 100x too small. It should be percent% of amount (e.g. 5% of 200 = 10.00). Fix it.
```

```text
/tests cover the loyalty tiers (0, 2, 4, 10 years), a zero amount, and a negative amount.
```

```text
/explain
```

```text
/doc
```

10. Context prompts:

```text
Are the tier boundaries in #selection correct and non-overlapping? Point out any off-by-one.
```

```text
What does #grand_total include that #split_bill does not?
```

```text
Give a one-paragraph overview of #tip_calculator.cpp and list every function with a one-line purpose.
```

## Run

```bash
g++ -std=c++17 tip_calculator.cpp -o tip && ./tip
```

PowerShell:

```powershell
g++ -std=c++17 tip_calculator.cpp -o tip; ./tip
```

Expected: all checks print PASS.
