#include<bits/stdc++.h>
using namespace std;
int main(){
    deque<int> d;//空队列
    deque<int> d2(n,val);// 里面有n个 val
    d.push_back(val); // 尾部插入
    d.push_front(val) // 头部插入
    d.pop_back(); // 删除尾部
    d.pop_front(); // 删除头部
    d[i]; //访问下标i的元素（无越界检测）
    d.at(i); //访问下标i的元素（有越界检查）
    d.front();// 返回头部
    d.back(); // 返回尾部
    d.size();
    d.insert(pos,val); // 在pos处插入val
    d.erase(pos); // 删除迭代器pos处元素
}