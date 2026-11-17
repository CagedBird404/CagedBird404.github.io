/*
浅拷贝：简单的赋值拷贝操作
深拷贝：在堆区重新申请空间，进行拷贝操作
*/
#include<bits/stdc++.h>
using namespace std;

class Person
{
public:
    Person()
    {
        cout << "默认构造函数调用" << endl;
    }
    Person(int age,int height)
    {
        cout << "有参构造函数"  << endl;
        Age = age;
        Height = new int(height);//由我们开启，就要由我们释放
    }
    //自己创建一个深拷贝
    Person(const Person &p)
    {
        cout << "拷贝构造函数" << endl;
        Age = p.Age;
        Height = new int(*p.Height); 
    }
    ~Person()
    {
        //在析构函数中，将堆区开辟数据释放
        if(Height != NULL)
        {
            delete Height;
            Height = NULL;
        }
        cout << "析构函数调用" << endl;
    }
    int Age;
    int *Height;//指针
};

void text1()
{
    Person p1(18,185);
    Person p2(p1);
    //浅拷贝是将数据直接拷贝过去，即使是地址，也是直接过去，所以p2先进行释放，p1再释放，就会冲突
    //深拷贝会再创建一块堆区内存，和p1数据一样，但是地址不一样
}
int main()
{
    text1();
}