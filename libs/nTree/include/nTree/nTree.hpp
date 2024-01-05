//
// Created by jeong on 2023-12-21.
//

#ifndef CPPLEARN_NTREE_HPP
#define CPPLEARN_NTREE_HPP

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct SystemNode;

struct nTreeNode {
    int data;
    std::vector<SystemNode *> children;
};

struct SystemNode : nTreeNode {
    int flag;
    std::string name;

    SystemNode(int fileType, std::string fileName) {
        name = fileName;
        if (fileType == 0) {
            // if fileType is 0, SystemNode is file.
            flag = fileType;
            return;
        }
        if (fileType == 1) {
            // if fileType is 1, SystemNode is folder
            flag = fileType;
            return;
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const SystemNode &node) {
        return (os << (node.flag == 1 ? "/" : "") << node.name << " ");
    }
};

vector<string> split(std::string str, const char delimiter);

class FileSystem {
    using node = SystemNode;
    using nodePtr = node *;

private:
    nodePtr root = nullptr;
    nodePtr current = nullptr;

public:
//    nodePtr root = nullptr;
//    nodePtr current = nullptr;

    FileSystem() {
        root = new node(1, "/");
        current = root;
    }

    ~FileSystem() {
        delete root;
    }

    void list();

    void addNode(int fileType, std::string fileName);

    void deleteNode(std::string fileName);

    void changeDir(const std::string path);

    nodePtr printWorkingDir();

    nodePtr findNode(nodePtr cur, std::string nodeName);
};

#endif //CPPLEARN_NTREE_HPP
