# A03 — Shopping Cart Simulation — Solution Report

## Overview

This assignment required simulating a shopping cart interface in a console application using C++ with inheritance. The focus was on products, quantities, unit prices, and total price calculation.

## Class Design

### Inheritance Hierarchy

```
CartItem (base)
├── MainProduct (paid items with discount display)
└── FreeGift (zero-price gift items)
```

**CartItem** is the base class holding common attributes:
- `name` — product name
- `variant` — selected variant (color, size)
- `unitPrice` — price per unit
- `quantity` — number of units (min 1)
- `checked` — whether the item is selected for checkout

**MainProduct** extends CartItem with:
- `originalPrice` — struck-through original price for discount display
- Overridden `displayInfo()` shows `[Product]` tag and original price when higher than unit price

**FreeGift** extends CartItem with:
- `unitPrice` always set to 0 (enforced in constructors)
- Overridden `displayInfo()` shows `[Gift]` tag and "FREE" label
- No quantity-based price contribution

### Aggregation

```
Shop o-- CartItem        (Shop contains CartItem pointers)
ShoppingCart o-- Shop    (ShoppingCart contains Shop pointers)
```

**Shop** groups items by merchant:
- Has a name, checked flag, and a vector of CartItem pointers
- Owns its items (destructor deletes them)
- `getTotalPrice()` sums checked items only if the shop itself is checked

**ShoppingCart** aggregates shops:
- Owns its shops (destructor deletes them)
- `displayCart()` prints all shops with their items
- `getTotalPrice()` sums all checked shops' totals
- `checkout()` displays final total with item count

## Key Design Decisions

| Decision | Rationale |
|----------|-----------|
| Check/uncheck per item | Items can be individually toggled; unchecked items contribute 0 to total |
| Quantity clamp at 1 | Prevents invalid zero or negative quantities |
| `checked` field on CartItem | Enables fine-grained selection control at the item level |
| Shop-level check | Shops can also be unchecked, excluding all their items from total |
| FreeGift enforces price=0 | Invariant: gifts never contribute to total regardless of quantity |
| Copy deleted on Shop/ShoppingCart | Prevents accidental double-free of owned pointers (RAII) |

## Challenges

1. **Ownership management**: Decided that Shop owns its CartItem pointers and ShoppingCart owns its Shop pointers. Copy operations were deleted to prevent double-free issues.
2. **Checked/unchecked logic**: The total must only include checked items from checked shops. This required propagating the check state through two levels.
3. **FreeGift constructor**: Ensuring `unitPrice = 0` always required overriding the value in all constructors, since the base class accepts a price parameter.

## How the Simulation Works

1. Main creates items (MainProduct and FreeGift) and a Shop
2. Items are added to the Shop
3. The Shop is added to the ShoppingCart
4. `displayCart()` prints the full cart layout with tags, variants, quantities, prices
5. `getTotalPrice()` computes the sum of (unitPrice × quantity) for all checked items
6. `checkout()` shows the final total and item count

## Reference Scenario

Based on the provided image (ROCKBROS Global Store):
- Bicycle Helmet: 572,368 VND × 1 = 572,368 VND
- Cycling Arm Sleeves (Gift): 0 VND × 1 = 0 VND
- Cycling Gloves: 81,632 VND × 1 = 81,632 VND
- **Total: 654,000 VND**
