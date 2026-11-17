#include<bits/stdc++.h>
using namespace std;

class Building; //类的声明

class goodgay
{
    
public:

    goodgay();
    void visit();

    Building *build;
};

class Building
{
    
    friend class goodgay;

public:

    Building();
    string ke;

private: 
    
    string wo;

};
//类外写成员函数
Building::Building()
{
    ke = "keting";
    wo = "woshi";
}

goodgay::goodgay()
{
    build = new Building;//类内的指针都要开辟新空间
}

void goodgay::visit()
{
    cout << "fangwen: " << build -> ke << endl;
    cout << "fangwen: " << build -> wo << endl;
}

void text01()
{
    goodgay p1;
    p1.visit();
}

int main(){
    text01();
}