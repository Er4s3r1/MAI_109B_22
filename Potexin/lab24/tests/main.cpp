#include "../include/ExpressionTree.h"
#include <iostream>
#include <string>

int main(){
    // 4*a^4+4*a^2*b+b^2
    std::string expr = "a^2+2*a*b+b^2";
    ExpressionTree tree(expr);

    tree.printInfix(tree.getRoot());
    std::cout << "\n";
    tree.printPostfix(tree.getRoot());
    std::cout << "\n";
    tree.printTree(tree.getRoot());
    std::cout << "\n\n\n";
    tree.printTree(tree.getRoot());
    std::cout << "\n\n\n";
    tree.composeToSquaredExpression();
    tree.printInfix(tree.getRoot());
    std::cout << "\n";
    tree.printPostfix(tree.getRoot());
    std::cout << "\n";
    tree.printTree(tree.getRoot());
    std::cout << "\n\n\n";
}
