//
// Created by jeong on 2023-12-18.
//

#include "binaryTree/binaryTree.hpp"

int main() {
    BinarySearchTree<int> bst;

    bst.insert(12);
    bst.insert(10);
    bst.insert(20);
    bst.insert(8);
    bst.insert(11);
    bst.insert(15);
    bst.insert(28);
    bst.insert(4);
    bst.insert(2);

    std::cout << "InOrder traversal: ";
    bst.inOrder();
    std::cout << std::endl;

    bst.find(3);

    return 0;

}