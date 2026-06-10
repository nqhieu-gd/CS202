#include "Student.h"

static char* dup_str(const char* s) {
    if (!s) return nullptr;
    char* copy = new char[strlen(s) + 1];
    strcpy(copy, s);
    return copy;
}

Student::Student() : id(0), fullname(nullptr), address(nullptr), gpa(0.0) {
    cout << "Student::Default constructor" << endl;
}

Student::Student(int id, const char* name) : id(id), gpa(0.0) {
    cout << "Student::Constructor(int id, const char* name)" << endl;
    fullname = dup_str(name);
    address = dup_str("");
}

Student::Student(int id, const char* fullname, const char* address, double gpa)
    : id(id), gpa(gpa) {
    cout << "Student::Constructor(int, char*, char*, double)" << endl;
    this->fullname = dup_str(fullname);
    this->address = dup_str(address);
}

Student::Student(const Student& other) : id(other.id), gpa(other.gpa) {
    cout << "Student::Copy constructor" << endl;
    fullname = dup_str(other.fullname);
    address = dup_str(other.address);
}

// Format: "id|fullname|address|gpa"
// Example: "103|Le Van C|789 Pasteur, Q3, HCMC|3.50"
// Pipe (|) is used as delimiter because names/addresses may contain commas.
Student::Student(string s) {
    cout << "Student::Constructor(string s)" << endl;

    stringstream ss(s);
    string token;
    string parts[4];
    int idx = 0;
    while (getline(ss, token, '|') && idx < 4) {
        parts[idx++] = token;
    }

    if (idx >= 1) id = stoi(parts[0]);
    else id = 0;

    if (idx >= 2) fullname = dup_str(parts[1].c_str());
    else fullname = dup_str("");

    if (idx >= 3) address = dup_str(parts[2].c_str());
    else address = dup_str("");

    if (idx >= 4) gpa = stod(parts[3]);
    else gpa = 0.0;
}

Student& Student::operator=(const Student& other) {
    cout << "Student::Copy assignment" << endl;
    if (this != &other) {
        delete[] fullname;
        delete[] address;
        id = other.id;
        gpa = other.gpa;
        fullname = dup_str(other.fullname);
        address = dup_str(other.address);
    }
    return *this;
}

Student::~Student() {
    cout << "Student::Destructor" << endl;
    delete[] fullname;
    delete[] address;
}

string Student::toString() const {
    stringstream ss;
    ss << "Student{id=" << id
       << ", fullname=\"" << (fullname ? fullname : "")
       << "\", address=\"" << (address ? address : "")
       << "\", gpa=" << gpa << "}";
    return ss.str();
}

Student Student::clone() const {
    return Student(id, fullname, address, gpa);
}

void Student::display() const {
    cout << toString() << endl;
}
