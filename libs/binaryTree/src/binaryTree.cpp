//
// Created by jeong on 2023-12-14.
//

#include "binaryTree.hpp"

binaryTree::binaryTree(const std::string value) {
    root = new node<std::string>(value);
}

binaryTree::~binaryTree() {
    std::cout << "deconstructed" << std::endl;
    removeNode(root);
}

bool binaryTree::removeNode(nodePtr curNode) {
    if (curNode == nullptr) {
        return false;
    }

    if (curNode->left != nullptr) {
        removeNode(curNode->left);
        curNode->left = nullptr;
    }
    if (curNode->right != nullptr) {
        removeNode(curNode->right);
        curNode->right = nullptr;
    }

    if (curNode->left == nullptr && curNode->right == nullptr) {
        std::cout << "curNode [" << curNode->data << "] deconstructed" << std::endl;
        auto temp = curNode;
        temp->left = nullptr;
        temp->right = nullptr;
        delete temp;
        return true;
    }
    return false;
}

binaryTree::nodePtr binaryTree::find(nodePtr curNode, const std::string value) {
    if (curNode == nullptr)
        return nullptr;
    if (curNode->data == value) {
        return curNode;
    }
    auto firstNode = find(curNode->left, value);
    if (firstNode != nullptr) return firstNode;
    return find(curNode->right, value);
}

bool binaryTree::addNode(const std::string &senior, const std::string &junior) {
    auto seniorNode = find(this->root, senior);

    if (seniorNode == nullptr) {
        std::cout << senior << "를 찾을 수 없습니다. " << std::endl;
        return false;
    }
    if (seniorNode->left && seniorNode->right) {
        std::cout << senior << "아래에 가득차서 등록할 수 없습니다. " << std::endl;
        return false;
    }
    if (seniorNode->left == nullptr) {
        seniorNode->left = new node<std::string>(junior);
    } else {
        seniorNode->right = new node<std::string>(junior);
    }
    std::cout << "[" << senior << "] 아래에 [" << junior << "] 를(을) 추가했습니다. " << std::endl;
    return true;
}

void binaryTree::preOrder(nodePtr start) {
    if (start == nullptr) return;

    std::cout << start->data << ", ";
    preOrder(start->left);
    preOrder(start->right);
}

void binaryTree::inOrder(nodePtr start) {
    if (start == nullptr) return;

    inOrder(start->left);
    std::cout << start->data << ", ";
    inOrder(start->right);
}

void binaryTree::postOrder(nodePtr start) {
    if (start == nullptr) return;

    postOrder(start->left);
    postOrder(start->right);
    std::cout << start->data << ", ";
}

binaryTree::nodePtr binaryTree::getRoot() {
    return this->root;
}

