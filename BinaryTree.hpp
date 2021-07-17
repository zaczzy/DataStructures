//
// Created by zhaoz on 7/15/2021.
//

#ifndef DATASTRUCTURES_BINARYTREE_H
#define DATASTRUCTURES_BINARYTREE_H



template<typename T>
class BTNode {
public:
    T value;
    BTNode<T> *left;
    BTNode<T> *right;
    BTNode(T value) : value(value), left(nullptr), right(nullptr) {};
};

template<typename T>
class BinaryTree {
private:
    BTNode<T>* root;
public:
    BinaryTree(BTNode<T>* r): root(r){};
    void printTree() {

    };
// virtual destructor needed when class serves as base class.
    virtual ~BinaryTree() {};
//  technically we also need
//  copy constructor
//  assignment operator
};
#endif //DATASTRUCTURES_BINARYTREE_H
