# Library Management System - OOP Version

## Overview
This is the Object-Oriented Programming (OOP) version of the Library Management System, converted from the original procedural C/C++ code.

## Files Structure

```
OOP_Version/
├── Date.h              - Date class declaration
├── Date.cpp            - Date class implementation
├── Book.h              - Book class declaration
├── Book.cpp            - Book class implementation
├── Reader.h            - Reader class declaration
├── Reader.cpp          - Reader class implementation
├── Library.h           - Library class declaration
├── Library.cpp         - Library class implementation
├── Main.cpp            - Main program with menu
└── README.md           - This file
```

## Class Structure

### Date Class
- Manages date information with validation
- Supports date comparison and calculations

### Book Class
- Represents a book with ISBN, title, author, publisher, etc.
- Handles book inventory and validation

### Reader Class
- Represents a library member
- Manages borrowed books (up to 6)
- Tracks borrow/return dates

### Library Class
- Central management system
- Manages collections of books and readers
- Handles all library operations

## Compilation

### Using g++
```bash
g++ -std=c++11 Date.cpp Book.cpp Reader.cpp Library.cpp Main.cpp -o LibraryOOP.exe
```

### Using Visual Studio
1. Create a new C++ Console Application project
2. Add all .h and .cpp files to the project
3. Build and run (Ctrl+F5)

### Using Code::Blocks
1. Create new Console Application project
2. Add all source files
3. Build and Run (F9)

## Usage

### Running the Program
```bash
./LibraryOOP.exe
```

### Main Menu Options
1. **Book Management** - Add, edit, delete, search books
2. **Reader Management** - Add, edit, delete, search readers
3. **Borrow Book** - Process book borrowing
4. **Return Book** - Process book returns
5. **Statistics** - View various reports
6. **Exit** - Save and quit

## Features

### Book Management
- Display all books in library
- Add new books with validation
- Edit book information
- Delete books from collection
- Search books by ISBN or name

### Reader Management
- Display all registered readers
- Register new readers
- Edit reader information
- Delete reader records
- Search readers by ID or name

### Borrowing System
- Readers can borrow up to 6 books
- Tracks borrow and return dates
- Validates book availability

### Statistics
- Total books in library
- Books grouped by type
- Total readers
- Gender distribution
- Currently borrowed books
- Overdue readers list

## Data Files
- `listBook.txt` - Stores book information
- `listReader.txt` - Stores reader information

## Requirements
- C++ compiler with C++11 support or higher
- Windows OS (for system commands)
- Standard C++ libraries

## Key Improvements Over Procedural Version

1. **Encapsulation** - All data is private with controlled access
2. **Better Organization** - Related data and functions grouped in classes
3. **Type Safety** - Uses std::string and std::vector
4. **Maintainability** - Easier to understand and modify
5. **Reusability** - Classes can be reused in other projects
6. **Extensibility** - Easy to add new features

## Documentation

See also:
- `../ConversionReport.md` - Detailed conversion process
- `../ClassDiagram.md` - Visual class structure
- `../ClassList.md` - Complete list of classes, attributes, and methods
- `../DevelopmentPlan.md` - Development methodology

## Author
Converted from procedural to OOP as part of CS202 Lab Assignment 5

## Notes
- Some advanced features (like complete file I/O) are simplified in this version
- File operations are stubbed and would need full CSV parsing in production
- Input validation follows the original procedural version's logic
