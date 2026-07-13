// Demo 3 — Writing Effective Prompts (Slide 42)
// Language: Java   |   Run: javac Catalog.java && java Catalog
//
// Features: crafting good prompts, @ and # references, iterative refinement.
//
// Five stubbed methods, each teaching one prompting move. All start FAILing;
// finish them with Copilot (see demo.md) until you get ALL PASS.
//   Task 1  inStockSorted()          weak -> strong prompt
//   Task 2  inStockUnder(max)        iterative refinement (add a constraint)
//   Task 3  cheapestInStock()        constraints & edge cases (Optional/empty)
//   Task 4  inStockInventoryValue()  aggregate with a precision rule
//   Task 5  inStockCsv()             exact output format

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public class Catalog {

    record Product(String name, double price, boolean inStock) {}

    static final List<Product> PRODUCTS = List.of(
        new Product("Keyboard", 45.0, true),
        new Product("Monitor", 210.0, false),
        new Product("Mouse", 25.0, true),
        new Product("Webcam", 45.0, true),
        new Product("Cable", 8.0, false)
    );

    // ---- Task 1: weak -> strong prompt --------------------------------
    // A NEW list of in-stock products, sorted by price ascending,
    // ties broken by product name A->Z. Do NOT mutate PRODUCTS.
    static List<Product> inStockSorted() {
        return new ArrayList<>(); // replace with Copilot's suggestion
    }

    // ---- Task 2: iterative refinement (add a constraint) --------------
    // In-stock products with price <= maxPrice, same sort as inStockSorted().
    static List<Product> inStockUnder(double maxPrice) {
        return new ArrayList<>(); // refine the prompt to add the price cap
    }

    // ---- Task 3: constraints & edge cases (Optional) ------------------
    // The single cheapest in-stock product, or Optional.empty() if none.
    static Optional<Product> cheapestInStock() {
        return Optional.empty(); // prompt Copilot to handle the empty case
    }

    // ---- Task 4: aggregate with a precision rule ---------------------
    // Total price of all in-stock products, rounded to 2 decimal places.
    static double inStockInventoryValue() {
        return 0.0; // ask for a sum with rounding
    }

    // ---- Task 5: exact output format --------------------------------
    // CSV of in-stock products in inStockSorted() order, each "name:price"
    // with price to exactly 2 decimals, comma-joined, no trailing comma.
    // Example shape: "Mouse:25.00,Keyboard:45.00,Webcam:45.00"
    static String inStockCsv() {
        return ""; // make the prompt specify the exact format
    }

    public static void main(String[] args) {
        List<String> names = new ArrayList<>();
        for (Product p : inStockSorted()) {
            names.add(p.name());
        }
        boolean checkSorted = names.equals(List.of("Mouse", "Keyboard", "Webcam"));

        List<Product> under = inStockUnder(30.0);
        boolean checkUnder = under.size() == 1 && under.get(0).name().equals("Mouse");

        boolean checkCheapest = cheapestInStock().map(Product::name).orElse("").equals("Mouse");

        boolean checkValue = inStockInventoryValue() == 115.0;

        boolean checkCsv = inStockCsv().equals("Mouse:25.00,Keyboard:45.00,Webcam:45.00");

        System.out.println("sorted     : " + (checkSorted ? "PASS" : "FAIL (Task 1: strong prompt)"));
        System.out.println("under_cap  : " + (checkUnder ? "PASS" : "FAIL (Task 2: refine with a cap)"));
        System.out.println("cheapest   : " + (checkCheapest ? "PASS" : "FAIL (Task 3: Optional/empty)"));
        System.out.println("value      : " + (checkValue ? "PASS" : "FAIL (Task 4: rounded sum)"));
        System.out.println("csv_format : " + (checkCsv ? "PASS" : "FAIL (Task 5: exact format)"));

        boolean all = checkSorted && checkUnder && checkCheapest && checkValue && checkCsv;
        System.out.println(all ? "ALL PASS" : "SOME FAILED - finish the tasks with Copilot, then re-run.");
    }
}
