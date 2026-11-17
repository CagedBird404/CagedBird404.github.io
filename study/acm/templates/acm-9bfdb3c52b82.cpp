/*
菱形继承，又叫钻石继承
*/
#include<bits/stdc++.h>
using namespace std;

class animal
{
public:

    int a = 10;

};
//利用虚继承 解决菱形继承问题
//加上virtual 后animal被称为虚基类
//底层是将继承两个数据改为两个指针，sheep和tuo对yt传下去的是两个指针，他们对应一个数据
class sheep : virtual public animal
{

};

class tuo : virtual public animal
{};

class yt : public sheep , public tuo
{};

void text01()
{
    yt k;
    //这份数据 只需要一份就可以 但是菱形数据有两份 浪费资源
    
    k.sheep::a = 18;
    k.tuo::a = 28;
    cout << k.sheep::a << endl << k.tuo :: a << endl << k.a << endl;
}

int main(){
    text01();
}