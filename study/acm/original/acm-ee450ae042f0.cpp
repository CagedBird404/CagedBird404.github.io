/*
作用：函数名可以形同，提高复用性

函数重载满足条件：
* 同一个作用域下
* 函数名称相同
* 函数参数类型不同 或者 个数不同 或者 顺序不同
*/
#include<bits/stdc++.h>
using namespace std;

void func()
{
    cout << "hello world";
}

void func(int a,double b)
{
    cout << "hello world";
}
void func(double a,int b)    //这个类型必须相同，就像这些都是void
{
    cout << "hello world";
}

//函数重载注意事项
//1、引用作为重载条件
//2、函数语法相同，要避免重载时存在多种可以处理的情况
void cc(int &a)
{
    cout << "cc" << endl;
}
void cc(const int &a)
{
    cout << "ccc" << endl;
}
int main(){
    int a = 10;
    func();
    func(10,3.14);
    func(3.14,10);
    cc(a);//调用,加了引用，那么就要传变量
    cc(10);//调用const的
}