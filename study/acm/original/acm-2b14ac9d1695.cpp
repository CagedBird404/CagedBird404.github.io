/*
1.一堆数字中，任意的a和b，用a^b的结果替代a、b中任意一个数字，不会影响非0异或和的组成
2.一对数字在，任意的a和b，如果a^b = 0,那么舍弃a、b中任意数字，不要影响非0异或和的组成
3.一堆数字中能否异或出0，在求出异或空间线性基之后，要被单独标记

他的作用是求出数组至少选一个数字的情况下，互相异或能得到那些数
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
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    vector<int> b(64, 0);
    int ok = 0; // 检测是否有0
    int num = 0;// 记录计算后有几个数字
    for(int i = 0;i < n;i++)
    {
        for(int k = 63;k >= 0;k--)
        {
            if((a[i] >> k) & 1)
            {
                if(b[k] == 0)
                {
                    b[k] = a[i];
                    num++;
                    break;
                }
                else{
                    a[i] ^= b[k];
                }
            }
            if(a[i] == 0) ok = 1;
        }
    }

    vector<int> c;
    for(int i = 0;i <= 63;i++)
    {
        if(b[i])
        {
            for(int j = 63;j > i;j--)
            {
                if((b[j] >> i) & 1) b[j] ^= b[i];
            }
        }
    }

    int nu = 1ll << num;
    for(int i = 0;i < 64;i++)
    {
        if(b[i]) c.push_back(b[i]);
    }
    
    int m;
    cin >> m;
    while(m--)
    {
        int x;
        cin >> x;
        if(num < n) x--;
        if(x >= nu) 
        {
            cout << -1 << endl;
            continue;
        }
        int ans = 0;
        for(int i = 0;i < num;i++)
        {
            if(x & (1ll << i)) ans ^= c[i];
        }
        cout << ans << endl;
    }
}

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);                
    cout << setiosflags(ios::fixed) << setprecision(2); 
    int TT = 1;
    cin >> TT; 
    int nu = 1;

    while (TT--)
    {
        
        cout << "Case #" << nu << ":" << endl;solve(); 
        //cout << endl;
        nu++;
    }
}