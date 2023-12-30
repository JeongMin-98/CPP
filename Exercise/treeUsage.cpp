//
// Created by jeong on 2023-12-14.
//
#include "binaryTree/binaryTree.hpp"
#include <iostream>
int main() {

    binaryTree tree("CEO");

    tree.addNode("CEO", "부사장");
    tree.addNode("부사장", "IT부장");
    tree.addNode("부사장", "마케팅부장");
    tree.addNode("IT부장", "보안팀장");
    tree.addNode("IT부장", "웹개발팀장");
    tree.addNode("마케팅부장", "물류팀장");
    tree.addNode("마케팅부장", "홍보팀장");
    tree.addNode("부사장", "재무부장");

    tree.preOrder(tree.getRoot());
    std::cout << std::endl;
    tree.inOrder(tree.getRoot());
    std::cout << std::endl;
    tree.postOrder(tree.getRoot());
    std::cout << std::endl;

    std::cout << "level Order" << std::endl;
//    tree.levelOrder(tree.getRoot());
    return 0;

}