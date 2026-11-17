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
    double eps = 1e-9;
    vector<vector<double>> a(n + 1 , vector<double>(n + 2));
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n + 1;j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 1;i <= n;i++)
    {
        int r = i;
        for(int k = i;k <= n;k++)
        {
            if(fabs(a[k][i]) > eps)
            {
                r = k;
                break;
            }
        }
        if(r != i)
        {
            swap(a[i], a[r]);
        }
        if(fabs(a[i][i]) < eps)
        {
            cout << "No Solution";
            return;
        }
        for(int k = i + 1;k <= n;k++)
        {
            double t = a[k][i] / a[i][i];
            for(int j = i;j <= n + 1;j++) a[k][j] -= t * a[i][j];
        }
    }
    for(int i = n;i >= 1;i--)
    {
        double sum = a[i][n + 1];
        for(int j = i + 1;j <= n;j++) sum -= a[i][j] * a[j][n + 1];
        a[i][n + 1] = sum / a[i][i];
    }

    for(int i = 1;i <= n;i++)
    {
        if(i > 1) cout << endl;
        cout << a[i][n + 1];
    }
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