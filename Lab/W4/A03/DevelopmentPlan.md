# A03 — Shopping Cart Simulation — Development Plan

## Requirements Analysis

Simulate a shopping cart console application based on an e-commerce platform (Shopee-style). Focus on:

- Products with variants (color, size) and unit prices
- Quantities per product
- Total price calculation: sum of (unitPrice × quantity)
- Multiple shop groupings
- Free gifts as special product types

### Screen Elements (from reference image)

| Element | Description |
|---------|-------------|
| Shop header | Shop name with checkbox and "Mall" tag |
| Product items | Name, variant selection, quantity selector (- 1 +) |
| Unit price | Current price with optional struck-through original price |
| Free gift | Zero-price item tied to a main product |
| Quantity adjust | Increment/decrement per product |
| Total price | Sum of all checked items across all shops |
| Global footer | Select all, vouchers, coins toggle, saved amount |

### Focus (per assignment notes)
- Products, quantities, unit prices, total price
- Other features deferred to future weeks

## Design Decisions

### Inheritance Structure
- Base `CartItem` — common: name, variant, unitPrice, quantity
- Derived `MainProduct` — regular paid item with optional originalPrice
- Derived `FreeGift` — zero-price gift item linked to a MainProduct
- `Shop` groups items by merchant
- `ShoppingCart` aggregates shops and computes total

### Class Hierarchy

```
CartItem (abstract / concrete base)
├── MainProduct (concrete, has originalPrice for discount display)
└── FreeGift (concrete, always unitPrice = 0)
```

### Non-Inheritance Classes
- `Shop` — holds a shop name, a list of CartItem*, and a checked flag
- `ShoppingCart` — holds a list of Shop*, global select-all, total computation

### Total Price Calculation
- Only checked items contribute
- Total = sum over all shops of sum over checked items of (unitPrice × quantity)
- Free gifts contribute 0 (unitPrice = 0)

### Quantity Control
- Items have a quantity (int, >= 1)
- `adjustQuantity(delta)` increases or decreases
- Cannot go below 1

### Console Simulation
- Display a simplified text version of the cart
- Show shop names, items with variants, quantities, prices
- Show total at the bottom
- Simple menu: toggle item check, adjust quantity, checkout

### Constructors (at least 5)
For CartItem and derived:

| # | Signature | Notes |
|---|-----------|-------|
| 1 | `CartItem()` | Default |
| 2 | `CartItem(name, variant, unitPrice, quantity)` | Full |
| 3 | `CartItem(const CartItem&)` | Copy |
| 4 | `CartItem(name, unitPrice)` | Default variant and quantity = 1 |
| 5 | `CartItem(const string& data)` | Parse from formatted string |

### Stereotypes for Class Diagram
- `<<concrete>>` for all instantiable classes
- `<<constructor>>` on constructors
- `<<override>>` on overridden methods

## Potential Problems & Resolutions

| Problem | Resolution |
|---------|------------|
| How to link FreeGift to a MainProduct | Add a pointer or index to parent MainProduct in FreeGift; or store gift alongside product in a struct |
| Check/uncheck logic affects total | Each CartItem has a `bool checked` flag; total only sums checked items |
| Quantity cannot go below 1 | Clamp to 1 in adjustQuantity; if delta would make it 0, set to 1 and print warning |
| Multiple shops with same item names | Shops are separate entities; items are scoped to their shop |
| Struck-through original price display | MainProduct stores originalPrice; display both if originalPrice > unitPrice |
| Invariant: FreeGift price must be 0 | Enforce in constructor: unitPrice = 0 always |
| How to represent variants | String field storing variant description (e.g., "Black & White, Size M") |

## File Structure

```
Lab/W4/A03/
├── CartItem.h               — Base class header
├── CartItem.cpp             — Base implementation
├── MainProduct.h            — Derived class header
├── MainProduct.cpp          — Derived implementation
├── FreeGift.h               — Derived class header
├── FreeGift.cpp             — Derived implementation
├── Shop.h                   — Shop grouping class
├── Shop.cpp                 — Shop implementation
├── ShoppingCart.h           — Cart aggregation class
├── ShoppingCart.cpp         — Cart implementation
├── Main.cpp                 — Test program with console menu
├── classDiagram.mmd         — Mermaid class diagram
├── classDiagram.png         — Rendered diagram
└── DevelopmentPlan.md       — This file
```

## Testing

Compile:
```
g++ -std=c++11 CartItem.cpp MainProduct.cpp FreeGift.cpp Shop.cpp ShoppingCart.cpp Main.cpp -o ShoppingCart.exe
```

Test scenarios:
1. Create items via all 5 constructor variants
2. Add MainProduct and FreeGift items to a Shop
3. Add multiple shops to ShoppingCart
4. Toggle item check/uncheck and verify total updates
5. Adjust quantities and verify total recalculates
6. Free gifts always show unitPrice = 0
7. Checkout displays final total with item count
