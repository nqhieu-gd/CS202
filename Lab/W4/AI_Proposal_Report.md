# AI Proposal Report — CS202 Week 4

**Student**: Nguyen Quang Hieu - 25125043 | **Course**: CS202 - Programming Systems | **Week**: 4

## AI Usage Notes

**Declaration B: I did use AI for this homework.**  
**Tool**: Claude (via opencode CLI), accessed July 14, 2026.

### AI-Generated Content

| Assignment | What AI Generated | Prompt / Purpose |
|-----------|-------------------|------------------|
| A01–A03 | Header files, `.cpp` implementations, `Main.cpp` | "Generate Employee abstract base + OfficeEmployee/Worker derived with 5 constructors each" / "Generate BankAccount + SavingBankAccount with simple interest, deposit/withdraw guards" / "Generate CartItem, MainProduct, FreeGift, Shop, ShoppingCart simulating the given cart scenario" |
| A01–A03 | Mermaid class diagrams | "Create class diagram with stereotypes for the hierarchy" |
| A01–A03 | DevelopmentPlan.md | "Draft development plan with requirements, design decisions, problems, testing" |
| A04–A05 | Presentation slides | "Create 30+ slide markdown on inheritance in Python/Java covering syntax, overriding, constructor order" |

### Student-Edited & Validated Content

| Fix | Assignment | What I Did |
|-----|-----------|------------|
| Simplified Date (not W3's full version) | A01 | Directed AI to make a minimal self-contained Date class |
| 5-constructor pattern + string format | A01 | Specified `"id \|\| name \|\| dd/mm/yyyy \|\| address"` format and constructor signatures |
| Simple interest formula | A02 | Specified `balance * rate * (savingMonths / 12.0)` |
| checkBalance semantics | A02 | Directed it returns sum but does **not** modify stored balance |
| freePeriod flag | A02 | Directed `withdrawImmediately()` sets 2% rate via boolean flag |
| Quantity clamp at 1 | A03 | Directed minimum quantity = 1 |
| Main.cpp test cases | A01–A03 | Designed test scenarios covering all constructors + edge cases |
| Slide sequence & accuracy | A04–A05 | Reorganized slides, verified MRO, `super()`, covariant returns |

### Independent Work
- Analyzed assignment specifications and determined inheritance structure for each problem
- Made all design decisions: abstract vs concrete, constructor signatures, guard conditions
- Reviewed every line of generated code; caught and directed fixes for all bugs
- Compiled and ran all three C++ assignments to verify correctness

## Key Design Decisions (All Mine)

- **Employee abstract** — no meaningful generic salary; forces derived implementation
- **5 constructors including string parser** — matches spec, flexible construction
- **checkBalance returns sum without modifying balance** — principal preserved, interest read-only
- **CartItem → MainProduct / FreeGift** — paid vs free items with distinct display
- **Shop owns CartItem\*, ShoppingCart owns Shop\*** — clear RAII ownership chain

## Academic Integrity
Every line is reviewed and understood by me. I can explain and modify any part independently.

## Files Submitted

| Folder | Key Files |
|--------|-----------|
| A01 | Date.h, Employee.h/.cpp, OfficeEmployee.h/.cpp, Worker.h/.cpp, Main.cpp, classDiagram.mmd/.html, DevelopmentPlan.md |
| A02 | BankAccount.h/.cpp, SavingBankAccount.h/.cpp, Main.cpp, classDiagram.mmd/.html, DevelopmentPlan.md |
| A03 | CartItem.h/.cpp, MainProduct.h/.cpp, FreeGift.h/.cpp, Shop.h/.cpp, ShoppingCart.h/.cpp, Main.cpp, Report.md, classDiagram.mmd/.html, DevelopmentPlan.md |
| A04 | OOP_Python_Inheritance.md (33 slides), Review.txt |
| A05 | OOP_Java_Inheritance.md (33 slides), Review.txt |
| Root | README.md (Declaration B), AI_Proposal_Report.md |
