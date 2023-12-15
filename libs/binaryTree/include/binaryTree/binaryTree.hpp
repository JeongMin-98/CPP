//
// Created by jeong on 2023-12-14.
//

#ifndef CPPLEARN_BINARYTREE_HPP
#define CPPLEARN_BINARYTREE_HPP

#include<iostream>
#include<queue>

struct node {
    std::string position;
    node *first;
    node *second;

    node(std::string pos) : position(pos), first(nullptr), second(nullptr) {}
};

class binaryTree {
public:
    using nodePtr = node *;
private:
    nodePtr root;
public:
    binaryTree() : root(nullptr) {}

    binaryTree(const std::string pos);

    ~binaryTree() {
        std::cout << "deconstructed" << std::endl;
        removeNode(root);
    }

    ~binaryTree();

    bool removeNode(node *curNode);

    nodePtr find(node *curNode, const std::string value);

    bool addNode(const std::string senior, const std::string junior);
};

#endif //CPPLEARN_BINARYTREE_HPP
