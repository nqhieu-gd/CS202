# A02 — Bank Account — Development Plan

## Requirements Analysis

### BankAccount (Base Class)

| Attribute | Type | Description |
|-----------|------|-------------|
| accountNumber | string | Account identifier |
| ownerName | string | Full name of owner |
| socialID | string | Social ID / national ID |
| balance | long / double | Money in account (VND) |

| Method | Description |
|--------|-------------|
| inputInfo() | Read from keyboard |
| displayInfo() | Print to console |
| deposit(amount) | Add money to balance |
| withdraw(amount) | Remove money; balance must stay >= 50,000 VND |
| checkBalance() | Return current balance |

### SavingBankAccount (Derived from BankAccount)

| Additional Attribute | Type | Description |
|---------------------|------|-------------|
| annualRate | double | e.g., 6% = 0.06 |
| period | int | Commitment period: 1, 2, 3, 6, or 12 months |
| savingMonths | int | Months elapsed since opening |

| Additional Method | Description |
|-------------------|-------------|
| deposit(amount) | Blocked if savingMonths < period (cerr + no-op) |
| withdraw(amount) | Blocked if savingMonths < period |
| withdrawImmediately(amount) | Allowed anytime; account becomes free-period, rate drops to 2% |
| checkBalance() | Return balance + currentInterest (does NOT modify balance) |
| checkInterest() | Return computed interest only |

### Interest Formula

Simple interest:
```
interest = balance * annualRate * (savingMonths / 12.0)
```
- annualRate: e.g., 0.06 for 6%
- savingMonths / 12.0 converts to years
- For withdrawImmediately: rate becomes 2% (0.02) after the withdrawal

## Design Decisions

### Inheritance
- `BankAccount` is a concrete class (can be instantiated on its own)
- `SavingBankAccount` extends `BankAccount` publicly
- No virtual needed for basic use, but methods that change behavior (deposit, withdraw, checkBalance) are virtual for polymorphic dispatch

### balance Type
- Use `double` for balance (VND amounts can have decimals even if rare)
- Alternative: `long` for whole VND — use `double` for generality

### checkBalance() Semantics
- In `BankAccount`: returns `balance` directly
- In `SavingBankAccount`: returns `balance + interest` but does NOT modify `balance`
- Current interest is read-only calculated on demand

### withdrawImmediately()
- Changes internal state: marks account as "free-period"
- After this, interest rate is locked to 2%
- The account can still be used but loses the original rate benefit
- Track this with a `bool freePeriod` flag

### Deposit / Withdraw Guards
- `SavingBankAccount::deposit`: if `savingMonths < period`, print error, do nothing
- `SavingBankAccount::withdraw`: same guard
- `withdrawImmediately`: no guard, runs regardless, then sets free-period

### Input Validation
- Balance must be non-negative
- Withdraw amount must leave >= 50,000 VND
- Annual rate should be > 0 (e.g., 0.01 to 1.0)
- Period should be in allowed set {1, 2, 3, 6, 12}

### Constructors (at least 5 per class)

For BankAccount:
| # | Signature | Notes |
|---|-----------|-------|
| 1 | `BankAccount()` | Default — empty values, balance = 0 |
| 2 | `BankAccount(acctNum, name, socialID, balance)` | Full parameterized |
| 3 | `BankAccount(const BankAccount&)` | Copy |
| 4 | `BankAccount(acctNum, name)` | Default socialID and balance |
| 5 | `BankAccount(acctNum)` | Minimal — everything else defaulted |

For SavingBankAccount: same 5 patterns + rate, period, months parameters.

### Constructor Chaining
- SavingBankAccount constructors call matching BankAccount constructors
- Default rate = 0.06, period = 12, savingMonths = 0, freePeriod = false

## Potential Problems & Resolutions

| Problem | Resolution |
|---------|------------|
| checkBalance returns balance + interest but should not modify stored balance | Interest calculated in a local variable; balance field untouched |
| withdrawImmediately changes rate permanently | Store bool freePeriod; if true, use 2% rate in all future interest calc |
| Deposit/withdraw guards: what if months == period? | Allow if savingMonths >= period (fully matured) |
| Preventing negative balance after withdraw | Check balance - amount >= 50000 before subtracting |
| Saving months tracking | Manually set via constructor or setter; no auto-increment timer in console app |

## File Structure

```
Lab/W4/A02/
├── BankAccount.h             — Base class header
├── BankAccount.cpp           — Base class implementation
├── SavingBankAccount.h       — Derived class header
├── SavingBankAccount.cpp     — Derived class implementation
├── Main.cpp                  — Test program
├── classDiagram.mmd          — Mermaid class diagram
├── classDiagram.png          — Rendered diagram
└── DevelopmentPlan.md        — This file
```

## Testing

Compile:
```
g++ -std=c++11 BankAccount.cpp SavingBankAccount.cpp Main.cpp -o BankAccount.exe
```

Test scenarios:
1. Create BankAccount and test deposit/withdraw/balance
2. Create SavingBankAccount with all 5 constructor variants
3. Test deposit blocked when savingMonths < period
4. Test withdraw blocked when savingMonths < period
5. Test withdrawImmediately succeeds, rate drops to 2%
6. Verify checkBalance returns balance + interest (balance unchanged)
7. Polymorphic array: BankAccount* pointing to SavingBankAccount
