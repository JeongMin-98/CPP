//
// Created by jeong on 2023-12-14.
//

#ifndef CPPLEARN_BINARYTREE_HPP
#define CPPLEARN_BINARYTREE_HPP

#include<iostream>
#include<queue>



template<typename T>
struct node {
    T data;
    node *left;
    node *right;

    node(T pos) : data(pos), left(nullptr), right(nullptr) {}
};


class binaryTree {
public:
    using nodePtr = node<std::string> *;
private:
    nodePtr root;

    bool removeNode(nodePtr curNode);

public:
    binaryTree() : root(nullptr) {}

    binaryTree(const std::string pos);

    ~binaryTree();

    nodePtr getRoot();

    nodePtr find(nodePtr curNode, const std::string value);

    void preOrder(nodePtr start);

    void inOrder(nodePtr start);

    void postOrder(nodePtr start);

    bool addNode(const std::string &senior, const std::string &junior);
};

template<typename T>
class BinarySearchTree {
public:
    using Node = node<T>;
    using nodePtr = Node *;
private:
    nodePtr root = nullptr;

public:

    ~BinarySearchTree<T>();

    BinarySearchTree<T>::nodePtr find(T value);

    void insert(T value);

    void deleteNode(nodePtr curNode);

    void inOrder();

private:
    nodePtr find_impl(nodePtr curNode, T value);

    void insert_impl(nodePtr curNode, T value);

    void deleteNodeImpl(nodePtr curNode);

    void inOrder_impl(nodePtr start);
};

template<typename T>
void BinarySearchTree<T>::inOrder() {
    inOrder_impl(root);
}

template<typename T>
void BinarySearchTree<T>::inOrder_impl(BinarySearchTree::nodePtr start) {
    if (!start) return;

    inOrder_impl(start->left);
    std::cout << start->data << " ";
    inOrder_impl(start->right);
}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree<T>() {
    deleteNode(root);
}

template<typename T>
typename BinarySearchTree<T>::nodePtr BinarySearchTree<T>::find_impl(nodePtr curNode, T value) {
    if (curNode == nullptr) {
        std::cout << "No value in tree" << std::endl;
        return nullptr;
    }

    if (value == curNode->data) {
        std::cout << "find value" << std::endl;
        return curNode;
    }

    if (value < curNode->data) {
        std::cout << "your value is smaller than curNode data " << curNode->data << " So, step left node" << std::endl;
        return find_impl(curNode->left, value);
    } else {
        std::cout << "your value is bigger than curNode data " << curNode->data << " So, step right node" << std::endl;
        return find_impl(curNode->right, value);
    }
}

template<typename T>
typename BinarySearchTree<T>::nodePtr BinarySearchTree<T>::find(T value) {
    return find_impl(root, value);
}

template<typename T>
void BinarySearchTree<T>::insert_impl(BinarySearchTree::nodePtr curNode, T value) {
    if (value < curNode->data) {
        if (curNode->left == nullptr) {
            curNode->left = new Node(value);
            return;
        } else {
            insert_impl(curNode->left, value);
        }
    } else {
        if (curNode->right == nullptr) {
            curNode->right = new Node(value);
            return;
        } else {
            insert_impl(curNode->right, value);
        }
    }
}

template<typename T>
void BinarySearchTree<T>::insert(T value) {
    if (root == nullptr) {
        root = new Node(value);
    } else {
        insert_impl(root, value);
    }
}

template<typename T>
void BinarySearchTree<T>::deleteNodeImpl(BinarySearchTree::nodePtr curNode) {

    if (curNode->left != nullptr) {
        deleteNodeImpl(curNode->left);
        curNode->left = nullptr;
    }
    if (curNode->right != nullptr) {
        deleteNodeImpl(curNode->right);
        curNode->right = nullptr;
    }

    if (curNode->left == nullptr && curNode->right == nullptr) {
        std::cout << "curNode [" << curNode->data << "] deconstructed" << std::endl;
        auto temp = curNode;
        temp->left = nullptr;
        temp->right = nullptr;
        delete temp;
        return;
    }
}

template<typename T>
void BinarySearchTree<T>::deleteNode(BinarySearchTree::nodePtr curNode) {
    // for deconstructor , If program exits, deconsturct tree.
    if (curNode != nullptr) {
        deleteNodeImpl(curNode);
    }
}


#endif //CPPLEARN_BINARYTREE_HPP
