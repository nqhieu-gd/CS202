# A02 — Console Output Analysis — Development Plan

## Requirements Analysis

Analyze a given C++ code snippet and determine what is printed to the console.

Expected deliverable:
- A report explaining the console output step by step
- Trace the execution flow, showing how each line produces its output

## Design Decisions

### Approach
- Manually trace the code execution line by line
- Identify which constructors, destructors, and methods are called
- Note the order of output based on constructor/destructor call order
- Consider inheritance, virtual dispatch, and implicit conversions

### Key Concepts to Cover
- Constructor call order (base → derived)
- Destructor call order (derived → base, reverse of construction)
- Virtual function dispatch at runtime
- Object slicing if objects are passed by value
- Static vs dynamic binding where applicable

### Report Structure
| Section | Content |
|---------|---------|
| Code Review | The given source code |
| Execution Trace | Step-by-step breakdown |
| Console Output | The final printed lines |
| Explanation | Why each line appears where it does |

## Potential Problems & Resolutions

| Problem | Resolution |
|---------|------------|
| Ambiguous output due to compiler optimizations | Assume standard behavior with `g++ -std=c++11` no optimization |
| Object slicing when passing by value | Explicitly note where slicing occurs |
| Virtual vs non-virtual destructor calls | Trace based on static type for non-virtual, dynamic type for virtual |

## File Structure

```
Lab/W5/A02/
├── Report.md              — Console output analysis report
└── DevelopmentPlan.md     — This file
```

## Testing

- Verify analysis by compiling and running the actual code
- Confirm the traced output matches the program output
