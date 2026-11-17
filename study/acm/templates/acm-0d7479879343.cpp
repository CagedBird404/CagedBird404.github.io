#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

priority_queue<int> mx; // 大顶堆
priority_queue<int,vector<int>,greater<int>> mi; // 小顶堆

int now;
void qwq()
{
    if(mi.size() < now)
    {
        mi.push(mx.top());
        mx.pop();
    }
    if(mi.size() > now)
    {
        mx.push(mi.top());
        mi.pop();
    }
}
void solve()
{
    int n,w,num;
    cin >> n >> w;
    mx.push(0);
    for(int i = 1;i <= n;i++)
    {
        now = max(1ll,i*w/100);
        cin >> num;
        if(num >= mx.top())
        {
            mi.push(num);
        }
        else mx.push(num);
        qwq();
        cout << mi.top() << " ";
    }
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