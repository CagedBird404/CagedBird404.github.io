/*
list 不支持随机访问，
可以在已知位置插入删除，复杂度O1
缺点是占空间很大

*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    list<int> lst = {1,2,3};
    lst.push_back(4);//结尾放
    lst.push_front(0);//开头放
    auto it = lst.begin();
    advance(it,2);//将某个迭代器移动，后面数字代表n，n>0代表向前移动，反之
                  //他是通用的，很多容器都可以用
    lst.insert(it,99);//将99送到第2个位置
    lst.erase(it);//删除当前位置
    lst.sort();//list自带函数，因为list不能用正常的sort，这个内置函数也可以用表达式
    lst.sort([](int a,int b){
        return a > b;
    });
    lst.unique();//自带的去重
    list<int> a = {1,2,3}
    auto iit = lst.begin();
    advance(it,1);
    lst.splice(it,a);//将a的元素都搬到lst的位置上
}