#include<bits/stdc++.h>
using namespace std;
int main(){
    //前缀和
    int N;
    cin>> N;
    vector<int> a(N+1);
    vector<int> prefix(N)+1;
    for(int i=1;i<=N;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=N;i++)
    {
        prefix[i]=prefix[i-1] + a[i];
    }
    //差分 
    //前缀的差分是原数组，反过来也一样
    vector<int> diff(N+1);
    for(int i=1;i<=N;i++)
    {
        diff[i]=a[i] - a[i-1];
    }
    //如果修改差分，例如让原数组[l,r]加一，
    //则让l对应差分加一，r+1对应差分减一，
    //差分加一代表他从这个位置以后所有元素都加一
    //根据自己需求，进行计算，采用一次差分或者二次
    //进行优化复杂度，最后前缀还原数组


}