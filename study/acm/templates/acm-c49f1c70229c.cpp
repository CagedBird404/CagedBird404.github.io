/*
成员函数会被重复多次使用，实际上他们访问的都是一块代码
问题：那么他们是怎么区分哪个对象调用自己的？

用this指针
* this指针指向被调用的成员函数所属的对象
this指针是隐含在每一个非静态成员函数的一种指针
this指针不需要定义，直接使用即可

作用：
1、当形参和成员变量同名时，可以用this指针来区分
2、在类的非静态成员函数返回对象本身时，可以用 return *this
*/
#include<bits/stdc++.h>
using namespace std;

class Person
{
public:
    //解决名称冲突
    Person(int age)
    {
        this -> age = age;
    }

    Person& Personadd(Person &p)
    {
        this -> age += p.age;
        return *this; //返回的是p2本身
    }
    int age;
};

void text01()
{
    Person p1(18);
    cout << p1.age;
}

void text02()
{
    Person p1(10);
    Person p2(10);
    //链式编程思想
    p2.Personadd(p1).Personadd(p1).Personadd(p1);
    cout << p2.age << endl;
}
int main()
{
    text02();
}