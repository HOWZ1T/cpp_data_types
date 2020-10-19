//
// Created by dylan on 2020-10-19.
//

#include <stdexcept>
#include <catch.hpp>
#include "ArrayStack.h"

template <class T>
ArrayStack<T>::ArrayStack(unsigned int capacity) : capacity(capacity) {
    // allocates memory for, and creates, a new array for type T with the initial size given.
    a = new T[capacity];
}

template<class T>
ArrayStack<T>::~ArrayStack() {
    // deallocates the memory that the array was using upon the arraystack's destruction.
    delete[] a;
}

template<class T>
int ArrayStack<T>::size() {
    return n;
}

template<class T>
T ArrayStack<T>::get(int i) {
    // index is out of bounds
    if (i < 0 || i >= capacity) {
        throw std::out_of_range("ArrayStack<T>::get() : index is out of range");
    }
    return a[i];
}

template<class T>
T ArrayStack<T>::set(int i, T x) {
    // index is out of bounds
    if (i < 0 || i >= capacity) {
        throw std::out_of_range("ArrayStack<T>::set() : index is out of range");
    }

    T y = a[i];
    a[i] = x;
    return y;
}

template<class T>
void ArrayStack<T>::add(int i, T x) {
    if (n + 1 > capacity) {
        resize();
    }

    // shift elements to the right by one position to make space for x
    for (int j = n; j > i; j--) {
        a[j] = a[j-1];
    }

    a[i] = x;
    n++;
}

template<class T>
T ArrayStack<T>::remove(int i) {
    T x = a[i];

    // shift elements to the left by one position to make space for x
    for (int j = i; j < n-1; j++) {
        a[j] = a[j+1];
    }
    n--;

    if (capacity >= 3*n) {
        resize();
    }

    return x;
}

template<class T>
void ArrayStack<T>::resize() {
    // create new array with the size based on the number of elements in the array multiplied by 2
    capacity = std::max(n*2, 1);
    T *b = new T[capacity];

    // copy the elements from the old array to the new array
    for (int i = 0; i < n; i++) {
        b[i] = a[i];
    }

    // deallocate the old array memory
    delete[] a;

    // update a to the resized array b
    a = b;
}

// -- UNIT TESTS --
TEST_CASE("ArrayStack unit test", "[ArrayStack]") {
    int init_size = 10;
    ArrayStack<int> astack(init_size);
    SECTION("ArrayStack can be created") {
        REQUIRE(astack.size() == 0);
    }

    SECTION("set and get works correctly") {
        for (int i = 0; i < init_size; i++) {
            astack.set(i, (i+1)*2);
        }

        for (int i = 0; i < init_size; i++) {
            REQUIRE(astack.get(i) == (i+1)*2);
        }
    }

    // create new array for next set of testing
    astack = ArrayStack<int>(init_size);

    SECTION("add, remove and resize works correctly") {
        // testing add
        for (int i = 1; i <= init_size+10; i++) {
            astack.add(i-1, i*2);
            REQUIRE(astack.size() == i);
            REQUIRE(astack.get(i-1) == i*2);
        }

        // testing remove
        for (int i = init_size+10; i >= 1; i--) {
            int x = astack.remove(i-1);
            REQUIRE(astack.size() == init_size+10-(init_size+10-(i-1)));
            REQUIRE(x == i*2);
        }
    }
}