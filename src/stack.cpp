#ifndef STACK_TPP
#define STACK_TPP

#include "../include/stack.h"

Stack::Stack(int size) : maxSize(size), top(-1) {
    elements = new Position[maxSize];
}

Stack::~Stack() {
    delete[] elements;
}

void Stack::push(const Position& value) {
    if (isFull()) {
        throw std::overflow_error("Overflow: não é possível adicionar item a uma lista cheia.");
    }
    elements[++top] = value;
}

Position Stack::pop() {
    if (isEmpty()) {
        throw std::underflow_error("Underflow: não é possível remover item de uma lista vazia.");
    }
    return elements[top--];
}

Position Stack::peek() {
    if (isEmpty()) {
        throw std::underflow_error("Empty: lista está vazia.");
    }
    return elements[top];
}

bool Stack::isEmpty() {
    return top == -1;
}

bool Stack::isFull() {
    return top == maxSize - 1;
}

bool Stack::contains(const Position& value) {
    for (int i = 0; i <= top; i++) {
        if (elements[i].x == value.x && elements[i].y == value.y) {
            return true;
        }
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const Stack& stack) {
    os << "[";

    for (int i = 0; i <= stack.top; i++) {
        os << '{' << stack.elements[i].x << ", " << stack.elements[i].y << '}';
    }

    os << "]";
    return os;
}

#endif
