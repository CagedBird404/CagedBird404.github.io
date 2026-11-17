/*
如果a与b均为整数，则有整数x和y，使ax + by = gcd(a,b);

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

如果a和b不是全为0的整数，并且ax + by = c有解，那么 c 必须是 gcd(a, b) 的整数倍

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
    cout << abs(now);
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