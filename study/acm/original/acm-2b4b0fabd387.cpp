/*
对于析构和构造函数
顺序是： 父类构造 -> 子类构造 -> 子类析构 -> 父类析构
*/

#include<bits/stdc++.h>
using namespace std;

//继承中的对象模型
class base
{
public:

    int a;

protected:

    int b;

private:

    int c;
};
//对象中的私有也会继承到子类中，占内存
//父类中所有非静态成员属性都会被继承到子类
//父类中私有成员属性 只是被编译器隐藏了，不能访问但是被继承下去了

class son:public base
{
public:

    int d;
};

void text01()
{
    son k;
    cout << sizeof(k) << endl;
}

int main(){
    text01();
}