
//
// Created by jeong on 2023-12-27.
//

#include "nTree/nTree.hpp"

int main() {
    FileSystem fs;
    fs.list();
    fs.printWorkingDir();

    fs.addNode(1, "test");
    fs.addNode(0, "file");

    fs.list();

    cout << fs.findNode(fs.printWorkingDir(), "test")->name;
    cout << endl;
    cout << fs.findNode(fs.printWorkingDir(), "file")->name;

    cout << endl;
    fs.changeDir("/test");
    fs.printWorkingDir();


    for (auto it: fs.printWorkingDir()->children) {
        delete it;
    }
}