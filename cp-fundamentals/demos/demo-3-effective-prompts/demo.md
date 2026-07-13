# Demo 3 - Writing Effective Prompts

Language: Java
File: Catalog.java

## Setup

1. Open Catalog.java.
2. Use Edit or Inline chat to apply prompts.
3. Use Ask mode for # and @ context prompts.

## Execution prompts

1. Weak prompt:

```text
can you sort the products in this file and make the list a bit nicer for me
```

2. Strong prompt:

```text
In #Catalog.java implement inStockSorted(): return a NEW list (do not mutate PRODUCTS) containing only products where inStock is true, sorted by price ascending, breaking ties on equal price by product name A→Z.
```

3. Iterative refinement prompts:

```text
Implement inStockUnder(double maxPrice) in #Catalog.java to return in-stock products no more expensive than maxPrice.
```

```text
Sort the result by price ascending, then by name A→Z, and return a new list without mutating PRODUCTS.
```

```text
Make the cap inclusive: price <= maxPrice, not strictly less than.
```

4. Edge-case prompt:

```text
Implement cheapestInStock() in #Catalog.java to return an Optional<Product> holding the lowest-priced in-stock product. Return Optional.empty() when nothing is in stock — do not throw and do not return null.
```

5. Precision prompt:

```text
Implement inStockInventoryValue() in #Catalog.java: sum the price of every in-stock product and round the result to exactly 2 decimal places. Return the rounded double.
```

6. Output-format prompt:

```text
Implement inStockCsv() in #Catalog.java. Using inStockSorted() order, join each product as "name:price" where price is formatted to exactly 2 decimals. Separate entries with commas and no trailing comma. It must produce exactly: Mouse:25.00,Keyboard:45.00,Webcam:45.00
```

7. Ask mode context prompts:

```text
Explain #selection and describe exactly what it returns when PRODUCTS has no in-stock items.
```

```text
Using #Catalog.java, which methods duplicate the same sort logic and could share one helper?
```

```text
Compare #inStockSorted and #inStockUnder — what do they share, and what is different?
```

8. @ reference prompts:

```text
@workspace where else in this project is product or catalog logic defined?
```

```text
@vscode how do I configure a task to compile and run a single Java file?
```

```text
@terminal what was the exact command that compiled and ran Catalog?
```

## Run

```bash
javac Catalog.java && java Catalog
```

Expected: all checks print PASS.
