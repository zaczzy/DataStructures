//
// Created by zhaoz on 7/15/2021.
//

#ifndef DATASTRUCTURES_BINTREESMARTPOINTER_HPP
#define DATASTRUCTURES_BINTREESMARTPOINTER_HPP
#include <memory>
#include <queue>
#include <iostream>
using namespace std;

template<class T>
class BTNode {
public:
    T value;
    unique_ptr<BTNode<T>> left;
    unique_ptr<BTNode<T>> right;
    BTNode(T value): value(value), left(nullptr), right(nullptr){};
};



template<class T>
class BinTreeSmartPointer {
public:
    unique_ptr<BTNode<T>> root;
    BinTreeSmartPointer(unique_ptr<BTNode<T>> r) : root(move(r)) {};
    void printTree() {
        queue<unique_ptr<BTNode<T>>> q;
        q.push(move(root));
        unique_ptr<BTNode<T>> top;
        while(!q.empty()) {
            top = move(q.front());
            cout << top->value << " ";
            if (top->left != nullptr) q.push(move(top->left));
            if (top->right != nullptr) q.push(move(top->right));
            q.pop();
        }
        cout << endl;
    };
};

#endif //DATASTRUCTURES_BINTREESMARTPOINTER_HPP
