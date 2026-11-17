/*
给定一个长度为n的数组，如果一段范围内，数字x出现c次
他的重要度就是 x * c ，求范围上每种数字的重要度的最大值

窗口加入数字时，区间信息和答案信息都更新
窗口删数字时，只更新区间信息不更新答案信息

对于l在同一区块的分两种
一种是r也在同一区块，进行暴力求解
第二种是r在其他区，利用回溯的方法一次一次进行扩充

答案信息利用回滚来更新

排序策略：
（1）l所在块从小到大
（2）r从小到大
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

struct node
{
    int l, r, id;
};

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int> a(n+1);
    for(int i = 1;i <= n;i++) cin >> a[i];

    vector<int> unique_vals = a;
    sort(all(unique_vals));
    unique_vals.erase(unique(unique_vals.begin(), unique_vals.end()), unique_vals.end());

    // 离散化映射，使用 map 或者直接在 unique_vals 中二分查找
    unordered_map<int, int> compress;

    for (int i = 0; i < unique_vals.size(); i++) {
        compress[unique_vals[i]] = i;
    }

    // 用离散化后的值替换原数组
    for (int i = 1; i <= n; i++) {
        a[i] = compress[a[i]];
    }


    int len = sqrt(n);
    int num = (n + len - 1) / len;
    vector<int> b(n+1);
    for(int i = 1; i <= n; i++)
    {
        b[i] = (i - 1) / len + 1;
    }
    vector<int> bl(num + 1),br(num + 1);
    for(int i = 1;i <= num; i++)
    {
        bl[i] = (i - 1) * len + 1;
        br[i] = min(n, i * len);
    }
    vector<node> k(m);
    for(int i = 0; i < m;i++)
    {
        cin >> k[i].l >> k[i].r;
        k[i].id = i;
    }
    vector<int> ans(m);
    sort(all(k),[&](node x, node y){
        if(b[x.l] != b[y.l]) return b[x.l] < b[y.l];
        return x.r < y.r;
    });
                            //qi代表到哪个任务
    for(int nk = 1, qi = 0; nk <= num && qi < m;nk++) //两个截止条件，一个任务数量，一个块数
    {
        int now = 0; 
        vector<int> mp(unique_vals.size(),0);
        int l = br[nk] + 1, r = br[nk];
        for( ; qi < m && b[k[qi].l] == nk; qi++) //当前任务的左边界在这块上
        {
            if(k[qi].r <= br[nk])
            {
                int tnow = 0;
                vector<int> tmp(unique_vals.size(),0);
                for(int i = k[qi].l;i <= k[qi].r; i++) tmp[a[i]]++;
                for(int i = k[qi].l; i <= k[qi].r; i++) tnow = max(tnow, unique_vals[a[i]] * tmp[a[i]]);
                ans[k[qi].id] = tnow;
            }
            else{
                while(r < k[qi].r)
                {
                    r++;
                    mp[a[r]]++;
                    now = max(now, unique_vals[a[r]] * mp[a[r]]);
                }
                int temp = now;//对于你这个块内的查询，因为你的r是递增的，那么你的r1就可以真实的往前走，而你的l可能是参差不齐，那么你就一直维护在一个固定值，然后记录你扩展l之前的答案，那么对于下一个l，你直接再次扩展就好了
                while(l > k[qi].l)
                {
                    l--;
                    mp[a[l]]++;
                    now = max(now, unique_vals[a[l]] * mp[a[l]]);
                }
                ans[k[qi].id] = now;
                now = temp;
                while(l <= br[nk])
                {
                    mp[a[l]]--;
                    l++;
                }
            }
        }
    }
    for(int i = 0;i < m; i++)
    {
        cout << ans[i] << endl;
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
        cout << endl;
    }
}