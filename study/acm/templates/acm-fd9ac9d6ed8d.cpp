/*
维护一个单调的队列，去解决问题
例如经典题，求当前位置左面或者右面第一个大于或者小于的数的下标

下面是求每个数，左面第一个小于他的和右面第一个小于他的,数字里面有重复的，要求严格小于

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
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n;i++) cin >> a[i];
    vector<pair<int,int>> ans(n);
    stack<int> st;
    for(int i = 0;i < n;i++)
    {
        while(!st.empty() && a[st.top()] >= a[i])
        {
            auto k = st.top();
            st.pop();
            if(!st.empty())ans[k].first = st.top();
            else ans[k].first = -1;
            ans[k].second = i;
        }
        st.push(i);
    }
    while(!st.empty())
    {
        auto k = st.top();
        st.pop();
        if(!st.empty())ans[k].first = st.top();
        else ans[k].first = -1;
        ans[k].second = -1; 
    }
    for(int i = n - 2;i >= 0;i--)
    {
        while(ans[i].second != -1 && a[ans[i].second] == a[i])
        {
            ans[i].second = ans[ans[i].second].second;
        }
    }
    for(int i = 0; i < n; i++)
    {
        cout << ans[i].first << " " << ans[i].second << endl;
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