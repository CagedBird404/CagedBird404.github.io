/*
逆序对就是i < j && a[i] > a[j] 有多少对
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

vector<int> a, b;
int ans = 0;

void gb(int l, int r)
{
    if(l == r) return;
    int mid = l + ( r- l) / 2;
    gb(l, mid);
    gb(mid + 1, r);
    int i = l, j = mid + 1, t = l;
    while(i <= mid && j <= r)
    {
        if(a[i] > a[j])
        {
            b[t++] = a[j++];
            ans += mid - i + 1;
        }
        else{
            b[t++] = a[i++];
        }
    }
    while(i <= mid) b[t++] = a[i++], ans += mid - i + 1;
    while(j <= mid) b[t++] = a[j++];
    for(int k = l;k <= r;k++) a[k] = b[k];
}

void solve()
{
    int n;
    cin >> n;
    a.assign(n,0);
    b.assign(n,0);
    for(int i =0 ;i < n;i++) cin >> a[i];
    gb(0,n-1);
    cout << ans;
}

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);                
    cout << setiosflags(ios::fixed) << setprecision(2); 
    int TT = 1;
    //cin >> TT; 
    while (TT--)
    {
        solve(); 
        cout << endl;
    }
}