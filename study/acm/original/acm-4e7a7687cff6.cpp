/*
对于search可以在一个大容器中返回小容器出现的位置
和find类似但是这个是对于两个容器
复杂度为暴力
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5, 3, 4};
    std::vector<int> sub = {3, 4};

    auto it = std::search(v.begin(), v.end(), sub.begin(), sub.end());

    if (it != v.end()) {
        std::cout << "Found at position: " << it - v.begin() << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }
}