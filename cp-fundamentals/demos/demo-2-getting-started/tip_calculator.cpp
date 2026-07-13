// ============================================================
//  Demo 2 - Getting Started in Your IDE (Slide 32)
//  Build & run: g++ -std=c++17 tip_calculator.cpp -o tip && ./tip
// ============================================================
//
//  This file gives every Copilot surface a real job:
//    - Ghost text        -> complete calculate_tip
//    - Inline chat (Ctrl+I) -> add a zero-people guard to split_bill
//    - Next Edit Sugg.   -> rename calculate_tip -> tip_amount (Tab to finish)
//    - Quick chat (Ctrl+Shift+I) -> ask about shortcuts (no edit)
//    - Ask + #selection  -> explain split_bill
//    - Plan mode         -> plan a new feature
//    - / commands        -> /fix the service_fee bug, /doc format_currency
//
//  Everything is stubbed/buggy so the file runs but FAILS until you demo.

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

// ---- Ghost text target -------------------------------------
// Return the tip: amount * percent / 100
double calculate_tip(double amount, double percent) {
    return 0.0; // let ghost text complete this
}

// ---- Inline chat target (Ctrl+I) ---------------------------
// Split the bill (amount + its tip) evenly between `people`.
// Right now it divides by zero when people == 0. Harden it with inline chat.
double split_bill(double amount, double percent, int people) {
    double tip = calculate_tip(amount, percent);
    return (amount + tip) / people;
}

// ---- Inline chat target (Ctrl+I) - harder, multi-branch ----
// Apply a loyalty discount to `amount` based on `loyalty_years`:
//   0 years -> 0% off, 1-2 -> 5% off, 3-4 -> 10% off, 5+ -> 15% off.
// Return the amount AFTER the discount. Stub returns it unchanged.
double apply_discount(double amount, int loyalty_years) {
    return amount; // build the tiered discount with inline chat (Ctrl+I)
}

// ---- / commands target: /fix -------------------------------
// A service fee that is `percent` of the amount.
// BUG (fix with /fix): it divides by 100 twice, so the fee is 100x too small.
double service_fee(double amount, double percent) {
    return amount * percent / 100 / 100;
}

// ---- / commands target: /doc -------------------------------
// (Undocumented on purpose - use /doc to add a doc comment here.)
std::string format_currency(double value) {
    std::ostringstream out;
    out << "$" << std::fixed << std::setprecision(2) << value;
    return out.str();
}

// ---- Ask / #symbol / /tests target -------------------------
// Composes the other functions into one final number. Great for
// Ask mode ("trace #grand_total") and /tests. Needs the discount,
// tip, and service_fee steps finished before its check passes.
double grand_total(double amount, double percent, int loyalty_years) {
    double discounted = apply_discount(amount, loyalty_years);
    double tip        = calculate_tip(discounted, percent);
    double fee        = service_fee(discounted, 5);
    return discounted + tip + fee;
}

int main() {
    bool c1 = calculate_tip(200, 10) == 20.0;
    bool c2 = split_bill(200, 10, 4) == 55.0;

    // After the inline-chat edit, zero people should return 0 (not inf/nan).
    bool c3 = split_bill(200, 10, 0) == 0.0;

    // After /fix, service_fee(200, 5) should be 10.0 (5% of 200), not 0.1.
    bool c4 = service_fee(200, 5) == 10.0;

    bool c5 = format_currency(90.0) == "$90.00";

    // After the harder inline-chat edit, the loyalty tiers should match:
    //   0y -> 0% off, 1-2y -> 5%, 3-4y -> 10%, 5+y -> 15%.
    bool c6 = apply_discount(100, 0)  == 100.0
           && apply_discount(100, 2)  == 95.0
           && apply_discount(100, 4)  == 90.0
           && apply_discount(100, 10) == 85.0;

    // grand_total composes discount + tip + service fee (needs c1, c4, c6).
    bool c7 = grand_total(200, 10, 0) == 230.0;

    std::cout << "calculate_tip  : " << (c1 ? "PASS" : "FAIL") << "\n";
    std::cout << "split_bill     : " << (c2 ? "PASS" : "FAIL") << "\n";
    std::cout << "guard          : " << (c3 ? "PASS" : "FAIL (add the zero-people guard with Ctrl+I)") << "\n";
    std::cout << "service_fee    : " << (c4 ? "PASS" : "FAIL (fix the double /100 bug with /fix)") << "\n";
    std::cout << "format_currency: " << (c5 ? "PASS" : "FAIL") << "\n";
    std::cout << "apply_discount : " << (c6 ? "PASS" : "FAIL (build the tiered discount with Ctrl+I)") << "\n";
    std::cout << "grand_total    : " << (c7 ? "PASS" : "FAIL (finish discount + /fix first)") << "\n";

    if (c1 && c2 && c3 && c4 && c5 && c6 && c7) {
        double bill = 200.0, pct = 10.0;
        int people = 4;
        std::cout << "\n----- Bill Summary -----\n";
        std::cout << "Bill        : " << format_currency(bill) << "\n";
        std::cout << "Tip (" << pct << "%) : " << format_currency(calculate_tip(bill, pct)) << "\n";
        std::cout << "Service fee : " << format_currency(service_fee(bill, 5)) << "\n";
        std::cout << "Per person  : " << format_currency(split_bill(bill, pct, people)) << "\n";
        // NES demo (Step 3b): add a "Discount" line here, then Tab the predicted "Grand total" line.
        std::cout << "ALL PASS\n";
    } else {
        std::cout << "\nSOME FAILED - finish the steps with Copilot, then re-run.\n";
    }
    return 0;
}
