/*
c++中空指针也是可以调用成员函数的，但是也要主要有没有用到this指针

如果用到this指针，需要加以判断保证代码的健壮性
*/
#include<bits/stdc++.h>
using namespace std;

class Person
{
public:

void showClassName()
{
    cout << "this is a person class" << endl;
}

void showAge()
{
    if(this == NULL) return;
    cout << "Age = " <<this -> Age << endl;
}

    int Age; 
};

void text01()
{
    Person * p = NULL; //空指针代表本来也没有建立对象
    p -> showClassName();//可以运行
    p -> showAge();//不可以,报错原因是因为传入的指针为空
}

int main()
{

}