#include<bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int> pque;//输入进去的自动排大小，从小到大
    pque.push(1);
    pque.push(3);
    pque.push(6);
    pque.push(2);
    pque.emplace(8);
    //如果里面是两个，优先排第一个
    cout<<pque.top()<<endl;//输出最大值（最后的）
    pque.pop();//删去最大元素
    priority_queue<int,vector<int>,greater<int>> pque2;//变为小顶堆，所有都与普通的相反，从大到小
    //其中元素不可修改，只可以操作堆顶
    //储存int类型元素，底层用vector作为容器
}