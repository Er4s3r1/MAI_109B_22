#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H

#include "Node.h"
#include <iostream>
#include <string>

class ExpressionTree{
private:
    Node* root;
    std::string expression;

public:
    ExpressionTree();
    ExpressionTree(const std::string& expression);
    ~ExpressionTree();

    Node* getRoot() const;
    std::string getExpression();

    void deleteTree(Node* node);
    void createTree(const std::string& postfix);
    std::string doPostfix(const std::string& expression);
    void composeToSquaredExpression();

    void printPostfix(Node* root);
    void printInfix(Node* root) const;
    void printTree(Node* root, const size_t height = 0) const;
};

#endif
