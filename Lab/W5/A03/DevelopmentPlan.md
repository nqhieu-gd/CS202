# A03 — Console, Memory Issues, I/O Operators — Development Plan

## Requirements Analysis

Three tasks for a given C++ program:

1. **Console Output**: What is printed? Give a brief explanation.
2. **Memory Issues**: Identify memory issues in the program and correct them.
3. **I/O Operators**: Write input and output operators for class A and class B.

### Expected Deliverables
- Full source code with corrections applied
- Report explaining the output, memory issues, and fixes

## Design Decisions

### Console Output Analysis
- Trace execution step by step
- Identify constructor/destructor calls and their order
- Note any undefined behavior or platform-dependent output

### Memory Issue Identification
Common issues to look for:
- Missing virtual destructors (undefined behavior when deleting via base pointer)
- Double deletion of the same pointer
- Memory leaks (allocated but never deleted)
- Dangling pointers (use after free)
- Buffer overflows / out-of-bounds access
- Improper copy semantics (shallow copy of raw pointers)

### I/O Operators
Overload `operator<<` and `operator>>` for class A and class B:
- `friend ostream& operator<<(ostream& os, const A& a)` — formatted output
- `friend istream& operator>>(istream& is, A& a)` — formatted input
- Handle input errors gracefully (failbit on bad input)

### Fix Strategy
| Issue | Fix |
|-------|-----|
| Missing virtual destructor | Add `virtual ~Base()` |
| Double delete | Use nullptr after delete, or use smart pointers |
| Memory leak | Add proper destructor / use RAII |
| Shallow copy | Implement copy constructor + copy assignment (Rule of Three/Five) |

## Potential Problems & Resolutions

| Problem | Resolution |
|---------|------------|
| I/O operator format ambiguity | Document expected I/O format clearly |
| Input validation in operator>> | Check stream state after extraction; set failbit on error |
| Memory issue might be subtle | Compile with `-fsanitize=address` to detect leaks and UB |
| Output may depend on compiler | Test with g++ and clang++ to confirm expected behavior |

## File Structure

```
Lab/W5/A03/
├── Report.md              — Analysis + corrected source code
└── DevelopmentPlan.md     — This file
```

## Testing

Compile original and corrected versions:
```
g++ -std=c++11 -fsanitize=address -g original.cpp -o original.exe
g++ -std=c++11 -fsanitize=address -g corrected.cpp -o corrected.exe
```

Test scenarios:
1. Original program output matches traced analysis
2. Corrected program runs without ASAN errors
3. I/O operators round-trip correctly (write then read back)
4. Valgrind/ASAN shows no leaks or errors in corrected version
