//
// Created by zhaoz on 7/15/2021.
//
#include "BinTreeSmartPointer.hpp"
int main() {
    auto root = make_unique<BTNode<int>>(1);
    root->left = make_unique<BTNode<int>>(2);
    root->right = make_unique<BTNode<int>>(3);
    BinTreeSmartPointer<int> t(move(root));
    t.printTree();
    return 0;
}