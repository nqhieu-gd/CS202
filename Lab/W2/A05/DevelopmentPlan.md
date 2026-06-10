# Assignment 5 - Development Plan
## Theater Ticket System

### 1. Requirements Analysis
- Theater auditorium: 15 rows, 30 seats per row (450 seats total)
- Display seating chart (* = taken, # = available)
- Enter seat prices per row when program begins (manual, file, or defaults)
- Sell ticket(s): validate row/seat, check availability, update chart
- Group purchase: sell multiple consecutive seats
- Track total ticket sales (viewable)
- View statistics: sold/available per row and total
- Input validation for all user inputs

### 2. Class Design

**Theater Class**
- Attributes: seats[15][30], rowPrices[15], totalSales
- Constructors: default (prompts for pricing), copy (for clone/assignment)
- Key methods: initializePrices, loadPricesFromFile, displaySeatingChart, sellTicket, sellGroup

### 3. Design Decisions
- Default constructor immediately asks user for pricing method (1: manual, 2: file, 3: defaults)
- File prompt accepts full path (absolute or relative) for static file access
- Row/seat numbers are 1-indexed for user (0-indexed internally)
- Group purchase validates all seats before selling any (all-or-nothing)
- cin.fail() + range checks on all numeric input

### 4. Seating Chart Format
```
   123456789012345678901234567890
 1 ############################## $10
 2 ############################## $10
...
15 ############################## $10
```

### 5. Testing Plan
| Test Case | Input | Expected Output |
|-----------|-------|----------------|
| Display chart | Menu option 1 | 15x30 grid |
| Sell single | Row 5 Seat 10 | "Seat 5-10 sold for $10" |
| Sell taken | Same seat again | "Error: already taken" |
| Sell group | Row 5, seats 1-5 | "5 seats sold for $50.00" |
| Invalid row | Row 0 or 16 | "Error: Invalid row" |
| Non-numeric | "abc" | Validation loop |
| File load | Path to file | Read 15 prices or error |

### 6. Deliverables
- [x] ClassDiagram.md - Class diagram
- [x] Theater.h - Header
- [x] Theater.cpp - Implementation
- [x] Main.cpp - Entry point
- [x] DevelopmentPlan.md - This document
