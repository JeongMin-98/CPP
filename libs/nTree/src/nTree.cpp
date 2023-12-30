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
        return cur;
    }
    if (cur->children.empty()) {
        return nullptr;
    }
    for (auto it: cur->children) {
        nodePtr tempPtr;
        tempPtr = findNode(it, nodeName);
        foundNodePtr = (tempPtr == nullptr ? foundNodePtr : tempPtr);
    }
    return foundNodePtr;
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

void FileSystem::addNode(int fileType, std::string fileName) {
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
    cout << current->name;
    return current;
}
