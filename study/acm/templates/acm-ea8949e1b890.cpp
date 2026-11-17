#include<bits/stdc++.h>
using namespace std;
int main(){
    queue<int> que;
    que.push(1);
    que.push(2);
    que.push(3);
    cout<<que.front()<<endl;
    cout<<que.back()<<endl;
    cout<<que.size()<<endl;
    cout<<que.empty()<<endl;
    que.pop();//删第一个
}