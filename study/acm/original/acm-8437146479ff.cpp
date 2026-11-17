/*
引用作用：给变量起别名
引用和指针区别：引用只是起别名，不占内存
语法：数据类型 &别名 = 原名

例：
int a = 10;
int &b = a;
b = 20;
那么输出a时，结果也是20
本质上就是让a和b有相同的地址

引用注意事项：
1、引用必须初始化
例： int &b; //错误
2、引用一旦初始化后，就不可以更改
例：
int a = 10;
int &b = a;
int c = 20;
b = c;   //这属于赋值操作，不是换

引用做函数参数
作用：函数传参时，可以让形参修饰实参

例：
int Swap(int &a,int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

引用本质：
int &b = a;
本质上是 int* const b = &a;
这也是不能更改的原因，因为他已经是固定地址了

常量引用
作用：常量引用主要用来修饰形参，防止形参改变实参
例：
const int &ref = 10;
加上const后 编译器将代码修改为 int temp = 10; &ref = temp;
意思就是创建一个临时变量，将这个变量的地址给ref
加入const后变成只读状态，不可以修改
*/
#include<bits/stdc++.h>
using namespace std;
void show(const int &val) //防止其进行更改
{
    cout << val << endl;
    cout << val << endl;
}
int main()
{
    int a = 100;
    show(a);
    cout << a << endl;
}