/*
单调队列经典用法：
滑动窗口滑动时，r++代表右侧数字进窗口，l++代表左侧数字进窗口
这个过程中，像随时得到当前窗口的 最大值 或 最小值

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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n;i++) cin >> a[i];
    deque<int> q, p;
    int r = 0;
    vector<int> ans1, ans2;
    while(r < n)
    {
        while(!q.empty() && q.front() < r - k + 1)
        {
            q.pop_front();
        }
        while(!q.empty() && a[q.back()] <= a[r])
        {
            q.pop_back();
        }
        
        while(!p.empty() && p.front() < r - k + 1)
        {
            p.pop_front();
        }
        while(!p.empty() && a[p.back()] >= a[r])
        {
            p.pop_back();
        }
        
        p.push_back(r);
        q.push_back(r);
        if(r >= k - 1) ans1.emplace_back(a[q.front()]), ans2.emplace_back(a[p.front()]);
        r++;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);                
    cout << setiosflags(ios::fixed) << setprecision(2); 
    int TT = 1;
    cin >> TT; 
    while (TT--)
    {
        solve(); 
        cout << endl;
    }
}