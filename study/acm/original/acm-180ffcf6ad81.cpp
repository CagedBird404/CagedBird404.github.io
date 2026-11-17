#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<double> stk;
    stk.push(1.0)
    stk.push(1.4)
    cout<<stk.top()<<endl;//最后一个进栈的，为top
    cout<<stk.size()<<endl;
    cout<<stk.enpty()<<endl;
    stk.pop();
}