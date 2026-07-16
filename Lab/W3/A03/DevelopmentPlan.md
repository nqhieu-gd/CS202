# A03 — IntArray Class Development Plan

## Requirements Analysis

Implement an IntArray class using dynamic allocated array, supporting all operators in the provided `main.cpp`:

| Category | Operators |
|----------|-----------|
| Constructors | Default (empty), size (n zeros), from C array (copy), copy |
| Assignment | `=` |
| Subscript | `[]` (read and write) |
| Stream | `<<`, `>>` |
| Type conversion | `(int)` — returns the size |

## Design Decisions

### Dynamic Memory (Rule of Three)
The class manages a raw pointer `int* data`. This requires:
- **Destructor** — `delete[] data`, then set `data = nullptr` for double-delete safety
- **Copy constructor** — deep copy of data (guard `size > 0` to avoid `new int[0]`)
- **Copy assignment** — allocate-first pattern for strong exception safety, then delete-and-swap

Without these, the compiler-generated defaults would shallow-copy the pointer, causing double-delete crashes.

### Defensive Patterns Applied

| Pattern | Why |
|---------|-----|
| `data = nullptr` in all constructors for empty arrays | Ensures `delete[] nullptr` is a safe no-op |
| `if (size > 0)` guard before `new int[size]` | Avoids wasteful `new int[0]` which returns a dummy pointer |
| Allocate-first in `operator=` | If `new` throws, original data is preserved (strong exception guarantee) |
| `this != &other` guard in `operator=` | Prevents self-assignment from deleting own data prematurely |
| `data = nullptr` after `delete[]` in destructor | Double-delete safety

### Subscript Operator (Two Versions)
```cpp
int& operator[](int index);       // non-const: allows arr[3] = 5
int  operator[](int index) const; // const: read-only, used by operator<<
```

The `const` version returns by value so the caller can't modify through a const reference.

### Stream I/O
- `operator<<` prints as `[1, 2, 3, 4, 5, 6, 7]`
- `operator>>` reads `size` integers from input into the existing array
- Both are `friend` functions (stream is left operand)

### Size via operator int()
```cpp
operator int() const { return size; }
```
Allows `(int)m4` to return the array length.

### Size Constructor
```cpp
IntArray(int n) : data(nullptr), size(n) {
    if (n > 0)
        data = new int[n]();  // () zero-initializes all elements
}
```
Note: `data` is initialized to `nullptr` first. If `n == 0`, no allocation occurs — `data` stays `nullptr`, keeping the empty state consistent.

## File Structure

```
Lab/W3/A03/
├── IntArray.h            — Class declaration
├── IntArray.cpp          — Implementation
├── Main.cpp              — Provided test code
└── DevelopmentPlan.md    — This file
```

## Testing

Compile with:
```
g++ IntArray.cpp Main.cpp -o IntArray.exe
```

Run with 7 integers for `cin >> m2`:
```
echo "10 20 30 40 50 60 70" | ./IntArray.exe
```

Expected output: `[10, 20, 30, 40, 50, 60, 70]07`
