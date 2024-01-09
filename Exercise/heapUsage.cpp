//
// Created by jeong on 2024-01-09.
//
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

void print(const vector<int> &arr) {
    for (const auto& e: arr){
        std::cout << e << ' ';
    }
    std::cout << endl;
}


int main() {
    priority_queue<int> maxHeap;

    for (int i = 0; i < 4; i++) {
        int input;
        cin >> input;
        maxHeap.push(input);
    }

//    while(!maxHeap.empty()){
//        cout << maxHeap.top() << " ";
//        maxHeap.pop();
//    }
//    cout << endl;

    vector<int> list = {1, 1, 3, 5, 2};

    std::make_heap(list.begin(), list.end());
    print(list);

}