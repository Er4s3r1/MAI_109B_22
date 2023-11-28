#ifndef TREE_HPP_INCLUDED
#define TREE_HPP_INCLUDED

#include "Node.hpp"

template<typename T>
class Tree {
private:
    Node<T>* root;
    Node<T>* createNode(T data);
    Node<T>* insertNode(Node<T>* root, T data);
    void traversal(Node<T>* root);
    Node<T>* deleteNode(Node<T>* root, T data);
    bool areLeavesAtSameLevel(Node<T>* root, int level, int& leafLevel);
public:
    Tree();
    void insert(T data);
    void remove(T data);
    void display();
    bool areLeavesAtSameLevel();
};

#include "../src/BinaryTree.cpp"

#endif
