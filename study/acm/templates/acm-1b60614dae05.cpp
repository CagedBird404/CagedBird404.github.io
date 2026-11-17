/*
在一维数组上实现单点或范围增加，单点或范围查询

二维数组上实现单点或者范围增加，范围查询

树状数组都是来维护可差分信息，线段树是用来对于不可差分信息的
什么是可差分信息：区域和，乘积
不可：最大值最小值

线段树大多数都是可以代替树状数组的
线段树优势：用法全面，思考量低，维护信息多
线段树劣势：代码量大，使用空间大，常熟时间较大
树状数组优势：代码量少，使用空间少，常数时间优异

树状数组下标必须从1开始
怎么确定树状数组下标所对应的范围，将下标二进制最右1去掉，再加1，到当前下标就是所包围范围

对于每次查询，对于l和r的二进制，通过不断去掉最右侧的1，加上对应下标的树状数组和，来进行求解
对于单点修改，通过不断加上二进制最右侧的1，来得到有哪些树状数组下标拥有这个数
对于最右侧的1，用i & -i
和线段树一样都是nlogn
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m ;
    vector<int> a(n+1), tree(n + 1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        int k = i;
        while(k <= n)
        {
            tree[k] += a[i];
            k += k & -k;
        }
    }
    while(m--)
    {
        int op, x, y;
        cin >> op >> x >> y;
        if(op == 1)
        {
            while(x <= n)
            {
                tree[x] += y;
                x += x & -x;
            }
        }
        else{
            int ans = 0;
            x--;
            while(y > 0)
            {
                ans += tree[y];
                y -= y & -y;
            }
            while(x > 0)
            {
                ans -= tree[x];
                x -= x & -x;
            }
            cout << ans << endl;
        }
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