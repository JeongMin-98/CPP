//
// Created by jeong on 2023-12-18.
//

#include "binaryTree/binaryTree.hpp"

int main() {
    BinarySearchTree<int> bst;

    bst.insert(10);
    bst.insert(12);
    bst.insert(3);

    bst.find(3);

    return 0;

}