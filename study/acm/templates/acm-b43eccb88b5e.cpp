/*
在c++中成员变量和成员函数分开存储
只有非静态成员变量才属于类上的对象
*/
#include<bits/stdc++.h>
using namespace std;

class Person
{
public:
    int a;
    static int b;
};
int Person::b = 10;

int main()
{
    Person p1;//空的情况下，占用一个字节
              //非空才是正常字节计算
              //静态是不占字节的，他不属于类上对象
              //成员函数都不属于类的对象上
}