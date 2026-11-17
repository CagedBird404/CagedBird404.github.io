#include<bits/stdc++.h>   //记忆化搜索
using namespace std;
int n;vector<int> saved(n+1,-1);
//进行优化，他会有很多分支，
int f(int n){           //计算很多重复数据，太慢，
    if(n<=2)            //将其保存，再调用，会快很多
    {                   //最后输出保存的数据就行
        return 1;
    }
    if(saved[n]==-1)
    {
        saved[n]=f(n-1)+f(n-2);
    }
    return saved[n];
}
int main(){
cin>> n;saved = vector<int> (n+1,-1);
cout<<f(n);
}