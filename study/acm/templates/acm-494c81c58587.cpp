#include<bits/stdc++.h>
using namespace std;

class Person
{
    friend ostream & operator<<(ostream& cout , Person p1);

public:

    Person& operator--()
    {
        this -> a--;
        this -> b--;
        return *this;
    }

    Person operator--(int)
    {
        Person p1 = *this;
        this -> a--;
        this -> b--;
        return p1;
    }

private:
    int a = 1;
    int b = 1;
};

ostream & operator<<(ostream& cout,Person p1)
{
    cout << p1.a + p1.b;
    return cout;
}

    void text01()
    {
        Person p1;
        cout << p1 << endl;
        cout << --p1 << endl;
        cout << p1 << endl;
    }

void text02()
{
    Person p1;
    cout << p1 << endl;
    cout << p1-- << endl;
    cout << p1 << endl; 
}

int main(){
    text01();
    text02();
}