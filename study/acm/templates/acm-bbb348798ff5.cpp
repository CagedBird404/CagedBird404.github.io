/*
列表法：作用为初始化属性
语法：构造函数():属性1(值1),属性2(值2)
*/
#include<bits/stdc++.h>
using namespace std;

class Person
{
public:
    int a;
    int b;
    int c;
    //传统初始化操作
    Person(int aa,int bb,int cc)
    {
        a = aa;
        b = bb;
        c = cc;
    }

    //初始化列表
    Person(int aa,int bb,int cc):a(aa),b(bb),c(cc)
    {

    }
};
int main()
{

}