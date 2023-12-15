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

    binaryTree(const std::string pos) {
        root = new node(pos);
    }

    ~binaryTree() {
        std::cout << "deconstructed" << std::endl;
        removeNode(root);
        delete root;
    }

    bool removeNode(node *curNode) {
        if (curNode == nullptr) {
            return false;
        }
        if (curNode->first == nullptr && curNode->second == nullptr) {
            std::cout << "curNode [" << curNode->position << "] deconstructed" << std::endl;
            delete curNode;
            return true;
        }
        if (curNode->first != nullptr) {
            removeNode(curNode->first);
        }
        if (curNode->second != nullptr) {
            removeNode(curNode->second);
        }

    }

    nodePtr find(node *curNode, const std::string value) {
        if (curNode == nullptr)
            return nullptr;
        if (curNode->position == value) {
            return curNode;
        }
        auto firstNode = find(curNode->first, value);
        if (firstNode != nullptr) return firstNode;
        return find(curNode->second, value);
    }

    bool addNode(const std::string senior, const std::string junior) {
        auto seniorNode = find(this->root, senior);

        if (seniorNode == nullptr) {
            std::cout << senior << "를 찾을 수 없습니다. " << std::endl;
            return false;
        }
        if (seniorNode->first && seniorNode->second) {
            std::cout << senior << "아래에 가득차서 등록할 수 없습니다. " << std::endl;
            return false;
        }
        if (seniorNode->first == nullptr) {
            seniorNode->first = new node(junior);
        } else {
            seniorNode->second = new node(junior);
        }
        std::cout << senior << "아래에 " << junior << "를(을) 추가했습니다. " << std::endl;
        return true;
    }
};

#endif //CPPLEARN_BINARYTREE_HPP
