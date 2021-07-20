//
// Created by zhaoz on 5/12/2021.
//

#include <iostream>
#include <vector>

void printVector(std::vector<int> v) {
    for (auto it = v.begin(); it != v.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
int main() {
    std::vector<int> v {1,2,3};
    std::vector<int> copy;
    printVector(copy);
    copy = v;
    printVector(v);
    printVector(copy);
    v.insert(v.end(), copy.begin(), copy.end());
    printVector(v);
}

