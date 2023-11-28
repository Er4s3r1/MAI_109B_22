#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED
#include <iostream>

template<typename T>
class List;
template<typename T>
class Iterator;

template <typename T>
class Node {
private:
    T data;
    Node* prev = nullptr;
    Node* next = nullptr;

public:
    friend class List<T>;
    friend class Iterator<T>;

    Node() = default;
    explicit Node(const T& _data);
    Node(const T& _data, Node* _prev, Node* _next);
    ~Node() = default;
};


#include "../src/Node.cpp"
#endif
