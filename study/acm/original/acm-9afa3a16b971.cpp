/*
调用使用时机一般有三种
* 使用一个已经创造完毕的对象来初始化一个新对象
* 值传递的方式给函数参数传值
* 以值方式返回局部对象
*/
#include<bits/stdc++.h>
using namespace std;

class Person{
public:
    Person(){
        cout << "无参构造函数！" << endl;
        mAge = 0;
    }
    Person(int age)
    {
        cout << "有参构造函数！" << endl;
        mAge = age;
    }
    Person(const Person &p)
    {
        cout << "拷贝构造函数！" << endl;
        mAge = p.mAge;
    }
    ~Person()
    {
        cout << "析构函数！" << endl;
    }

private:
    int mAge;
};

//值传递的方式给函数参数传值
void dowork(Person p) //这只是一个临时的参数，属于新构造一个，不会改变原p的值
{
     
}

void text1()
{
    Person p;
    dowork(p);//属于拷贝构造函数
}

//值方式返回局部对象
Person dowork2()
{
    Person p1;
    return p1;
}

void text3()
{
    Person p = dowork2();// 属于拷贝构造函数
}
int main()
{
    //使用一个已经创造完毕的对象来初始化一个新对象
    Person p1(20);
    Person p2(p1);
}