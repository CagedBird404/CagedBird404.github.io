#include<bits/stdc++.h>
using namespace std;

class Building;

class goodgay
{
public:

    goodgay();

    void visited();

    Building * build;
};

class Building
{
    friend void goodgay::visited();

public:

    Building();
    string ke;

private:

    string wo;

};

Building::Building()
{
    ke = "keting";
    wo = "woshi";
}
goodgay::goodgay()
{
    build = new Building;
}
void goodgay::visited()
{
    cout << "fangwen: " << build -> ke << endl;
    cout << "fangwen: " << build -> wo << endl;
}

void text01()
{
    goodgay p1;
    p1.visited();
}

int main(){
    text01();
}