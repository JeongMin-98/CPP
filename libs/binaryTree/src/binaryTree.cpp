//
// Created by jeong on 2023-12-14.
//

#include "binaryTree.hpp"

binaryTree::binaryTree(const std::string pos) {
    root = new node(pos);
}

binaryTree::~binaryTree() {
    std::cout << "deconstructed" << std::endl;
    removeNode(root);
}

bool binaryTree::removeNode(node *curNode) {
    if (curNode == nullptr) {
        return false;
    }

    if (curNode->first != nullptr) {
        removeNode(curNode->first);
        curNode->first = nullptr;
    }
    if (curNode->second != nullptr) {
        removeNode(curNode->second);
        curNode->second = nullptr;
    }

    if (curNode->first == nullptr && curNode->second == nullptr) {
        std::cout << "curNode [" << curNode->position << "] deconstructed" << std::endl;
        auto temp = curNode;
        temp->first = nullptr;
        temp->second = nullptr;
        delete temp;
        return true;
    }
}

binaryTree::nodePtr binaryTree::find(node *curNode, const std::string value) {
    if (curNode == nullptr)
        return nullptr;
    if (curNode->position == value) {
        return curNode;
    }
    auto firstNode = find(curNode->first, value);
    if (firstNode != nullptr) return firstNode;
    return find(curNode->second, value);
}

bool binaryTree::addNode(const std::string senior, const std::string junior) {
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
    std::cout << "[" << senior << "] 아래에 [" << junior << "] 를(을) 추가했습니다. " << std::endl;
    return true;
}

void binaryTree::preOrder(node *start) {
    if (start == nullptr) return;

    std::cout << start->position << ", ";
    preOrder(start->first);
    preOrder(start->second);
}

void binaryTree::inOrder(node *start) {
    if (start == nullptr) return;

    inOrder(start->first);
    std::cout << start->position << ", ";
    inOrder(start->second);
}

void binaryTree::postOrder(node *start) {
    if (start == nullptr) return;

    postOrder(start->first);
    postOrder(start->second);
    std::cout << start->position << ", ";
}

binaryTree::nodePtr binaryTree::getRoot() {
    return this->root;
}

