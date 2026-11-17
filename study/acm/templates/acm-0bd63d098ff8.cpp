/*
若长度为 n 的字符串 s 中可以选择一个位置 i，使得  
si ⋯sn s1 ⋯si−1 =t，则称 s 与 t 循环同构。字符串 s 的最小表示为与 s 循环同构的所有字符串中字典序最小的字符串
求最小字典序字符串
时间复杂度On
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    s += s;
    int i = 0,j = 1,k = 0;
    while(i < n && j < n && k < n)
    {
        if(s[i+k] == s[j+k]) k++;
        else{
            if(s[i+k] > s[j+k]) i = i + k + 1;
            else j = j + k + 1;
            if(i == j) j++;
            k = 0;
        }
    }
    int ans = min(i,j);
    cout << s.substr(ans,n);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);                
    cout << setiosflags(ios::fixed) << setprecision(2); 
    int TT = 1;
    //cin >> TT; 
    while (TT--)
    {
        solve(); 
        //cout << endl;
    }
}