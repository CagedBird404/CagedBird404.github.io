/*
对于一些函数和类，可以用friend修饰后
可以访问他的私有和保护属性
*/
#include<bits/stdc++.h>
using namespace std;

class Building
{

    friend void cc(Building *build); //将其设置成好朋友，使其可以访问他的私有

public:

    Building()
    {
        keting = "客厅";
        woshi = "卧室";
    }

    string keting;

private:
    string woshi;
};

void cc(Building *build)
{
    cout << build -> woshi << endl; //正常来讲，私有不可访问
    cout << build -> keting << endl;
}



int main(){
    Building bu;
    cc(&bu);
}