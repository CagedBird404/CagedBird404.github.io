#include<bits/stdc++.h>
using namespace std;
bool isprime(int x)
{
    if(x <= 1) return 0;
    for(int i=2;i<=x / i;i++)
    {
        if(x%i==0)
        {
            return 0;
        }
    }
    return 1 ;
}
int main(){

}