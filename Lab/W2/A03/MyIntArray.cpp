#include "MyIntArray.h"
#include <vector>

MyIntArray::MyIntArray() : a(nullptr), n(0) {
    cout << "MyIntArray::Default constructor" << endl;
}

MyIntArray::MyIntArray(int n) : n(n) {
    cout << "MyIntArray::Constructor(int n)" << endl;
    a = new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = 0;
    }
}

MyIntArray::MyIntArray(int n, int* arr) : n(n) {
    cout << "MyIntArray::Constructor(int n, int* arr)" << endl;
    a = new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = arr[i];
    }
}

MyIntArray::MyIntArray(const MyIntArray& other) : n(other.n) {
    cout << "MyIntArray::Copy constructor" << endl;
    a = new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = other.a[i];
    }
}

MyIntArray::MyIntArray(string s) {
    cout << "MyIntArray::Constructor(string s)" << endl;
    if (s.empty()) {
        n = 0;
        a = nullptr;
        return;
    }
    vector<int> temp;
    stringstream ss(s);
    string token;
    while (getline(ss, token, ',')) {
        if (!token.empty()) {
            temp.push_back(stoi(token));
        }
    }
    n = (int)temp.size();
    a = new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = temp[i];
    }
}

MyIntArray& MyIntArray::operator=(const MyIntArray& other) {
    cout << "MyIntArray::Copy assignment" << endl;
    if (this != &other) {
        delete[] a;
        n = other.n;
        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = other.a[i];
        }
    }
    return *this;
}

MyIntArray::~MyIntArray() {
    cout << "MyIntArray::Destructor" << endl;
    delete[] a;
}

string MyIntArray::toString() const {
    stringstream ss;
    ss << "[";
    for (int i = 0; i < n; i++) {
        if (i > 0) ss << ", ";
        ss << a[i];
    }
    ss << "]";
    return ss.str();
}

MyIntArray MyIntArray::clone() const {
    return MyIntArray(n, a);
}

int MyIntArray::sum() const {
    int s = 0;
    for (int i = 0; i < n; i++) s += a[i];
    return s;
}

int MyIntArray::max() const {
    if (n == 0) return 0;
    int m = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > m) m = a[i];
    return m;
}

int MyIntArray::min() const {
    if (n == 0) return 0;
    int m = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] < m) m = a[i];
    return m;
}

static int partition(int* arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

static void quickSort(int* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void MyIntArray::sortAsc() {
    if (n <= 1) return;
    quickSort(a, 0, n - 1);
}

void MyIntArray::display() const {
    cout << toString() << endl;
}
