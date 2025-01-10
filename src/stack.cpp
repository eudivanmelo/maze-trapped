#ifndef STACK_TPP
#define STACK_TPP

#include "Stack.h"

template <typename T>
Stack<T>::Stack(int size) : maxSize(size), top(-1) {
    elements = new T[maxSize];
}

template <typename T>
Stack<T>::~Stack() {
    delete[] elements;
}

template <typename T>
void Stack<T>::push(const T& value) {
    if (isFull()) {
        throw std::overflow_error("Overflow: não é possível adicionar item a uma lista cheia.");
    }
    elements[++top] = value;
}

template <typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        throw std::underflow_error("Underflow: não é possível remover item de uma lista vazia.");
    }
    return elements[top--];
}

template <typename T>
T Stack<T>::peek() {
    if (isEmpty()) {
        throw std::underflow_error("Empty: lista está vazia.");
    }
    return elements[top];
}

template <typename T>
bool Stack<T>::isEmpty() {
    return top == -1;
}

template <typename T>
bool Stack<T>::isFull() {
    return top == maxSize - 1;
}

#endif
