---
title: "算法 · 数论"
published: 2026-11-16
category: "算法"
tags: [学习笔记, C++]
description: "按主题整理的原始学习代码，保留注释与实现。"
draft: false
---

本文整理自我的本地学习代码，按文件分节，保留原有实现与注释。

> 整理说明：这些是不同阶段的练习、模板和实验代码，未逐一编译或验证，不代表所有实现均正确。使用时需结合题目、输入范围和编译环境。部分代码使用 GCC 的 `bits/stdc++.h`，Windows 小程序可能依赖 `windows.h`、`conio.h`。

## 01裴蜀定理

原文件：`算法/数论/01裴蜀定理.cpp`

````cpp
/*
如果a与b均为整数，则有整数x和y，使ax + by = gcd(x,y);

# P4549 【模板】裴蜀定理

## 题目描述

给定一个包含 $n$ 个元素的**整数**序列 $A$，记作 $A_1,A_2,A_3,...,A_n$。

求另一个包含 $n$ 个元素的待定**整数**序列 $X$，记 $S=\sum\limits_{i=1}^nA_i\times X_i$，使得 $S>0$ 且 $S$ 尽可能的小。

## 输入格式

第一行一个整数 $n$，表示序列元素个数。  

第二行 $n$ 个整数，表示序列 $A$。

## 输出格式

一行一个整数，表示 $S>0$ 的前提下 $S$ 的最小值。

## 输入输出样例 #1

### 输入 #1

```
2
4059 -1782

```

### 输出 #1

```
99
```

## 说明/提示

对于 $100\%$ 的数据，$1 \le n \le 20$，$|A_i| \le 10^5$，且 $A$ 序列不全为 $0$。
*/


/*
如果a和b都是不为0的整数，那么有整数x和y，使得ax + by = gcd(a, b)
辗转相除法：gcd(a, b) = gcd(b, a % b) 直到其中一个为0

还能怎么理解，对于a和b，随意给定整数x和y，你能得到的最小正数差值

如果a和b不是全为0的整数，并且ax + by = c有解，那么x一定是gcd(a, b)的整数倍

这个多项，类似于a b c d也成立
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
    int now;
    cin >> now;
    n--;
    while(n--)
    {
        int k;
        cin >> k;
        now = gcd(k, now);
    }
    cout << now;
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
````

## 02拓展欧几里得算法

原文件：`算法/数论/02拓展欧几里得算法.cpp`

```cpp
#include <bits/stdc++.h> 
using namespace std;
#define int long long
#define endl '\n'

/*
拓展欧几里得算法是在裴蜀定理的基础上来实现的，裴蜀定理是知道这个成立，那么拓展欧几里得算法就是得到一组特解
对于 ax + by = c 这个公式
这个函数返回的是gcd(a, b),也就是说
返回的是另一个式子at + bh = gcd(a, b);
而且对应x和y的位置，会变成相同比例的t和h
所以得出来的t将其按照比例放大就可以了

拓展欧几里得还有很多算法：
1、求逆元
逆元的本质是什么，对于一个数a，他的逆元是x，那么就相当于x和1/a是等效的，那么也就等同于ax % b = 1
那么你就可以简化成ax - by = 1, 那么也就是ax + by = 1，其中b是模数，拓展欧几里得有点在于，快，而且b不用是质数，只是a和b互质
但是求出来的逆元x有可能是负数，要用(x + MOD) % MOD;
*/

/*
算法的实现其实还是和站专项出发有关，就是用递归去实现辗转相除的同时去得到x和y
*/

int extend_gxd(int a, int b, int &x, int &y)
{
    //对于最终相态肯定是 1 * gcd(a, b) + 0 * 0 = gcd(a, b)
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    int d = extend_gxd(b, a % b, y, x);
    y -= a / b * x;

    return d;
}

int ksm(int x, int y, int m)
{
    int ans = 1;
    while(y)
    {
        if(y & 1)
        {
            ans = ans * x % m;
        }
        x = x *x % m;
        y >>= 1;
    }
    return ans;
}

void solve()
{
    int x, y, m, n;
    cin >> m >> n;

    int g = extend_gxd(m, n, x, y);
    cout << ksm(m, n - 2, n) << endl;
    cout << (x % n + n) % n;
    
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}
```

## 03二元一次方程

原文件：`算法/数论/03二元一次方程.cpp`

```cpp
/*
二元一次不定方程，也叫丢番图方程
*/
```

## 大数取余

原文件：`算法/数论/大数取余.cpp`

```cpp
/*
对于很大的数字，进行取模，应该怎么办呢
比如10^1e5的数据
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

void solve()
{
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0;i < s.size();i++)
    {
        ans = (ans * 10 % MOD + (s[i] - '0')) % MOD;
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

## 大数次方取模

原文件：`算法/数论/大数次方取模.cpp`

```cpp
/*
给定整数x,y，你需要输出x^y % p的值
0 <= x <= 1e5 ,
0 <= y <= 10^1e5
1e5 <= p <= 1e9 + 7

*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

int ksm(int base, int exp, int MOD)
{
    int ans = 1;
    while (exp)
    {
        if (exp & 1)
        {
            ans = ans * base % MOD;
        }
        base = base * base % MOD;
        exp >>= 1;
    }
    return ans;
}
void solve()
{
    int x, p;
    string y;
    cin >> x >> y >> p;
    if (p == 1)
    {
        cout << 0;
        return;
    }

    int ans = 1 % p;
    int base = x % p;
    for(int i = 0;i < y.size();i++)
    {
        ans = ksm(ans, 10, p);
        int k = y[i] - '0';
        if(k)
        {
            ans = ans * ksm(base, k, p) % p;
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

## 拉格朗日插值法

原文件：`算法/数论/拉格朗日插值法.cpp`

```cpp
/*
简单来说，如果你在二维平面上有n个不同的点，
拉格朗日插值法可以帮你找出一个次数不超过n−1的多项式曲线，这条曲线会完美地穿过这 n个点。
通过这个多项式，你就可以估算出其他位置上的y值。
d 次多项式需要 (d+1) 个点。
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

// 快速幂
int qpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % MOD;

        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

// 拉格朗日插值
// 已知 n 个点 (x[i], y[i])
// 求 f(k)
//
// 要求：x[i] 两两不同
// 时间复杂度：O(n^2)
int lagrange(vector<int> x, vector<int> y, int k)
{
    int n = x.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int up = 1;
        int down = 1;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;

            // 分子：k - x[j]
            up = up * ((k - x[j] + MOD) % MOD) % MOD;
            // 分母：x[i] - x[j]
            down = down * ((x[i] - x[j] + MOD) % MOD) % MOD;
        }
        int term = y[i] * up % MOD;
        term = term * qpow(down, MOD - 2) % MOD;
        ans = (ans + term) % MOD;
    }

    return ans;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> x(n), y(n);

    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    int k;
    cin >> k;

    cout << lagrange(x, y, k) << endl;
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

## 欧拉函数

原文件：`算法/数论/欧拉函数.cpp`

```cpp
/*
求的是小于等于n，且与n互质的正整数有多少个
*/

#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

int Max = 1e6 + 10;
vector<int> is_prime(Max, 1);
vector<int> primes;
vector<int> pp(Max);

void cc(int n)
{
    is_prime[0] = is_prime[1] = 0;
    int num = 0;
    for(int i = 2;i <= n;i++)
    {
        if(is_prime[i])
        {
            primes.push_back(i);
            pp[i] = i;
            num++;
        }
        for(int j = 0;j < num && primes[j] * i <= n;j++)
        {
            is_prime[i * primes[j]] = 0;
            pp[i * primes[j]] = primes[j];
            if(i % primes[j] == 0) break;
        }
    }
}

int ksm(int x, int y)
{
    int ans = 1;
    while(y)
    {
        if(y & 1)
        {
            ans = ans * x % MOD;
        }
        x = x * x % MOD;
        y >>= 1;
    }
    return ans;
}

void solve()
{
    int x;
    cin >> x;
    int ans = x;
    ans %= MOD;
    while(x != 1)
    {
        ans = ans * (pp[x] - 1) % MOD;
        ans = ans * ksm(pp[x], MOD - 2) % MOD;
        int nu = pp[x];
        while((x % nu) == 0) x /= nu;
    }
    cout << ans;
}

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);                
    cout << setiosflags(ios::fixed) << setprecision(2); 
    int TT = 1;
    cin >> TT; cc(2e5);
    while (TT--)
    {
        solve(); 
        cout << endl;
    }
}
```

## 欧拉降幂

原文件：`算法/数论/欧拉降幂.cpp`

```cpp
/*
利用欧拉定理，来对大数次方对m取模的情况下进行计算  a的n次幂，对m取模
使用条件为a和m的gcd = 1

欧拉定理：x为m的欧拉函数，a的x次幂对m取余等于1
所以可以利用欧拉定理来进行大数次幂取模，也就是说直接让n等于n % x
*/

#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

int Max = 1e6 + 10;
vector<int> is_prime(Max, 1);
vector<int> primes;
vector<int> pp(Max);

void cc(int n)
{
    is_prime[0] = is_prime[1] = 0;
    int num = 0;
    for(int i = 2;i <= n;i++)
    {
        if(is_prime[i])
        {
            primes.push_back(i);
            pp[i] = i;
            num++;
        }
        for(int j = 0;j < num && primes[j] * i <= n;j++)
        {
            is_prime[i * primes[j]] = 0;
            pp[i * primes[j]] = primes[j];
            if(i % primes[j] == 0) break;
        }
    }
}

int ksm(int x, int y, int z)
{
    int ans = 1;
    while(y)
    {
        if(y & 1)
        {
            ans = ans * x % z;
        }
        x = x * x % z;
        y >>= 1;
    }
    return ans;
}

void solve()
{
    int x, y, m;
    cin >> x >> y >> m;
    int ans = m;
    int num = m;
    while(num != 1)
    {
        
        ans = ans / pp[num] * (pp[num] - 1);
        int nu = pp[num];
        while((num % nu) == 0) num /= nu;
    }
    y %= ans;
    cout << ksm(x, y, m);
}

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);                
    cout << setiosflags(ios::fixed) << setprecision(2); 
    int TT = 1;
    cin >> TT; cc(2e5);
    while (TT--)
    {
        solve(); 
        cout << endl;
    }
}
```

## 求逆

原文件：`算法/数论/求逆.cpp`

```cpp
/*
p是模数
*/

vector<int> inv(n + 1);
for(int i = 2;i <= n;i++)
{
    inv[i] = p - (p / i * inv[p % i] % p) % p;
}
```

## 高斯消元法

原文件：`算法/数论/高斯消元法.cpp`

```cpp
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
```

