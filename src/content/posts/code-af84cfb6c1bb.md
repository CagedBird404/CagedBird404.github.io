---
title: "算法"
published: 2026-11-16
category: "算法"
tags: [学习笔记, C++]
description: "按主题整理的原始学习代码，保留注释与实现。"
draft: false
---

本文整理自我的本地学习代码，按文件分节，保留原有实现与注释。

> 整理说明：这些是不同阶段的练习、模板和实验代码，未逐一编译或验证，不代表所有实现均正确。使用时需结合题目、输入范围和编译环境。部分代码使用 GCC 的 `bits/stdc++.h`，Windows 小程序可能依赖 `windows.h`、`conio.h`。

## 2-sat问题

原文件：`算法/2-sat问题.cpp`

```cpp
/*
给出n个变量x，每个变量只能取0/1，给出m个条件，
比如xi = 0/1，或者xj = 0/1
求2-sat问题就是求出满足m个条件的一组x

样例：x2只能取0，x1只能取1，x3能取0或1

时间复杂度O(n + m)
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

const int N = 2e6 + 10;
int head[N], to[N], ne[N], tot;
int dfn[N], low[N], stk[N], scc[N];
bool in_stk[N];
int tim, top, cnt;

void add(int u, int v)
{
    to[++tot] = v;
    ne[tot] = head[u];
    head[u] = tot;
}

void tarjan(int x)
{
    dfn[x] = low[x] = ++tim;
    stk[++top] = x;
    in_stk[x] = true;
    for(int i = head[x]; i; i = ne[i])
    {
        int y = to[i];
        if(!dfn[y])
        {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        }
        else if(in_stk[y])
        {
            low[x] = min(low[x], dfn[y]);
        }
    }

    if(low[x] == dfn[x])
    {
        ++cnt;
        int y;
        do {
            y = stk[top--];
            in_stk[y] = false;
            scc[y] = cnt;
        } while (y != x);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    
    tot = tim = top = cnt = 0;
    for (int i = 1; i <= 2 * n; ++i) {
        head[i] = dfn[i] = low[i] = scc[i] = 0;
        in_stk[i] = false;
    }

    for (int i = 1; i <= m; ++i) {
        int i1, a, i2, b;
        cin >> i1 >> a >> i2 >> b;
        // i1为a OR i2为b
        // !a -> b, !b -> a
        add(i1 + (a ^ 1) * n, i2 + b * n);
        add(i2 + (b ^ 1) * n, i1 + a * n);
    }

    for (int i = 1; i <= 2 * n; ++i) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (scc[i] == scc[i + n]) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    cout << "POSSIBLE\n";
    for (int i = 1; i <= n; ++i) {
        cout << (scc[i] > scc[i + n]) << " \n"[i == n];
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
```

## LCA共同祖先问题（倍增）

原文件：`算法/LCA共同祖先问题（倍增）.cpp`

```cpp
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

constexpr int N = 1e5 + 5;
constexpr int LOG = 20;

int n,m,root; // 节点数，查询次数，root为根
vector<vector<int>> g(N,vector<int>());
int depth[N];
int fa[N][LOG];

void dfs(int u,int f)
{
    fa[u][0] = f;           //记录父点
    depth[u] = depth[f] + 1;//深度
    for(int k = 1;k < LOG;k++)
    {
        fa[u][k] = fa[fa[u][k - 1]][k - 1]; //倍增
    }

    for(int v : g[u])          //遍历u的相邻点
    { 
        if(v == f) continue;   //跳过父节点
        dfs(v,u);              //深入子节点
    }
}

int LCA(int u,int v)
{
    if(depth[u] < depth[v]) swap(u,v);
    // 让其同一个深度
    for(int k = LOG - 1;k >= 0;k--)
    {
        if(fa[u][k] && depth[fa[u][k]] >= depth[v])
        u = fa[u][k];
    }
    // 如果已经相遇，直接返回
    if(u == v) return u;
    // 从高到低一起跳，直到他们的父节点相同
    for(int k = LOG - 1;k >= 0;k--)
    {
        if(fa[u][k] && fa[v][k] && fa[u][k] != fa[v][k])
        {
            u = fa[u][k];
            v = fa[v][k];
        }
    }
    return fa[u][0];
}
void solve()
{
    cin >> n >> m >> root;
    for(int i = 1;i <= n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(root,0);

    for(int i = 1;i <= m;i++)
    {
        int x,y;
        cin >> x >> y;
        cout << LCA(x,y) << endl;
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
        //cout << endl;
    }
}
```

## P_4017_最大食物链(拓扑排序)

原文件：`算法/P_4017_最大食物链(拓扑排序).cpp`

```cpp
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 80112002;

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n+1);
    vector<int> inp(n+1);
    vector<int> outp(n+1);
    for(int i = 0;i < m ;i ++)
    {
        int x,y;
        cin >> x >> y;
        inp[x]++;
        outp[y]++;
        a[x].emplace_back(y);
    } 
    queue<int> q;
    vector<int> dp(n+1);
    for(int i=1;i<=n;i++)
    {
        if(!outp[i]) 
        {
            q.push(i);
            dp[i] = 1;
        }
    }
    while(!q.empty())
    {
        auto k = q.front();
        q.pop();
        for(auto p : a[k])
        {
            dp[p] = (dp[p] + dp[k]) % MOD;
            outp[p]--;
            if(!outp[p]) q.push(p);
        }
    }
    int ans = 0;
    for(int i = 1;i<=n;i++)
    {
        if(!inp[i])
        {
            ans = (ans + dp[i])%MOD;
        }
    }
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
        //cout << endl;
    }
}
```

## STL 算法

原文件：`算法/STL 算法.cpp`

```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    // string a="awa",b="bwb";
    // swap(a,b);//置换
    vector<int> au={1,9,1,3,6,0,4};
    sort(au.begin(),au.end());//将数组中数字排序，从小到大
    sort(au.begin(),au.end(),greater<int>());//从大到小
    vector<pair<int,int>> be={{2,4},{5,3},{8,4},{9,1},{8,5},{2,10},{2,4}};
    sort(be.begin(),be.end(),[](pair<int,int>a,pair<int,int>b){if(a.first!=b.first)return a.first>b.first;
        return a.second>b.second;});//相当于后面省略了一个else，先判断条件，符合执行第一个，不符合执行后一个
    for(auto&&i:be)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }


    //lower_bound()寻找大于等于X的第一个元素位置,是位置不是数字
    //upper_bound()寻找大于X的第一个元素位置
    vector<int> A{2,5,9,3,0,2,9,4,2,6,7,8};
    int B=lower_bound(A.begin(),A.end(),8)-A.begin();//将迭代器转为数字
    cout<<B<<endl;//如果想从某个位置开始，就在begain后加减，end同理，如果找不到，则返回尾迭代器
    
    reverse(A.begin(),A.end());//反转数组中的数


    cout<<max(1,2)<<endl;//前后必须同一类型，板子数字是longlong注意，如果是
    cout<<min(3,2)<<endl;//数字可以在数字后加ll，例如0ll
    cout<<max({1,2,3,4,5,6,7})<<endl;//多个数用({})
    *max_element(A.begin(), A.end());   //适用于容器的


    string line;
    while(getline(cin,line,';'))//轮流输入给line，';'结束，可以作为判断条件，如果没有;默认遇到换行符号结束
    {
        cout<< line <<endl;
    }


    //unique,消除重复相邻元素，数组长度不变，但是消除的变为无效数据
    sort(A.begin(),A.end());
    //比如排序后为 1 1 2 3 3 5 5 
    //之后就会变为 1 2 3 5 * * *
    //unique(A.begin(),A.end());返回的是第一个*的迭代器
    //如果想只要实际数据长度，则组合使用erase
    A.erase(unique(A.begin(),A.end()),A.end());
    for(auto&&i:A)
    {
        cout<<i<<endl;
    }

while(next_permutation(all(a))){}//会将容器内的元素调整为下一个字典序更大的排列，
                                 //同时也能作为判断标准，没有就返回0，否则为1
                                 //1 2 3 ->  1 3 2  ->  2 1 3  ->  2 3 1  ->  3 1 2等等
    

    //统计容器中有多少为x的元素   count
    int u=1;
    int g=count(A.begin(),A.end(),u);  //只可以统计单个元素数量，比如MHY就不可以
    cout<< g <<endl;
    //统计符合条件元素的数量      count_if
    int k=count_if(A.begin(),A.end(),[](int x){return x%2==0;});
    cout<< k <<endl;


    //gcd()最大公因数/lcm()最小公倍数
    int d=gcd(12,40);
    cout<<d<<endl;
    int e=lcm(101,200);
    cout<<e<<endl;
}
    //如果没有则需前置函数
    int gcd(int a,int b)
    {
        if(!b)
           return a;
        return gcd(b,a%b);//返给函数b和a除以b的余数
    }
    int lcm(int a,int b)
    {
        return a/gcd(a,b)*b;
    }
    //3. 关键逻辑：欧几里得算法的原理
//欧几里得算法的核心定理是：对于任意两个正整数a、b（a > b），
//有 gcd(a, b) = gcd(b, a mod b)（ a mod b  即  a%b ，表示a除以b的余数）。
//通过不断用“较小数”和“余数”替换原参数，直到余数为0，此时的“较小数”就是最终的GCD。
```

## ST表

原文件：`算法/ST表.cpp`

```cpp
//ST表通常采取预处理的方案存储不同长度的区间答案
//所有在查询时很方便
//一般用于解决区间最值，可重复贡献
/*
ST表通常需要注意
1.静态区间查询
2.运算满足结合律和幂等律
3.常见元素：
    区间最大最小
    区间GCD
    区间按位与，按位或
*/
//基本思路：倍增法
/*
预处理二维数组st[i][j]代表从i开始，长度为2……j的区间答案
状态转移方程：  st[i][j]=f(s[i][j-1],st[i+(2^(j-1))][j-1])
即为将长度为2^j的区间拆解成两个2^(j-1)
*/
//对于[L,R]
//令k=floor(log_2(R-L+1))
//ans = f(st[l][k],st[r-(1 << k)+1][k])


//这是最大值的
struct ST
{
    int maxn;
    vector<int> logtab;
    vector<vector<int>> st;
    ST(int maxk)
    {
        maxn = maxk;
    }
    void pre(const vector<int> &a)
    {
        // 预处理log表
        logtab.resize(maxn + 1);
        int K = __lg(maxn) + 1;
        st = vector<vector<int>>(maxn, vector<int>(K));
        logtab[1] = 0;
        for (int i = 2; i <= maxn; i++) {
            logtab[i] = logtab[i / 2] + 1;
        }
        // 预处理st表
        // 初始化
        for (int i = 0; i < maxn; i++) {
            st[i][0] = a[i];
        }
        // pre
        for (int j = 1; (1 << j) <= maxn; j++) {
            for (int i = 0; i + (1 << j) <= maxn; i++) {
                st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    int get(int l, int r)
    {
        int k = logtab[r - l + 1];
        return max(st[l][k], st[r - (1 << k) + 1][k]);
    }
};
```

## Tarjan

原文件：`算法/Tarjan.cpp`

```cpp
/*
强连通：若一张有向图的节点两两互达，则称这张图是强连通
强连通分量：极大的强连通子图，联通的一堆点可以互相到达

对图深搜时，每一个节点访问一次，被访问过的节点与边构成搜索树

树边：访问节点走过的边
返祖边：指向祖先节点的边
横叉边：右子树指向左子树的边
前向边：指向子树中节点的边

返祖边和树边必构成环，横叉边可能与树边构成环

如果节点x是某个强联通分量在搜索树上中遇到的第一个节点
那么这个强联通分量的其余节点肯定是在搜索树在，以x为根的子树中，节点x被称为这个强联通分量的根

*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

int dfn[N]; //节点第一次被访问的顺序
int low[N]; //从节点x出发，所能访问到的最早时间戳
int tot;
int stk[N], instk[N], top;
int scc[N], siz[N], cnt;
void solve()
{
    
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
```

## 三分

原文件：`算法/三分.cpp`

```cpp
/*
二分查找一般适用于单调函数，
对于凸函数极值的求解，可以考虑三份搜索。
具体的就是把候选区域分成三份，然后去掉一份不可能存在极值的区间，直到逼近极值
*/
/*
如果f(m1) > f(m2)则不要最右面的区间
如果f(m1) < f(m2)则不要最左面的区间
不断逼近，直到找到最大值
*/

/*
有n个种族，每个种族有ai个人，要求把所有人分成m组，
给定x和b，定义p为在不同组中同种族的人的pair对数，
分组的评分定义为 b * P - x * (m-1)
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

int find_max(int l,int r,vector<int> &a)
{
    int left = l,right = r;
    while(left < right)
    {
        if(right - left <= 2)
        {
            int Max = a[left];
            for(int i=left;i<=right;i++)
            {
                Max = max(Max,a[i]);
            }
            return Max;
        }
        int m1 = left + (right - left)/3;
        int m2 = right - (right - left)/3;
        if(a[m1] < a[m2])
        {
            left = m1+1;
        }
        else{
            right = m2-1;
        }
    }
    return a[left]; // 如果左右直接相等，返回这个值
}
int find_min(int l,int r,vector<int> &a)
{
    int left = l;
    int right = r;
    while(left < right)
    {
        if(right - left <= 2)
        {
            int Min = a[left];
            for(int i=left;i<=right;i++)
            {
                Min = min(Min,a[i]);
            }
            return Min;
        }
        int m1 = left + (right - left)/3;
        int m2 = right - (right - left)/3;
        if(a[m1] < a[m2])
        {
            right = m2 -1;
        }
        else{
            left = m1 + 1;
        }
    }
    return a[left];
}
void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    while(m--)
    {
        int l,r;
        cin >> l >> r;
        int Max = find_max(l,r,a);
        int Min = find_min(l,r,a);
        cout<<Max - Min<<endl;
        
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
```

## 二进制小问题

原文件：`算法/二进制小问题.cpp`

```cpp
/*
给定一个正整数x
已知用m个二进制位一定能表示x
从高位到低位打印x的每一位状态
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

void dy(int x,int m)
{
    int t=x;
    for(int i=m-1;i>=0;i--)
    {
        if(1 << i <= t)
        {
            t -= 1 << i;
            cout<<x<<"的第"<<i<<"位是1"<<endl;
        }
        else{
            cout<<x<<"的第"<<i<<"位是0"<<endl;
        }
    }
    return;
}
void solve()
{
    int n,m;
    cin >> n >> m;
    dy(n,m);
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
```

## 二进制小问题2

原文件：`算法/二进制小问题2.cpp`

```cpp
/*
给定一个正整数m
求2的多少次方，最接近m
难点在于，有可能m很大，再下一次方可能会越界
*/

#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

void show1(int x)
{
    int power = 0;
    while((1 << power) <= (x >> 1)) //优化防止溢出，右移一位
    {
        power ++;
    }
    cout<<power<<endl;
    return;
}
void solve()
{
    int x;
    cin >> x;
    show1(x);
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
```

## 二进制暴力组合数组的数

原文件：`算法/二进制暴力组合数组的数.cpp`

```cpp
/*
二进制掩码枚举法
二进制掩码枚举是一种通过二进制数的位状态来表示 “选取 / 不选取” 的暴力枚举方法，
核心是用二进制数的每一位对应原始序列中元素的选取状态。

假设原始序列有n个元素（字符串，数组），我们需要枚举所有可能的子序列（包含空序列）
用一个 n 位的二进制数（称为“掩码”，mask）表示选举规则：
* 掩码的第i位为1  就选第i个元素，加入子序列

范围限制
时间复杂度 O(n * 2^n)
空间复杂度O(n)
一般可使用范围为 n <= 20
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
    string s;
    cin >> s;
    int ok=0;
    for(int i=0;i < (1 << n);i++)  // 最大范围是2^n
    {
        string m1,m2;
        vector<int> a;
        for(int j=0;j<n;j++)
        {
            if(i & (1 << j))
            {
                m1 += s[j];
                a.push_back(j+1);
            }
            else{
                m2 += s[j];
            }
        }
        int ok1=1;         // 后面是检测规则
        for(int i=1;i<m1.size();i++)
        {
            if(m1[i] < m1[i-1])
            {
                ok1=0;
                break;
            }
        }
        if(!ok1) continue;
        if(m2 == string(m2.rbegin(),m2.rend()))
        {
            cout<<a.size()<<endl;
            for(int i=0;i<a.size();i++)
            {
                cout<<a[i]<<" ";
            }
            ok=1;
            break;
        }
    }
    if(!ok)
    {
        cout<<"-1";
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
```

## 八个方向数组

原文件：`算法/八个方向数组.cpp`

```cpp
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1}; 
void solve()
{
    for(auto dx : {-1,0,1})
    {
        for(auto dy : {-1,0,1})
        {
            if(dx == dy && dx == 0) continue;
            // ......
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
```

## 分解质因数

原文件：`算法/分解质因数.cpp`

```cpp
/*
将数n中的质因数全部存入
数组p
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;
vector<int> p;
void disc(int n){
    p.clear();   // 清除里面之前的元素
    for(int i=2;i*i <= n;i++)
    {
        if(n%i == 0)
        {
            p.push_back(i);
            while(n % i == 0) n/=i;
        }
        if(n > 1) p.push_back(n);
    }
}
void solve()
{
    
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
```

## 前缀，差分

原文件：`算法/前缀，差分.cpp`

```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    //前缀和
    int N;
    cin>> N;
    vector<int> a(N+1);
    vector<int> prefix(N)+1;
    for(int i=1;i<=N;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=N;i++)
    {
        prefix[i]=prefix[i-1] + a[i];
    }
    //差分 
    //前缀的差分是原数组，反过来也一样
    vector<int> diff(N+1);
    for(int i=1;i<=N;i++)
    {
        diff[i]=a[i] - a[i-1];
    }
    //如果修改差分，例如让原数组[l,r]加一，
    //则让l对应差分加一，r+1对应差分减一，
    //差分加一代表他从这个位置以后所有元素都加一
    //根据自己需求，进行计算，采用一次差分或者二次
    //进行优化复杂度，最后前缀还原数组


}
```

## 双堆动态维护第k大值

原文件：`算法/双堆动态维护第k大值.cpp`

```cpp
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
```

## 基本算法

原文件：`算法/基本算法.cpp`

```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){       
     //visited 是数组，专门记录某一编号
     //的数据是否被访问过（不是算法，属于一种技巧）
     //数组默认为0（无需设置值）
     //如果被访问过，就将其改为1
     
    

}
```

## 天空数

原文件：`算法/天空数.cpp`

```cpp
/*
何为天空数，两个数乘积，是一个数的平分 类似于 2 * 8 = 4^2
现在给你一组数，让你找其中天空数的个数，怎么计算呢？
可以发现，将每个数分解成其质数乘积的形式，假如其分解出来的质数，
这种有偶数个，那么这本身就符合平方的定义，如果是奇数个，
那么就需要，找到另一个数，他所拥有的奇数个数的因子，和这个数相同，
那么这两个数就可以凑成一对
那么就可以将每个数都压缩，压缩后的数如果相同，那么就证明他们可以凑成一对
再进行计算
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
    map<int,int> mp;
    for(int i = 0;i < n ;i++) cin >> a[i];
    for(int i = 0;i < n;i++)
    {
        int k = 1;
        int m = a[i];
        for(int j = 2;j <= m / j;j++)
        {
            if(m % j == 0)
            {
                int num = 0;
                while(m % j == 0)
                {
                    num++;
                    m /= j;
                }
                if(num & 1) 
                {
                    k *= j;
                }
            }
        }
        if(m > 1) k *= m;
        mp[k] ++;
    }
    int ans = 0;
    for(auto p : mp)
    {
        int j = p.second;
        if(j > 1)
        {
            ans += (j - 1) * j / 2;
        }
    }
    cout << ans;
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
```

## 差分约束

原文件：`算法/差分约束.cpp`

```cpp
/*
题目形式：给定若干个不等式，类似xi - xj <= ci,判断所有不等式是否有解，有解给出一组变量

对于边，对应的点，往小更新，然后判断负环，如果有负环，就无法成立

将所有不等式的形式都转化为 xi <= xj + ci,就是从xj往xi建边

spfa：如果任意节点进入队列次数 > 节点数 - 1，说明有负环
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
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for(int i = 0; i < m;i++){
        int u, v, w;
        // u - v <= w => u <= v + w
        cin >> u >> v >> w;
        adj[v].push_back({u, w});
    }

    // 为了保证图是连通的，并且能到达所有节点，通常建立一个超级源点0，向所有点连边，边权为0
    for(int i = 1; i <= n;i++){
        adj[0].push_back({i, 0});
    }

    vector<int> dist(n + 1, 1e18);
    vector<int> cnt(n + 1, 0);
    vector<bool> inq(n + 1, false);
    queue<int> q;

    dist[0] = 0;
    q.push(0);
    inq[0] = true;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        inq[u] = false;

        for(auto& edge : adj[u]){
            int v = edge.first;
            int w = edge.second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u] + 1;
                if(cnt[v] > n){
                    cout << "NO" << endl; // 存在负环，无解
                    return;
                }
                if(!inq[v]){
                    q.push(v);
                    inq[v] = true;
                }
            }
        }
    }

    // 有解，输出一组可行解
    for(int i = 1; i <= n; ++i) {
        cout << dist[i] << (i == n ? "" : " ");
    }
    cout << endl;
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
```

## 快速递增

原文件：`算法/快速递增.cpp`

```cpp
pair<long long, long long> fib_fast(long long n) {
    if (n == 0) return {0, 1};  // 基线条件：F(0)=0，F(1)=1
    auto [a, b] = fib_fast(n >> 1);  // 递归计算 k = n//2，得到 {F(k), F(k+1)}
    long long c = a * (2*b - a);     // 恒等式：F(2k) = F(k) * (2*F(k+1) - F(k))
    long long d = a*a + b*b;         // 恒等式：F(2k+1) = F(k)^2 + F(k+1)^2
    if ((n & 1) == 0) return {c, d}; // n为偶数时，n=2k → 返回 {F(2k), F(2k+1)}
    else return {d, c + d};          // n为奇数时，n=2k+1 → 返回 {F(2k+1), F(2k+2)}（因F(2k+2)=F(2k+1)+F(2k)）
}
```

## 数学符号

原文件：`算法/数学符号.cpp`

```cpp
#include<bits/stdc++.h>
using namespace std;
int mainn(){
    int x,a,b;
    //根号
    sqrt(x);
    //绝对值
    abs(x);
    fabs(x);//输出浮点数
    //向上取整
    ceil(x);
    //向下取整
    floor(x);
    //四舍五入
    round(x);
    //幂函数
    pow(a,b);
}
```

## 离散化天际线

原文件：`算法/离散化天际线.cpp`

```cpp
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

void solve()
{
    vector<int> l;//左端点
    vector<int> r;//右端点
    vector<int> h;//高度
    vector<int> a;//相当于一个跳板，为l,r离散化做准备
    ;//离散化后对应高度
    int lr,H,rr;
    while(cin>>lr>>H>>rr)
    {
        l.emplace_back(lr);
        h.emplace_back(H);
        r.emplace_back(rr);
        a.emplace_back(lr);
        a.emplace_back(rr);
    }
    sort(all(a));
    a.erase(unique(all(a)),a.end());
    int n=a.size();
    vector<int> b(n-1,0);
    for(int i=0;i<l.size();i++)//将l，r离散化
    {
        l[i]=lower_bound(all(a),l[i])-a.begin();//寻找第一个大于或者等于的元素位置
        r[i]=lower_bound(all(a),r[i])-a.begin();
        for(int j=l[i];j<r[i];j++)
        {
            if(h[i]>b[j])
            {
                b[j]=h[i];//h[i]是此时的a[i],b[i]的高度，将其离散化后存入记录高度的数组
            }
        }
    }
    for(int i=0;i<b.size();i++)
    {
        if(i==0){
            cout<<a[i]<<" "<<b[i]<<" ";
        }
        else if(b[i] != b[i-1])
        {
            cout<<a[i]<<" "<<b[i]<<" ";
        }
    }
    cout<<a.back()<<" 0";
}
//将每组测试用例的处理逻辑写在里面

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
```

## 移动窗口

原文件：`算法/移动窗口.cpp`

```cpp
// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
 
constexpr int MOD = 1e9 + 7;
// -9.2e18 ~ 9.2e18
//链接：https://ac.nowcoder.com/acm/contest/92182/K来源：牛客网有

 
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(all(v));
 
    int j = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        while (j < n and v[j] - v[i] <= k)
        {
            j++;
        }    //移动窗口，比二分快，
        auto m = j - i;
        ans = max(ans, m);
    }
 
    cout << ans * 1.0 / n;
}
 
signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    cout << setiosflags(ios::fixed) << setprecision(4);
    int TT = 1;
    // cin >> TT;
    while (TT--)
    {
        solve();
        // cout << endl;
    }
}
```

