/*
左移运算符的重载
*/

#include<bits/stdc++.h>
using namespace std;

class Person
{
    friend ostream & operator<<(ostream &cout,Person p);

private:

    //一般不用成员函数来重载左移运算符。因为cout会在变量左面
    //void operator<<( cout ){}

    int a = 0;
    int b = 0;

};

ostream & operator<<(ostream &cout,Person p) //所有要用全局函数
{
    cout << p.a + p.b;
    return cout;
}

void text01()
{
    Person p1;
    cout << p1;
}

int main(){
    text01();
}