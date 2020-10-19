//
// Created by dylan on 2020-10-19.
//

#ifndef DATA_STRUCTURES_ARRAYSTACK_H
#define DATA_STRUCTURES_ARRAYSTACK_H

// generic type T
template <class T>

class ArrayStack {
private:
    // n denotes the number of elements in the array
    int n = 0;

    // capacity denotes the size of the array
    unsigned int capacity;

    // an array of generic type T
    T *a;

    // resizes the array based on the number of elements in the array stack
    void resize();

public:
    // constructor marked explicit to avoid unintentional implicit conversions
    explicit ArrayStack(unsigned int capacity);
    ~ArrayStack();

    // returns the number of elements in the array stack
    int size();

    // returns the element at the given index i
    T get(int i);

    // sets the element at index i to x within the array stack.
    T set(int i, T x);

    // removes element at index i from the array stack and returns the element
    T remove(int i);

    // adds element x to the array stack at index i
    void add(int i, T x);
};


#endif //DATA_STRUCTURES_ARRAYSTACK_H
