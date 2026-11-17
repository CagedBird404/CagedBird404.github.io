#include <bits/stdc++.h>
using namespace std;
long long factorial(int n) {
    if(n<0 || n>20) throw out_of_range("factorial supports 0..20");
    long long result=1;
    for(int i=2;i<=n;++i) result*=i;
    return result;
}
