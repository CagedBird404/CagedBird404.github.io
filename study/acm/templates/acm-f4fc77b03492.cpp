#include<bits/stdc++.h>
using namespace std;

class Person
{
    friend void text01();

public:
    Person(const Person& other) : a(new int(*other.a)) {}

    Person & operator=(const Person &p1)
    {
        if (this == &p1) return *this;
        // 先分配再释放，分配失败时保持当前对象有效。
        int* replacement = new int(*p1.a);
        //先释放本身的堆区数据
        if(a != NULL)
        {
            delete a;
            a = NULL;
        }
        a = replacement;
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
    p2 = p1; //这里调用自定义赋值，进行深拷贝；默认浅拷贝才会导致重复释放
    cout << *p2.a << endl;
    Person p3(30);
    p1 = p2 = p3;
    cout << *p1.a << " " << *p2.a << " " << *p3.a << endl;
} 

int main(){
    text01();
}