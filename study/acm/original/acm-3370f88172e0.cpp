/*

*/
#include<bits/stdc++.h>
using namespace std;

int Add(int a,int b = 20,int c = 30) //如果某个位置有了默认值，那么从这起右面都必须有默认值
{                                    //如果函数声明有参数，实现就不能有，声明和实现只能有一个有默认参数
    return a+b+c;
}

void func(int a,int)  //进行站位
{
    cout << "hello world" << endl;
}
void func1(int a,int  = 10)  //还可以这样，直接不用传值；
{
    cout << "hello world" << endl;;
}
int main()
{
    cout << Add(10) << endl;    //不用传另外两个
    cout << Add(10,30) << endl; //传进去的会覆盖函数里的值
    func(10,10);
    func1(10);
}