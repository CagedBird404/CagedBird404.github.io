/*

*/
#include<bits/stdc++.h>
using namespace std;

//类对象作为类成员
class Phone
{
public:
    Phone(string s)
    {
        pname = s;
    }
    string pname;
};

class Person
{
public:

    Person(string s1,string s2):name(s1),p(s2) // 先构造phone,后释放phone
    {

    }

    string name;
    Phone p;
};

void text1()
{
    Person("zhangsan","huawei");
}
int main()
{

}