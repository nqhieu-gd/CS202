# Complete Class List - Library Management System OOP

## Summary
- **Total Classes**: 4
- **Total Attributes**: 26
- **Total Methods**: 117

---

## Class 1: Date

### Purpose
Represents a calendar date with validation and comparison capabilities.

### Attributes (3)
| Access | Type | Name | Description |
|--------|------|------|-------------|
| private | int | day | Day of the month (1-31) |
| private | int | month | Month of the year (1-12) |
| private | int | year | Year (2000+) |

### Methods (17)
1. `public Date()` - Default constructor
2. `public Date(int d, int m, int y)` - Parameterized constructor
3. `public Date(const Date& other)` - Copy constructor
4. `public int getDay() const` - Returns day
5. `public int getMonth() const` - Returns month
6. `public int getYear() const` - Returns year
7. `public void setDay(int d)` - Sets day
8. `public void setMonth(int m)` - Sets month
9. `public void setYear(int y)` - Sets year
10. `public void input()` - Reads date from user
11. `public void display() const` - Displays date
12. `public static bool isValidDate(int d, int m, int y)` - Validates date
13. `public static bool isLeapYear(int y)` - Checks leap year
14. `public bool isAfter(const Date& other) const` - Compare dates
15. `public bool isBefore(const Date& other) const` - Compare dates
16. `public int daysDifference(const Date& other) const` - Calculate difference
17. Assignment operator (implicit)

---

## Class 2: Book

### Purpose
Represents a book in the library with inventory management.

### Attributes (8)
| Access | Type | Name |
|--------|------|------|
| private | string | ISBN |
| private | string | nameOfBook |
| private | string | nameOfAuthor |
| private | string | publisher |
| private | int | publishingYear |
| private | string | typeOfBook |
| private | long | priceOfBook |
| private | int | theNumberOfBooks |

### Methods (27)
**Constructors & Operators:**
1. `public Book()` - Default constructor
2. `public Book(...)` - Parameterized constructor
3. `public Book(const Book& other)` - Copy constructor
4. `public Book& operator=(const Book& other)` - Assignment operator

**Getters (8):**
5. `public string getISBN() const`
6. `public string getNameOfBook() const`
7. `public string getNameOfAuthor() const`
8. `public string getPublisher() const`
9. `public int getPublishingYear() const`
10. `public string getTypeOfBook() const`
11. `public long getPriceOfBook() const`
12. `public int getTheNumberOfBooks() const`

**Setters (8):**
13. `public void setISBN(const string& isbn)`
14. `public void setNameOfBook(const string& name)`
15. `public void setNameOfAuthor(const string& author)`
16. `public void setPublisher(const string& pub)`
17. `public void setPublishingYear(int year)`
18. `public void setTypeOfBook(const string& type)`
19. `public void setPriceOfBook(long price)`
20. `public void setTheNumberOfBooks(int quantity)`

**Business Methods (4):**
21. `public void input()` - Read book data
22. `public void display() const` - Display book info
23. `public void adjustQuantity(int delta)` - Adjust stock
24. `public bool isAvailable() const` - Check availability

**Private Helpers (3):**
25. `private bool isValidISBN(const string& isbn) const`
26. `private bool isValidCharacter(const string& str) const`
27. `private void toUpperCase(string& str)`

---

## Class 3: Reader

### Purpose
Represents a library member who can borrow books.

### Attributes (13)
| Access | Type | Name |
|--------|------|------|
| private | string | code |
| private | string | name |
| private | string | idNumber |
| private | Date | dob |
| private | string | email |
| private | string | address |
| private | string | gender |
| private | Date | creatingCardDay |
| private | Date | expiringCardDay |
| private | Book[6] | borrowBook |
| private | int | quantityOfBorrowing |
| private | Date[6] | borrowDay |
| private | Date[6] | returnDay |

### Methods (37)
**Constructors & Operators:**
1. `public Reader()` - Default constructor
2. `public Reader(...)` - Parameterized constructor
3. `public Reader(const Reader& other)` - Copy constructor
4. `public Reader& operator=(const Reader& other)` - Assignment operator

**Getters (13):**
5. `public string getCode() const`
6. `public string getName() const`
7. `public string getIdNumber() const`
8. `public Date getDob() const`
9. `public string getEmail() const`
10. `public string getAddress() const`
11. `public string getGender() const`
12. `public Date getCreatingCardDay() const`
13. `public Date getExpiringCardDay() const`
14. `public int getQuantityOfBorrowing() const`
15. `public Book getBorrowBook(int index) const`
16. `public Date getBorrowDay(int index) const`
17. `public Date getReturnDay(int index) const`

**Setters (8):**
18. `public void setCode(const string& c)`
19. `public void setName(const string& n)`
20. `public void setIdNumber(const string& id)`
21. `public void setDob(const Date& d)`
22. `public void setEmail(const string& e)`
23. `public void setAddress(const string& a)`
24. `public void setGender(const string& g)`
25. `public void setCreatingCardDay(const Date& d)`

**Business Methods (8):**
26. `public void input()` - Read reader data
27. `public void display() const` - Display reader info
28. `public bool canBorrowMore() const` - Check borrow limit
29. `public void borrowBookFromLibrary(...)` - Borrow book
30. `public void returnBookToLibrary(int)` - Return book
31. `public bool hasOverdueBooks(const Date&) const` - Check overdue
32. `public void displayBorrowedBooks() const` - Show borrowed books

**Private Helpers (4):**
33. `private bool isValidCode(const string& c) const`
34. `private bool isValidID(const string& id) const`
35. `private bool isValidCharacter(const string& str) const`
36. `private void toUpperCase(string& str)`

---

## Class 4: Library

### Purpose
Manages collections of books and readers, handles all library operations.

### Attributes (2)
| Access | Type | Name |
|--------|------|------|
| private | vector\<Book\> | listBook |
| private | vector\<Reader\> | listReader |

### Methods (30)
**Constructor:**
1. `public Library()` - Constructor

**Book Management (7):**
2. `public void printListOfBooks()` - Display all books
3. `public void addBook()` - Add new book
4. `public void adjustBook()` - Edit book info
5. `public void deleteBook()` - Remove book
6. `public void findBookByISBN()` - Search by ISBN
7. `public void findBookByName()` - Search by name
8. `public int getNumberOfBooks() const` - Get book count
9. `public Book& getBook(int index)` - Get book reference

**Reader Management (7):**
10. `public void printListOfReaders()` - Display all readers
11. `public void addReader()` - Register new reader
12. `public void adjustReader()` - Edit reader info
13. `public void deleteReader()` - Remove reader
14. `public void findReaderByCitizenId()` - Search by ID
15. `public void findBooksByReaderName()` - Find reader's books
16. `public int getNumberOfReaders() const` - Get reader count
17. `public Reader& getReader(int index)` - Get reader reference

**Operations (2):**
18. `public void borrowBook(const Date& today)` - Process borrowing
19. `public void returnBook(const Date& today)` - Process return

**Statistics (6):**
20. `public void statisticsNumberOfBooks()` - Total books
21. `public void statisticsNumberOfBooksByType()` - Books by type
22. `public void statisticsNumberOfReaders()` - Total readers
23. `public void statisticsGender()` - Readers by gender
24. `public void statisticsBooksBorrowed()` - Currently borrowed
25. `public void statisticsOverdueReaders(const Date&)` - Overdue list

**File Operations (6):**
26. `public void loadData()` - Load from files
27. `public void saveData()` - Save to files
28. `private void readBooksFromFile(const string&)` - Read books
29. `private void writeBooksToFile(const string&)` - Write books
30. `private void readReadersFromFile(const string&)` - Read readers
31. `private void writeReadersToFile(const string&)` - Write readers

---

## Summary Statistics

### Methods by Access Level
| Class | Public | Private | Total |
|-------|--------|---------|-------|
| Date | 17 | 0 | 17 |
| Book | 24 | 3 | 27 |
| Reader | 33 | 4 | 37 |
| Library | 26 | 4 | 30 |
| **TOTAL** | **100** | **11** | **117** |

### Attributes by Class
| Class | Private Attributes |
|-------|--------------------|
| Date | 3 |
| Book | 8 |
| Reader | 13 |
| Library | 2 |
| **TOTAL** | **26** |

---

## Key Features

✓ **Complete Encapsulation** - All data is private  
✓ **Comprehensive Getters/Setters** - Full access control  
✓ **Input Validation** - All user input validated  
✓ **Business Logic** - Operations like borrow/return encapsulated  
✓ **File Persistence** - Save/load functionality  
✓ **Statistics** - Various reporting methods  
✓ **Modern C++** - Uses STL (vector, string)
