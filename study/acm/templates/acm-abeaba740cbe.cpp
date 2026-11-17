/*
常函数：
    * 成员函数加const后我们称这个函数为常函数
    * 常函数内不可以修改成员属性
    * 成员属性声明时加关键字mutable后，在常函数中依旧可以修改

常对象：
    * 声明对象前加const称该对象为常对象
    * 常对象只能调用常函数
*/
#include<bits/stdc++.h>
using namespace std;

class Person
{
public:
    //this指针本质是指针常量，指针的指向是不可以修改的 可理解为 Person* const（this 不能被重新赋值）。
    void showPerson() const // 通过 this 访问对象时，对象被视为 const；mutable 成员除外。
    {
        //this -> a = 100;
        this -> b = 100;
    }
    int a = 0;
    mutable int b = 0; //加上mutable后即使加上const也可以修改
};

int main()
{
    //常对象，属性不可以修改
    const Person p;
    //但是mutable修饰后可以修改
    p.b = 100;
    //常对象只能调用常函数
}