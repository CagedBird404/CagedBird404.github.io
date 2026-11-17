/*
两种分类方式：
    1、按照参数：有参构造和无参构造
    2、按照类型：普通构造和拷贝构造

三种调用方法：
    1、括号法
    2、显示法
    3、隐式转换法
*/
#include<bits/stdc++.h>
using namespace std;

class Person
{
public:
    //普通构造函数
    Person()//默认构造函数
    {
        cout << "无参构造" << endl;
    }
    Person(int a)
    {
        cout << "有参构造函数" << endl;
    }
    //拷贝构造函数
    Person(const Person &p)
    {
        //将传入的这个人身上的属性，传到我身上
        cout << "拷贝构造函数" << endl;
        age = p.age;
    }

    int age = 10;
};

void text1()
{
    //1、括号法
    Person p; // 默认构造函数不要加()
              // 因为加括号的代码，编译器会认为是一个函数声明,不会认为在创建对象
              // 例如 void cc();
    Person p1(10);
    Person(p1); // 拷贝构造函数
    cout << p2.age << endl;
    cout << p3.age << endl;

    //2、显示法
    Person p1;
    Person p2 = Person(10);//有参构造
    Person p3 = Person(p2);//拷贝构造
    //不能利用拷贝构造函数，初始化匿名对象，例如  Person(p1);这可以看成再创建一个叫p3的对象
    Person(10);//匿名对象， 特点：当执行完结束后，系统会立即回收,所以会执行析构函数

    //3、隐式转换法
    Person p4 = 10;//相当于Person p4 = Person(10);
    Person p5 = p4;//拷贝构造
}
int main()
{
    text1();
}