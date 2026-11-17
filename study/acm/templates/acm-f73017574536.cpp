/*
三种权限：
1、public    公共权限    成员 类内可以访问  类外可以访问
2、protected 保护权限    成员 类内可以访问  类外不可以访问    儿子可以访问父亲中保护的内容
3、private   私有权限    成员 类内可以访问  类外不可以访问    儿子不可以访问父亲的私有内容

struct 和 class区别：
struct 默认是 公共 public
class  默认是 私有 private
*/
#include<bits/stdc++.h>
using namespace std;

class Person
{
public:
    string name;

protected:
    string car_name;

private:
    int passworld;

public:
    void func()
    {
        name = "张三";
        car_name = "拖拉机";
        passworld = 20000;
    }
};

int main()
{
    Person p1;
    p1.name = "李四";
    // p1.car_name = "奔驰";   类外不可以更改
}