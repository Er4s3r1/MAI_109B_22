#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED
#include <iostream>

template<typename T>
class Node{
public:
    T data;
    Node<T>* left;
    Node<T>* right;
    Node(T value);
};

#include "../src/Node.cpp"

#endif
