/*
求一个数列最长单调上升的子序列，不需要连续
下降同理，可以加入二分优化
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
    for(int i = 0;i < n;i++) cin >> a[i];
    vector<int> b(n+1);//上升,记录他的最小结尾,最后数组就记录了这个数组
    vector<int> dp1(n,1);
    b[0] = -1e9;
    int num = 0; //最后上升序列长度
    for(int i = 0;i < n;i++)
    {
        if(a[i] > b[num])
        {
            num++;
            b[num] = a[i];
            dp1[i] = num;
        }
        else{
            int l = 1,r = num;
            while(l <= r)
            {
                int mid = l + (r - l) / 2;
                if(b[mid] > a[i])
                {
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
            b[l] = a[i];
            dp1[i] = l + 1;
        }
    }
    cout << num << endl;


    vector<int> c(n+1);
    vector<int> dp2(n,1);
    c[0] = 1e9;
    num = 0;
    for(int i = 0;i < n;i++)
    {
        if(a[i] < c[num])
        {
            num++;
            c[num] = a[i];
            dp2[i] = num;
        }
        else{
            int l = 1,r = num;
            while(l <= r)
            {
                int mid = l + (r - l) / 2;
                if(c[mid] < a[i])
                {
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
            c[l] = a[i];
            dp2[i] = l + 1;
        }
    }
    cout << num;
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
        //cout << endl;
    }
}