# A03 - Console Output Report

## 1/ What is printed to the console?

B obj1("text");
//Triggers constructor B(char *s), which also triggers constructor A(s), assigning A::m_s to a literal string "text",
//which is forbidden in C++ as only const char* can do such operation ---> Error (m_s is still "text" anyway)

A *obj2 = new B(obj1);
//Triggers constructor B(const B& b), does nothing and also triggers A(), assigning m_s to "default

foo(obj1, *obj2);
//foo(A a, const A& b)
//First param obj1 (B) passed by value → sliced to A → A::prepare() → "A text"
//Second param *obj2 (B) passed by const ref → no slice → B::prepare() → "B default"
//---> A "text"
//     B "default"

## 2/ Identify the memory issues

### 2.1. String handling

Unlike modern C++ string, regular char* doesn't handle static literal string and thus will be warned as in the first line, there doesn't seem to be any dealbreaker for now because we haven't attempted to modify the string. Once we do, it will throw a segmental fault error and crash the program

=> Fix: use string or m_s = strdup(s)

### 2.2. No destructor

char* requires allocating memory and thus needed to be deallocated, but there are no destructor to do the job, leading to memory leaking

=> Fix: add virtual ~A() and ~B() that deallocate m_s

### 2.3. The rule of three

Since the class involves operations on pointer, a copy constructor and an assignment operator are required, otherwise there would be a lot of problems like double-free or multiple source control

=> Fix: add A(const A& a) and redesign B(const B& b), add A& operator=(const A& a) and B& operator=(const B& b)