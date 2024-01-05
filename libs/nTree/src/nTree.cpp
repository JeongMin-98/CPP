//
// Created by jeong on 2023-12-21.
//
#include "nTree.hpp"

vector<string> split(std::string str, const char delimiter) {
    vector<string> result;
    stringstream ss(str);
    string temp;

    while (getline(ss, temp, delimiter)) {
        result.push_back(temp);
    }

    return result;
}

FileSystem::nodePtr FileSystem::
findNode(FileSystem::nodePtr cur, std::string nodeName) {

    nodePtr foundNodePtr;
    if (cur->name == nodeName) {
        // When find targetNode.
        return cur;
    }
    if (cur->flag == 1) {
        // When targetNode is file and empty node.
        if (cur->children.empty()) {
            return nullptr;
        }
        // When targetNode is file and has any nodes.
        for (auto it: cur->children) {
            nodePtr tempPtr;
            tempPtr = findNode(it, nodeName);
            foundNodePtr = (tempPtr == nullptr ? foundNodePtr : tempPtr);
        }
        return foundNodePtr;
    }

}


void FileSystem::changeDir(const std::string path) {
    nodePtr destNode;
    vector<string> dirs = split(path, '/');
    // if path is absolute
    if (path[0] == '/') {
        destNode = findNode(root, dirs.back());
        current = (destNode == nullptr ? current : destNode);
        return;
    }
    // if path is relative
    destNode = findNode(current, dirs.back());
    current = (destNode == nullptr ? current : destNode);
    return;
}

void FileSystem::deleteNode(std::string fileName) {
    nodePtr targetNode = findNode(current, fileName);

}

void FileSystem::addNode(int fileType, std::string fileName) {
    // When you add New Node(file or Directory), You use this method.
    nodePtr newNode;
    newNode = new node(fileType, fileName);
    current->children.push_back(newNode);

}

void FileSystem::list() {
    // The current file system path is listed as follows.
    cout << "current path is " << (current->name == "/" ? "root" : current->name) << endl;
    for (auto it: current->children) {
        cout << (it->flag == 1 ? "/" : "") << it->name << " ";
    }
    cout << endl;
}

FileSystem::nodePtr FileSystem::printWorkingDir() {
    // Print working Directory.
    cout << current->name;
    return current;
}


