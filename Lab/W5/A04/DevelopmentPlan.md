# A04 — Prince and Princess — Development Plan

## Requirements Analysis

A prince must pass through N layers of gates to rescue a princess. Three gate types:

| Gate Type | Gatekeeper | Pass Condition | Effect on Prince |
|-----------|-----------|----------------|------------------|
| Business | Merchant | Buy products: cost = unitPrice × quantity | Reduces money |
| Academic | Sage | Prince IQ >= question intelligence level | No change to IQ |
| Power | Warrior | Prince strength >= warrior strength level | Strength reduced slightly |

### Prince Attributes
- Money (initial budget)
- IQ level
- Strength level

### Castle
- Contains N gates in sequence
- Prince must pass all gates to rescue the princess

### Expected Output
- If prince succeeds: display remaining parameters (money, IQ, strength)
- If prince fails: display list of remaining gates

## Design Decisions

### Inheritance Structure

```
Gate (abstract base)
├── BusinessGate  — pass if prince can afford unitPrice × quantity
├── AcademicGate  — pass if prince IQ >= intelligenceLevel
└── PowerGate     — pass if prince strength >= strengthLevel; strength reduces
```

- `Gate` is abstract with a pure virtual `canPass(Prince&)` method
- Each derived gate implements its own pass logic
- Virtual destructor in `Gate`

### Prince Class
- Tracks money, IQ, strength
- Methods: `spend(amount)`, `reduceStrength(amount)`, `getMoney()`, `getIQ()`, `getStrength()`
- Gates receive a reference to Prince and modify it on success

### Castle Class
- Stores a vector/array of `Gate*` (polymorphic)
- Input: reads N and each gate's type + parameters
- `simulate(Prince&)`: iterates gates, calls `canPass()`
- If any gate fails, stop and report remaining gates
- If all pass, prince wins

### Input Format
```
N                        — number of gates
gate1_type gate1_params  — e.g., "business 50000 2" (unitPrice quantity)
gate2_type gate2_params  — e.g., "academic 120" (intelligenceLevel)
gate3_type gate3_params  — e.g., "power 80" (strengthLevel)
...
prince_money prince_iq prince_strength
```

### Pass-Through Logic Details
- BusinessGate: if prince.money >= unitPrice * quantity, subtract cost, return true
- AcademicGate: if prince.iq >= intelligenceLevel, return true (no IQ reduction)
- PowerGate: if prince.strength >= strengthLevel, subtract 1 (or fixed amount), return true

## Polymorphism Aspect

- `Castle` stores `Gate*` pointers and calls `canPass()` virtually
- No switch/case on gate type — polymorphic dispatch handles it
- Easy to add new gate types (e.g., MagicGate) without modifying Castle

## Potential Problems & Resolutions

| Problem | Resolution |
|---------|------------|
| How to distinguish gate types during input | Read a type string ("business"/"academic"/"power"), then create corresponding Gate subclass |
| Prince strength reduction amount unspecified | Use a fixed reduction of 1 point per power gate victory |
| Negative money after spending | Check before spending; if insufficient, fail the gate |
| Memory management for Gate* array | Use `vector<unique_ptr<Gate>>` or ensure cleanup in Castle destructor |
| Input may contain mixed gate types | Use factory function: `Gate* createGate(string type, params)` |

## File Structure

```
Lab/W5/A04/
├── Gate.h                 — Abstract base class
├── Gate.cpp               — Base implementation
├── BusinessGate.h         — Derived class header
├── BusinessGate.cpp       — Derived class implementation
├── AcademicGate.h         — Derived class header
├── AcademicGate.cpp       — Derived class implementation
├── PowerGate.h            — Derived class header
├── PowerGate.cpp          — Derived class implementation
├── Prince.h               — Prince attributes class
├── Prince.cpp             — Prince implementation
├── Castle.h               — Castle simulation class
├── Castle.cpp             — Castle implementation
├── Main.cpp               — Test program
├── classDiagram.mmd       — Mermaid class diagram
├── classDiagram.png       — Rendered diagram
└── DevelopmentPlan.md     — This file
```

## Testing

Compile:
```
g++ -std=c++11 Gate.cpp BusinessGate.cpp AcademicGate.cpp PowerGate.cpp Prince.cpp Castle.cpp Main.cpp -o PrinceAndPrincess.exe
```

Test scenarios:
1. Prince with enough money, IQ, strength passes all gates
2. Prince fails at a business gate (insufficient money)
3. Prince fails at an academic gate (insufficient IQ)
4. Prince fails at a power gate (insufficient strength)
5. Mixed gate sequence, prince wins
6. Mixed gate sequence, prince loses mid-way — verify remaining gates display
