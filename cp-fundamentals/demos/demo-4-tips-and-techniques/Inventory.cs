// Demo 4 — Tips and Techniques (Slide 72)
// Language: C#   |   Run: put in a `dotnet new console` project as Program.cs, then `dotnet run`
//                        (or: csc Inventory.cs && Inventory)
//
// Techniques: commands & context, refactoring, documentation, multilingual (convert),
//             tests, MCP intro. Deep dive (Agent/MCP/tests/refactor/optimize) = Intermediate.
//
// This class already works — run it first so the room sees a passing baseline, then use Copilot to:
//   - #context  attach #Inventory.cs / #selection / #NeedsReorder to ground a question
//   - Inline chat  ask for an XML doc comment on ReorderQuantity (it has a rule worth documenting)
//   - Edit      refactor ReorderReport AND TotalUnitsToOrder to LINQ (same behavior)
//   - Edit      convert this file to Dart (multilingual) -> save as inventory.dart
//   - /tests    generate tests for ReorderQuantity (intro only; deep dive in Intermediate)

using System;
using System.Collections.Generic;

class Item
{
    public string Sku { get; set; }
    public string Name { get; set; }
    public int OnHand { get; set; }
    public int ReorderAt { get; set; }

    public Item(string sku, string name, int onHand, int reorderAt)
    {
        Sku = sku;
        Name = name;
        OnHand = onHand;
        ReorderAt = reorderAt;
    }
}

class Inventory
{
    static readonly List<Item> Items = new List<Item>
    {
        new Item("KB-01", "Keyboard", 3, 5),
        new Item("MS-02", "Mouse", 12, 5),
        new Item("MN-03", "Monitor", 1, 2),
        new Item("CB-04", "Cable", 8, 4),
    };

    // True when the item is at or below its reorder threshold.
    static bool NeedsReorder(Item item)
    {
        return item.OnHand <= item.ReorderAt;
    }

    // Units to order to bring an item back up to its "par level" (twice the
    // reorder threshold). Returns 0 when the item does not need reordering.
    // (/doc target: this rule is worth an XML <summary>.)
    static int ReorderQuantity(Item item)
    {
        if (!NeedsReorder(item))
        {
            return 0;
        }
        int parLevel = item.ReorderAt * 2;
        return parLevel - item.OnHand;
    }

    // Return the list of item names that need reordering.
    // (Refactor step: ask Copilot to rewrite this using LINQ, keeping behavior identical.)
    static List<string> ReorderReport(List<Item> items)
    {
        var result = new List<string>();
        foreach (var item in items)
        {
            if (NeedsReorder(item))
            {
                result.Add(item.Name);
            }
        }
        return result;
    }

    // Total units to order across the whole catalog.
    // (Refactor step: this one collapses to a single LINQ Sum(...).)
    static int TotalUnitsToOrder(List<Item> items)
    {
        int total = 0;
        foreach (var item in items)
        {
            total += ReorderQuantity(item);
        }
        return total;
    }

    static void Main()
    {
        bool check1 = NeedsReorder(Items[0]) && !NeedsReorder(Items[1]);

        var report = ReorderReport(Items);
        bool check2 = report.Count == 2 && report[0] == "Keyboard" && report[1] == "Monitor";

        // Keyboard: par 10 - onHand 3 = 7 ; Mouse is well stocked -> 0.
        bool check3 = ReorderQuantity(Items[0]) == 7 && ReorderQuantity(Items[1]) == 0;

        // Keyboard 7 + Monitor 3 = 10 (Mouse and Cable need nothing).
        bool check4 = TotalUnitsToOrder(Items) == 10;

        Console.WriteLine($"NeedsReorder    : {(check1 ? "PASS" : "FAIL")}");
        Console.WriteLine($"ReorderReport   : {(check2 ? "PASS" : "FAIL")}");
        Console.WriteLine($"ReorderQuantity : {(check3 ? "PASS" : "FAIL")}");
        Console.WriteLine($"TotalUnitsOrder : {(check4 ? "PASS" : "FAIL")}");
        Console.WriteLine((check1 && check2 && check3 && check4) ? "ALL PASS" : "SOME FAILED");
    }
}
