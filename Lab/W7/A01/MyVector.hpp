#pragma once

#include <string>
#include <stdexcept>
#include <sstream>

template <class T>
MyVector<T>::MyVector(): size(0), arr(nullptr), capacity(0) {}

// n zeros
template <class T>
MyVector<T>::MyVector(int n): size(n), arr(nullptr), capacity(0) {
    if (n < 0) {
        throw std::out_of_range("Negative size is not allowed!");
    }
    if (n == 0) return;
    arr = new T[n];
    capacity = size;
}

template <class T>
MyVector<T>::MyVector(T *a, int n): size(n), arr(nullptr), capacity(0) {
    if (n < 0) {
        throw std::out_of_range("Negative size is not allowed!");
    }
    if (n == 0) return;
    arr = new T[n];
    for (int i = 0; i < n; i++) {
        arr[i] = a[i];
    }
    capacity = size;
}

template <class T>
MyVector<T>::MyVector(const MyVector &v): size(v.size), arr(nullptr), capacity(v.capacity) {
    if (size == 0) {
        return;
    }
    arr = new T[size];
    for (int i = 0; i < capacity; i++) {
        arr[i] = v.arr[i];
    }
}

template <class T>
MyVector<T>::~MyVector() {
    delete[] arr;
    arr = nullptr;
    size = 0;
}

template <class T>
int MyVector<T>::getSize() {
    return this->capacity;
}

template <class T>
T MyVector<T>::getItem(int index) {
    if (index < 0 || index >= capacity) {
        throw std::out_of_range("Index out of range!");
    }
    return arr[index];
} 

template <class T>
void MyVector<T>::setItem(T value, int index) {
    if (index < 0 || index >= capacity) {
        throw std::out_of_range("Index out of range!");
    }
    this->arr[index] = value;
}

template <class T>
void MyVector<T>::add(T value) {
    if (size == 0) {
        arr = new T[2];
        size = 2;
    }
    if (capacity >= size) {
        size *= 2;
        T* newArr = new T[size];
        for (int i = 0; i < capacity; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }
    this->arr[capacity++] = value;
}

template <class T>
void MyVector<T>::addRange(T *a, int n) {
    if (size == 0) {
        arr = new T[2];
        size = 2;
    }
    if (capacity + n > size) {
        while (size < capacity + n) size *= 2;
        T* newArr = new T[size];
        for (int i = 0; i < capacity; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }
    for (int i = 0; i < n; i++) {
        this->arr[capacity++] = a[i];
    }
}

template <class T>
void MyVector<T>::clear() {
    delete[] arr;
    arr = nullptr;
    size = 0;
    capacity = 0;
}

template <class T>
bool MyVector<T>::contains(T value) {
    for (int i = 0; i < capacity; i++) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}

template <class T>
void MyVector<T>::toArray(T *arr, int &n) {
    if (capacity == 0) {
        if (arr != nullptr) delete[] arr;
        arr = nullptr;
    }
    if (arr == nullptr) {
        arr = new T[capacity];
    }
    n = capacity;
    for (int i = 0; i < n; i++) {
        arr[i] = this->arr[i];
    }
}

template <class T>
bool MyVector<T>::equals(const MyVector &v) {
    if (size != v.size || capacity != v.capacity) return false;
    for (int i = 0; i < capacity; i++) {
        if (arr[i] != v.arr[i]) return false;
    }
    return true;
}

template <class T>
int MyVector<T>::indexOf(T value) {
    for (int i = 0; i < capacity; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

template <class T>
int MyVector<T>::lastIndexOf(T value) {
    for (int i = capacity - 1; i >= 0; i--) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

template <class T>
void MyVector<T>::insert(T value, int index) {
    if (index < 0 || index > capacity) {
        throw std::out_of_range("Index out of range!");
    }
    if (capacity >= size) {
        size *= 2;
        T* newArr = new T[size];
        for (int i = 0; i < capacity; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }
    for (int i = capacity; i > index; i--) {
        arr[i] = arr[i-1];
    }
    arr[index] = value;
    capacity++;
}

template <class T>
void MyVector<T>::remove(T value) {
    int index = indexOf(value);
    if (index == -1) return;
    for (int i = index; i < capacity - 1; i++) {
        arr[i] = arr[i+1];
    }
    capacity--;
}

template <class T>
void MyVector<T>::removeAt(int index) {
    if (index < 0 || index >= capacity) {
        throw std::out_of_range("Index out of range!");
    }
    for (int i = index; i < capacity - 1; i++) {
        arr[i] = arr[i+1];
    }
    capacity--;
}

template <class T>
void MyVector<T>::reverse() {
    for (int i = 0; i < capacity / 2; i++) {
        T tmp = arr[i];
        arr[i] = arr[capacity - 1 - i];
        arr[capacity - 1 - i] = tmp;
    }
}

template <class T>
std::string MyVector<T>::toString() {
    std::string s = "";
    s += "[";
    for (int i = 0; i < capacity; i++) {
        std::stringstream ss;
        ss << arr[i];
        s += ss.str();
        if (i != capacity - 1) s += ", ";
    }
    s += "]";
    return s;
}

template <class T>
void MyVector<T>::sort(int i, int bg, int en) {
    if (i != 1 && i != -1) return;
    if (bg >= en) return;
    int md = (bg + en)/2;
    sort(i, bg, md);
    sort(i, md + 1, en);
    
    int l = bg, r = md + 1, id = 0;
    T* vt = new T[en - bg + 1];
    while (l <= md && r <= en) {
        if ((i == -1 && arr[l] <= arr[r]) || (i == 1 && arr[l] >= arr[r])) {
            vt[id++] = arr[l++];
        }
        else {
            vt[id++] = arr[r++];
        }
    }
    while (l <= md) {
        vt[id++] = arr[l++];
    }
    while (r <= en) {
        vt[id++] = arr[r++];
    }
    for (int i = 0; i < id; i++) {
        arr[bg + i] = vt[i];
    }
    delete[] vt;
}

template <class T>
void MyVector<T>::sortAsc() {
    sort(-1, 0, capacity - 1);
}

template <class T>
void MyVector<T>::sortDesc() {
    sort(1, 0, capacity - 1);
}