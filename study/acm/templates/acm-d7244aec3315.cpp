/*
静态成员分为：静态成员变量，静态成员函数

静态成员变量
    1、所有对象共享一份数据,所有成员都指向
    2.在编译阶段分配内存
    3.类内声明，类内初始化   必须有初始值

静态成员函数
    1.所有对象共享一个函数
    2.静态成员函数只能访问静态成员变量
*/

//静态成员变量
#include<bits/stdc++.h>
using namespace std;

class Person
{
public:
    //所有对象都共享同一份数据
    static int a;//类内声明，类外初始化

    static void func()
    {
        a = 200;
        cout << "你被调用了" << endl;
    }
    //静态成员变量也有访问权限
private:
    static int b;
};

int Person::a = 100;
int Person::b = 200;

void text01()
{
    //静态成员变量 不属于某个变量 所有对象都共享同一份数据
    //静态成员变量有两种访问方式
    //1、通过对象进行访问

    Person p1;
    cout << p1.a << endl;
    //2、通过类名进行访问

    cout << Person::a << endl;
}

void text02()
{
    Person p1;
    p1.func();
    Person::func();
}

int main()
{
    Person p1;
    cout << p1.a << endl;
    Person p2;
    p2.a = 200;
    cout << p1.a << endl;;
}
