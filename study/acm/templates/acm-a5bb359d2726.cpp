#include<bits/stdc++.h>
using namespace std;

class Person
{
public:
    int a = 0;
    int b = 0;
    string s;
    Person(int x,int y,string s1):a(x),b(y),s(s1)
    {

    }

    bool operator==(Person p1)
    {
        if(p1.s == this -> s && p1.a == this -> a && p1.b == this -> b) return 1;
        return 0;
    }

    bool operator!=(Person p1)
    {
        if(p1.s == this -> s && p1.a == this -> a && p1.b == this -> b) return 0;
        return 1;
    }

    bool operator>=(Person p1)
    {
        if(p1.s >= this -> s && p1.a >= this -> a && p1.b >= this -> b) return 1;
        return 0;
    }

    bool operator<=(Person p1)
    {
        if(p1.s <= this -> s && p1.a <= this -> a && p1.b <= this -> b) return 1;
        return 0;
    }

    bool operator>(Person p1)
    {
        if(p1.s > this -> s && p1.a > this -> a && p1.b > this -> b) return 1;
        return 0;
    }

    bool operator<(Person p1)
    {
        if(p1.s < this -> s && p1.a < this -> a && p1.b < this -> b) return 1;
        return 0;
    }
};

void text01()
{
    Person p1(10,20,"st");

    Person p2(20,10,"st");

    if(p1 == p2) cout << "p1 和 p2 是相等的" << endl;
    else cout << "不相等" << endl;
}

int main(){
    text01();
}