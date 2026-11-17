/*
运算符重载定义：对已有的运算符重新定义，赋予其另一种功能，以适应不同数据类型

对于内置的数据类型，编译器知道如何运算
*/
#include<bits/stdc++.h>
using namespace std;

class Person
{
public:

    int a,b;

//成员函数重载
    Person operator+(Person &p)
    {
        Person temp;
        temp.a = this -> a + p.a;
        temp.b = this -> b + p.b;
        return temp;
    }

    Person()
    {
        a = 10;
        b = 10;
    }
};

// 与 Person 相加采用上方成员版本，避免重载歧义。
Person operator+(Person &p1,int num)
{
    Person temp;
    temp.a = p1.a + num;
    temp.b = p1.b + num;
    return temp;
}

void text01()
{
    Person p1;
    p1.a = 10;
    p1.b = 29;
    Person p2;
    p2.a = 38;
    p2.b = 48;
    //成员函数重载本质调用：Person p3 = p1.operator+(p2);

    //全局函数重载本质调用： person p3 = operator+(p1,p2);
    Person p3 = p1 + p2;
    cout << p3.a << " " << p3.b << endl;

    Person p4 = p3 + 100;
    cout << p4.a << " " << p4.b;
}

int main(){
    text01();   
}