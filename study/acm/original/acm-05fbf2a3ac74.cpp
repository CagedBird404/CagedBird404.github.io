/*
对于子类和父类同名的成员
    子类成员直接访问就可以
    父类成员要加作用域
*/

/*
对于静态成员也是同理
*/
#include<bits/stdc++.h>
using namespace std;

class base
{
public:

    int a;

    void te()
    {
        cout << 1 << endl;
    }
//子类会隐藏所有父类同名的成员函数，即使你用了重载，都必须加作用域
    void te(int )
    {
        cout << 3;
    }
    base()
    {
        a = 100;
    }

};

class son : public base
{
public:

    int a;

    void te()
    {
        cout << 2 << endl;
    }
    son()
    {
        a = 200;
    }
};

void text01()
{
    son s;
    cout << s.a << endl;
    cout << s.base::a << endl;
    s.te();
    s.base::te();
}

int main(){
    text01();

}