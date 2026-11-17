/*
用于找最长公共上升子序列

时间复杂度O(n*m)
*/

#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

void solve()
{
    int n,m;
    cin >> n ;
    vector<int> a(n);
    for(int i = 0;i < n;i++) cin >> a[i];
    cin >> m;
    vector<int> b(m);
    for(int i = 0;i < m;i++) cin >> b[i];
    vector<int> dp(m),k(m,-1);   //dp[j]记录的是对于b数组以b[j]为结尾时
    for(int i = 0;i < n;i++)     //他的最大公共上升子区间长度
    {                            //k记录他的前驱元素，便于去回溯寻找整个序列
        int l = 0;//最大长度
        int num = -1;//前驱元素
        for(int j = 0;j < m;j++)
        {
            if(a[i] == b[j])  //关键限制，因为只能是相同的元素，所以只有相等
            {                 //的时候才对他加一
                if(dp[j] < l + 1)   //限制：只对于大于当前最佳长度的进行更新
                {
                    dp[j] = l + 1;
                    k[j] = num; //更新前置元素
                }
            }
            if(b[j] < a[i])  //对于比他小的b元素，如果dp[j]的长度比他大，那么就把最佳长度更新
            {                //并且更新前置
                if(dp[j] > l)
                {
                    l = dp[j];
                    num = j;
                }
            }
        }
    }
    int num = max_element(all(dp)) - dp.begin();
    int ans = dp[num];
    vector<int> pp;
    while(num != -1)
    {
        pp.emplace_back(b[num]);
        num = k[num];
    }
    reverse(all(pp));
    cout << ans << endl; if(ans == 0) return;
    for(auto gg : pp)
    {
        cout << gg << " ";
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