/*
n个数，m次询问，1 x y z就代表询问区间内大于z的个数
2 x y就代表将x 改成 y
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
    cin >> n>> m;
    vector<int> a(n+1);
    for(int i = 1;i <= n;i++) cin >> a[i];
    vector<int> bi(n+1),bl(n),br(n);
    int len = sqrt(n);
    int num = (n + len - 1) / len;
    for(int i = 1;i <= n;i++)
    {
        bi[i] = (i - 1) / len + 1;//第几块
    }
    for(int i = 1;i <= num ;i++)
    {
        bl[i] = (i - 1) * len + 1;
        br[i] = min(i * len, n);
    }
    vector<int> so(n+1);
    so = a;
    for(int i = 1;i <= num; i++)
    {
        sort(so.begin() + bl[i], so.begin() + br[i] + 1);
    }
    while(m--)
    {
        int op;
        cin >> op;
        if(!op)
        {
            int x,y;
            cin >> x >> y;
            int l = bl[bi[x]];
            int r = br[bi[x]];
            a[x] = y;
            for(int i = l;i <= r;i++)
            {
                so[i] = a[i];
            }
            sort(so.begin() + l,so.begin() + r + 1);
        }
        else{
            int x,y,z;
            cin >> x >> y >> z;
            int ans = 0;
            if(bi[x] == bi[y])
            {
                for(int i = x;i <= y;i++) if(a[i] >= z) ans++;
            }
            else{
                for(int i = x; i <= br[bi[x]];i++)
                {
                    if(a[i] >= z) ans ++;
                }
                for(int i = bl[bi[y]];i <= y;i++) 
                {
                    if(a[i] >= z) ans++;
                }
                for(int i = bi[x] + 1;i <= bi[y] - 1;i++)
                {
                    int l = bl[i];
                    int r = br[i];
                    int k = 0;
                    while(l <= r)
                    {
                        int mid = l + (r - l) / 2;
                        if(so[mid] >= z)
                        {
                            k = br[i] - mid + 1;
                            r = mid - 1;
                        }
                        else l = mid + 1;
                    }
                    ans += k;
                }
            }
            cout << ans << endl;
        }
    }
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