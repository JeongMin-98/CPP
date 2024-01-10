//
// Created by jeong on 2024-01-08.
//
#include <iostream>
#include <queue>
#include <vector>

class median {

    std::priority_queue<int> maxHeap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
public:
    double get() {
        if (maxHeap.size() == minHeap.size())
            return (maxHeap.top() + minHeap.top()) / 2.0;
        if (maxHeap.size() < minHeap.size())
            return minHeap.top();
        return maxHeap.top();
    }

    void insert(int data) {
        if (maxHeap.size() == 0) {
            maxHeap.push(data);
            return;
        }
        if (maxHeap.size() == minHeap.size()) {
            if (data <= get()) {
                maxHeap.push(data);
            } else {
                minHeap.push(data);
            }
            return;
        }
        if (maxHeap.size() > minHeap.size()) {
            if (data < get()) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(data);
            } else {
                minHeap.push(data);
            }
            return;
        }
        // maxHeap.size() < minHeap.size()
        if (data > get()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
            minHeap.push(data);
        } else {
            maxHeap.push(data);
        }
    }
};

int main() {
    median med;
    int endFlag = 0;
    int data;
    while (!endFlag) {
        std::cout << "원하는 값을 입력하시요. ";
        std::cin >> data;
        std::cout << std::endl;
        med.insert(data);
        std::cout << data << "을 입력했을 때 중간 값은 " << med.get() << "입니다. " << std::endl;
        std::cout << "계속하시겠습니까? 계속하려면 1, 중단하려면 0을 누르시요. ";
        std::cin >> endFlag;
        endFlag = (endFlag == 1 ? 0 : 1);
    }
}