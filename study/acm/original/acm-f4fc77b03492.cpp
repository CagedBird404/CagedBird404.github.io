#include<bits/stdc++.h>
using namespace std;

class Person
{
    friend void text01();

public:
    Person & operator=(Person &p1)
    {
        //先释放本身的堆区数据
        if(a != NULL)
        {
            delete a;
            a = NULL;
        }
        a = new int(*p1.a);
        return *this;
    }

    Person(int age)
    {
        a = new int(age);
    }

    ~Person()
    {
        if(a != NULL)
        {
            delete a;
            a = NULL;
        }
    }
private:
    int *a ;

};

void text01()
{
    Person p1(18);
    cout << *p1.a << endl;
    Person p2(20);
    p2 = p1; //浅拷贝两个对应一个内存空间，会重复释放
    cout << *p2.a << endl;
    Person p3(30);
    p1 = p2 = p3;
    cout << *p1.a << " " << *p2.a << " " << *p3.a << endl;
} 

int main(){
    text01();
}