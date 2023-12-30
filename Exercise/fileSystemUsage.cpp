//
// Created by jeong on 2023-12-27.
//

#include "nTree/nTree.hpp"

int main() {
    FileSystem fs;
    fs.list();

    fs.addNode(1, "test");
    fs.addNode(0, "file");

    fs.list();

    fs.findNode(fs.current, "test");
    fs.findNode(fs.current, "file");


    for (auto it: fs.current->children) {
        delete it;
    }
}