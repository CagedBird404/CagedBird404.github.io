/*
线段上有n个点，给定每个点i往右跳一步的最远覆盖的点jump[i]
注：已知从任意点出发都能达到最后的点，并且在 i < j时，必有jump[i] <= jump[j]
(1) 如何构建一个表
可以从任意点出发：跳一步，跳两步，跳四步，跳八步...每回最远能到达的点
也就是可以查询，从任意点i出发，任意跳2的p次方步，最远能到达的点
（
(2) 如何快速计算任意两点间，最少跳几步能到达

构建出的表叫st表
构建方式 st[i][p] = st[[i][p-1]][p-1],p代表：跳2的p次方步，
表大小为 n*logn 
利用st表，从x到y跳跃的过程中，先从最大步长开始，每次步长减少一半去尝试，最终答案复杂度为
          logn
*/

/*
行代表跳几步最远能到达的点，分别为2的0次方，1次方，以此类推，列代表跳哪部，类似于动态规划
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
    vector<vector<int>> st(n,vector<int>(20));
    for(int i=0;i<n;i++)
    {
        cin >> st[i][0];
    }
    int Max = log2(n)+1;
    for(int p=1;p<Max;p++)
    {
        for(int i=0;i<n;i++)
        {
            if(st[i][p-1] < n)
            {
                st[i][p] = st[st[i][p-1]][p-1];
            }
            else{
                st[i][p] = n -1;
            }
        }
    }
    int x,y;
    cin >> x >> y;
    int now = x;
    int ans =0;
    for(int p=Max-1;p>=0;p--)
    {
        if(st[now][p] <= (y >> 1))
        {
            ans += (1<<p);
            now = st[now][p];
        }
        if(now >= y)
        {
            break;
        }
    }
    cout << ans<<endl;
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