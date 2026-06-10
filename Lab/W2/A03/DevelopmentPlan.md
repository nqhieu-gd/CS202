# Assignment 3 - Development Plan
## MyIntArray Class Implementation with Constructors/Destructors

### 1. Requirements Analysis
- Implement MyIntArray class with dynamic int array (int* a, int n)
- 5 different constructors each printing identification message
- Destructor printing when called (must delete dynamic array)
- toString() for string representation "[v1, v2, ...]"
- clone() for creating independent deep copy
- Additional: sum, max, min, sortAsc (manual quicksort), display

### 2. Constructor Design
1. **Default** - MyIntArray() → empty array (n=0, a=nullptr)
2. **Size** - MyIntArray(int n) → array of n zeros
3. **Array** - MyIntArray(int n, int* arr) → copy from existing array
4. **Copy** - MyIntArray(const MyIntArray&) → deep copy
5. **String** - MyIntArray(string s) → parse comma-separated values "v1,v2,v3"

### 3. Key Design Decisions
- Uses int* for dynamic array (raw pointer as specified)
- Rule of Three: destructor + copy constructor + copy assignment operator
- Deep copy in copy constructor and assignment prevents double-free
- String constructor uses vector<int> as intermediate buffer
- sortAsc() implements manual quicksort with Hoare partition (O(n log n))
- max()/min() guard against empty array (return 0)

### 4. Testing Plan
| Test Case | Input | Expected Output |
|-----------|-------|----------------|
| Default | MyIntArray() | [], n=0 |
| Size | MyIntArray(5) | [0,0,0,0,0] |
| Array | MyIntArray(6, data) | [3,1,4,1,5,9] |
| Copy | arr4(arr3) | Same as arr3 |
| String | MyIntArray("10,20,30") | [10,20,30] |
| Copy assign | arr6 = arr5 | Deep copy via operator= |
| sortAsc | arr3.sortAsc() | [1,1,3,4,5,9] (quicksort) |

### 5. Deliverables
- [x] MyIntArray.h - Header with class declaration
- [x] MyIntArray.cpp - Implementation with 5 constructors + operator=
- [x] Main.cpp - Demonstration program

### 6. Lessons Learned
- Dynamic arrays require careful memory management
- Rule of Three: destructor, copy constructor, copy assignment
- Deep copy vs shallow copy for pointer members
- Quicksort: O(n log n) average, O(n²) worst case
