/*
c++面向对象三大特征：封装，继承，多态
c++认为 万事万物都皆为对象，对象上有其属性和行为
具有相同性质的对象，我们抽象为类

封装的意义：
* 将属性和行为作为一个整体，表现生活中的事物
* 将属性和行为加以权限控制

一、
    在设计类的时候，属性和行为写在一起，表现事物
语法： class 类名{ 访问权限： 属性 / 行为};
*/
//实际化：通过一个类 创建一个对象
#include<bits/stdc++.h>
using namespace std;
const double PI = 3.14;

//例1：设计一个圆类，求圆周长
class yuan{
    //访问权限：
public:

    //属性
    //半径
    int r;

    //行为
    //获取圆的周长
    double zhou()
    {
        return 2 * PI * r;
    }
};

//例2:设计学生类
class student{
public:
//类中的属性和行为我们统一称为 成员
//属性 也叫 成员属性 或者 成员变量
//行为 也叫 成员函数 或者 成员方法
    string m_name;
    int id;
    void show()
    {
        cout << m_name << " " << id << endl;
    }
    void setname(string s)
    {
        m_name = s;
    }
    void setid(int a)
    {
        id = a;
    }
};
int main()
{
    //通过圆类，创建具体的圆（对象）
    yuan c1;
    c1.r = 4;
    cout << c1.zhou() << endl;
    student m1;
    m1.m_name = "张三";
    m1.id = 2504;
    m1.show();
    student m2;
    m2.setname("李四");
    m2.setid(999);
    m2.show();
}