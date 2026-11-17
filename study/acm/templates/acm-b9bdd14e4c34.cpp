#include<bits/stdc++.h>
using namespace std;

class Person
{
public:

    void operator()(string s)
    {
        cout << s << endl;
    }

};

class MyAdd
{
public:
    int operator()(int a,int b)
    {
        return a + b;
    }
};

void text01()
{
    Person p1;
    p1("Hello World");
    //由于使用起来，很像函数调用，所以称为仿函数
    MyAdd add;
    int ret = add(10,20);
    cout << ret << endl;
    cout << MyAdd()(100,100) << endl;//匿名对象
}


int main(){
    text01();
}