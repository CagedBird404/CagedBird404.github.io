/*
为了解决字符串最大回文问题，最重要的是回文半径数组
时间复杂度On

把原字符串扩展加上#，方便找奇长度和偶数长度的回文

回文半径和真实长度对比是a[i]
真实回文串结尾位置 = 扩展串的结尾下标 / 2

r 代表以当前为中心向右扩展，第一个到达不了的位置
c 此时取得最右边界的中心位置，而且是最早的位置

对向下的每个中心
首先分两种情况：
    一、在r之外
    对于这种直接遍历找，暴力
    二、在r之内
    这种又分三种情况
    （1）关于c对称点的半径依旧在r内
        这样直接就相等就可以
    （2）对称点半径在大回文区域以外
        a[i] = r - i
    （3）对称点半径正好撞线大回文边界
        继续在r的基础上走，暴力继续找，往外扩
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

vector<int> a;

void get(string s)
{
    string t = "#";
    for(char k : s)
    {
        t += k;
        t += '#';
    }
    int n = t.size();
    a.assign(n+1,0);
    int r = 0;
    int c = 0;
    for(int i = 0;i < n;i++)
    {
        if(i < r)
        {
            a[i] = min(a[2 * c - i],r - i);
        }
        while(i - a[i] - 1 >= 0 && i + a[i] +1 < n && t[i-a[i]-1] == t[i+a[i]+1])
        a[i]++;
        if(i + a[i] > r)
        {
            c = i;
            r = i + a[i];
        }
    }
}

void solve()
{
    string s,ans;
    cin >> s;
    get(s);
    int c = 0;
    for(int i = 0;i < a.size();i++)
    {
        if(a[i] > a[c])
        {
            c = i;
        }
    }
    int r = a[c];
    ans = s.substr((c - r)/2,r);
    cout << ans;
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