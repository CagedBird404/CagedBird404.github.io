/*
给定一个正整数m
求2的多少次方，最接近m
难点在于，有可能m很大，再下一次方可能会越界
*/

#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

void show1(int x)
{
    int power = 0;
    while((1 << power) <= (x >> 1)) //优化防止溢出，右移一位
    {
        power ++;
    }
    cout<<power<<endl;
    return;
}
void solve()
{
    int x;
    cin >> x;
    show1(x);
}

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);                
    cout << setiosflags(ios::fixed) << setprecision(2); 
    int TT = 1;
    cin >> TT; 
    while (TT--)
    {
        solve(); 
        cout << endl;
    }
}