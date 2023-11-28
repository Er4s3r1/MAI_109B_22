#ifndef STACK_HPP
#define STACK_HPP

#include "../../KP7/src/Vector.cpp"
#include <iostream>

template <typename T>
class Stack{
private:
    Vector<T> stack;

public:
    Stack() = default;
    Stack(const std::initializer_list<T>& list);
    ~Stack() = default;

    size_t size() const;
    bool empty() const;
    void push(const T& value);
    void pop();
    T& top();
    const T& top() const;
};

#endif
