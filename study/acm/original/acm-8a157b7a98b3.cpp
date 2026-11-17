/*
成员属性设置私有
1、可以自己控制读写权限
2、对于写可以检测数据有效性
*/
#include<bits/stdc++.h>
using namespace std;

class Person
{
private:
    string name;

    int Age = 18;

    string idol;

public:
    void setname(string s)//可读可写
    {
        name = s;
    }
    string getname()
    {
        return name;
    }
    int getage()   //只读状态，不能输入
    {              //只写状态，不能输出
        return Age;
    }
    int setAge(int a)
    {
        if(a > 0 && a <= 150) Age = a;
        else cout << "年龄" << a << "输入有误，赋值失败"<<endl;
        return 0;
    }
};
int main()
{
    Person p;
    p.setname("张三");
    cout << p.getname() << " " << p.getage();
    int a;
    cin >> a;
    p.setAge(a);
}