#include<bits/stdc++.h>
using namespace std;

class Person
{
    friend ostream & operator<<(ostream& cout, Person p1);

public:

    //重载前置++运算符
    Person& operator++()
    {
        this -> a++;
        this -> b++;
        return *this;
    }

    Person operator++(int) //int 代表占位参数，可以用于区分前置++和后置++
    {
        Person p1 = *this;
        this -> a++;
        this -> b++;
        return p1;// 返回值，返回的引用是局部引用，会被释放
    }
    //重载后置++运算符
    
    int a = 0;
    int b = 0;
};

ostream & operator<<(ostream& cout, Person p1)
{
    cout << p1.a + p1.b;
    return cout;
}



void text01()
{
    Person p1;
    cout << p1 << endl;
    cout << ++(++p1) << endl;
    cout << p1 << endl;
}

void text02()
{
    Person p1;
    cout << p1 << endl;
    cout << p1++ << endl;
    cout << p1 << endl;
}

int main(){
    text01();
    text02();
}