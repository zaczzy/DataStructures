#include "BinaryTree.hpp"

int main() {
    BTNode<int>* root = new BTNode<int>(1);
    
    BinaryTree<int> t{root};
    delete root;
    return 0;
}