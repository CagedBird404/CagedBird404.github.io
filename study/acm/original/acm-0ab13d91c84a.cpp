/*
继承好处：减少重复代码

语法 ： class 子类: 继承方式 父类
子类也称为派生类，父类也称为基类
*/

#include<bits/stdc++.h>
using namespace std;

class gg
{
public:
    void sh()
    {
        cout << "kaitou" << endl;
    }
    void mu()
    {
        cout << "mulu" << endl;
    }
    void ji()
    {
        cout << "jiewei" << endl;
    }

};

class Gcc : public gg
{
public:
    void zj()
    {
        cout << "gcc shipin" << endl;
    }
};
class java : public gg
{
public:

    void zj()
    {
        cout << "java shipin" << endl;
    }

};

class python : public gg
{
public:

    void zj()
    {
        cout << "python shipin" << endl;
    }
};

void text01()
{
    java ja;
    ja.sh(),ja.mu(),ja.zj(),ja.ji();
    python py;
    py.sh(),py.mu(),py.zj(),py.ji();
    Gcc gk;
    gk.sh(),gk.mu(),gk.zj(),gk.ji();
}

int main(){
    text01();
}