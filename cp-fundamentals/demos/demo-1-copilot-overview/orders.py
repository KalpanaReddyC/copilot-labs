# ============================================================
#  Demo 1 - GitHub Copilot Overview (Slide 16)
#  Feature: Ghost text / code completions - "AI assistance in action"
# ============================================================
#
#  HOW TO PRESENT:
#    1. Delete the `pass` under a function.
#    2. Type the first token (e.g. `ret`) and PAUSE - grey "ghost text" appears.
#    3. Press Tab to accept, Alt+] / Alt+[ to cycle, Esc to dismiss.
#
#  The payoff: once all five functions are filled in, run the file and Copilot's
#  code prints a fully formatted store receipt. That's the "wow".
#
#  Each function starts with a stub `pass` so the file still runs before you demo.

STORE_NAME = "InfoMagnus Tech Store"

ITEMS = [
    {"name": "Mechanical Keyboard", "price": 45.0, "qty": 2},
    {"name": "Wireless Mouse", "price": 25.0, "qty": 1},
    {"name": "4K Monitor", "price": 210.0, "qty": 1},
    {"name": "USB-C Cable", "price": 12.5, "qty": 4},
]

# Orders at or above this subtotal earn a loyalty discount.
DISCOUNT_THRESHOLD = 300.0
DISCOUNT_RATE = 10   # percent
TAX_RATE = 8         # percent


# Return the subtotal: sum of price * qty for every item in the list
def order_total(items):
    pass  # ghost text -> return sum(i["price"] * i["qty"] for i in items)


# Return the discount amount (not the new total): DISCOUNT_RATE% of subtotal
# when subtotal >= DISCOUNT_THRESHOLD, otherwise 0.0
def loyalty_discount(subtotal):
    pass  # ghost text completes this


# Return amount plus tax, where rate is a percentage (e.g. 8 means 8%)
def apply_tax(amount, rate):
    pass  # ghost text completes this


# Return a receipt line like "Mechanical Keyboard   x2   $90.00" for one item dict
def receipt_line(item):
    pass  # ghost text completes this


# Return the final amount the customer pays:
#   subtotal minus loyalty_discount, then apply_tax at TAX_RATE, rounded to 2 decimals
def grand_total(items):
    pass  # ghost text completes this


def print_receipt(items):
    """Pretty, boxed receipt - assembled from the functions above."""
    width = 44
    line = "+" + "-" * width + "+"
    print(line)
    print("|" + STORE_NAME.center(width) + "|")
    print(line)
    for item in items:
        print("| " + receipt_line(item).ljust(width - 1) + "|")
    print(line)

    subtotal = order_total(items)
    discount = loyalty_discount(subtotal)
    taxed = apply_tax(subtotal - discount, TAX_RATE)
    tax_amount = taxed - (subtotal - discount)
    print("| " + f"Subtotal:  ${subtotal:>28.2f}".ljust(width - 1) + "|")
    print("| " + f"Discount: -${discount:>28.2f}".ljust(width - 1) + "|")
    print("| " + f"Tax ({TAX_RATE}%):  ${tax_amount:>28.2f}".ljust(width - 1) + "|")
    print("| " + f"TOTAL:     ${grand_total(items):>28.2f}".ljust(width - 1) + "|")
    print(line)
    print("|" + "Thank you for shopping with us!".center(width) + "|")
    print(line)


def _check(name, actual, expected):
    ok = actual == expected
    print(f"{name:<16}: {'PASS' if ok else f'FAIL (got {actual!r}, want {expected!r})'}")
    return ok


if __name__ == "__main__":
    print("=== Self-checks ===")
    sub = order_total(ITEMS)
    checks = [
        _check("order_total", sub, 375.0),
        _check("loyalty_discount", loyalty_discount(375.0), 37.5),
        _check("apply_tax", apply_tax(100.0, 8), 108.0),
        _check("receipt_line", receipt_line(ITEMS[0]), "Mechanical Keyboard   x2   $90.00"),
        _check("grand_total", grand_total(ITEMS), 364.5),
    ]

    if all(checks):
        print("\nALL PASS - here's the receipt:\n")
        print_receipt(ITEMS)
    else:
        print("\nSOME FAILED - finish the functions with ghost text, then re-run.")
