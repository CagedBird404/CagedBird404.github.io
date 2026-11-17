#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> a={1,2,3,4,5};
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<endl;
    }//用于线性
    for(vector<int>::iterator it=a.begin();it!=a.end();it++)
    {
        cout<<*it<<endl;
    }//用于非线性
    //.begain头迭代器.end尾迭代器.rbegain.rend反向输出
    //迭代器之间可以相减
    //prev(it)返回it前面的迭代器
    //next(it)返回if后的迭代器
}    