---
title: "算法 · 莫队"
published: 2026-11-16
category: "算法"
tags: [学习笔记, C++]
description: "按主题整理的原始学习代码，保留注释与实现。"
draft: false
---

本文整理自我的本地学习代码，按文件分节，保留原有实现与注释。

> 整理说明：这些是不同阶段的练习、模板和实验代码，未逐一编译或验证，不代表所有实现均正确。使用时需结合题目、输入范围和编译环境。部分代码使用 GCC 的 `bits/stdc++.h`，Windows 小程序可能依赖 `windows.h`、`conio.h`。

## 1普通莫队

原文件：`算法/莫队/1普通莫队.cpp`

```cpp
/*
莫队算法是解决批量的，可离线的区间查询问题，适用性广泛

按照排序策略
经典排序策略：
（1）左端点所在块号从小到大
（2）右端点数值从小到大

奇偶排序
（1）左端点在块号从小到大
（2）块号为奇，r从小到大，偶，从大到小

建立滑动窗口
左右边界都移动

时间复杂度n * sqrt(n)
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

struct node{
    int l,r,id;
};

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int> a(n+1);
    for(int i = 1;i <= n;i++) cin >> a[i];
    int len = sqrt(n);
    int num = (n + len - 1) / len;
    vector<int> b(n+1);
    for(int i = 1;i <= n;i++)
    {
        b[i] = (i - 1) / len + 1;
    }
    vector<int> bl(num + 1),br(num + 1);
    for(int i = 1;i <= num;i++)
    {
        bl[i] = (i - 1) * len + 1;
        br[i] = min(n, i * len);
    }
    vector<node> k(m);
    for(int i = 0;i < m;i++)
    {
        cin >> k[i].l >> k[i].r;
        k[i].id = i;
    }
    sort(all(k),[&](node a,node c){
        if(b[a.l] != b[c.l]) return b[a.l] < b[c.l];
        return a.r < c.r;
    });
    vector<int> ans(m);
    int kind = 0;
    map<int,int> mp;
    int l = 1, r = 0;
    for(int i = 0; i< m; i++)
    {
        
        while(l < k[i].l)
        {
            mp[a[l]]--;
            if(mp[a[l]] == 0) kind--;
            l++;
        }
        
        while(l > k[i].l)
        {
            l--;
            mp[a[l]]++;
            if(mp[a[l]] == 1) kind++;
        }

        while(r < k[i].r)
        {
            r++;
            mp[a[r]]++;
            if(mp[a[r]] == 1) kind++;
        }

        while(r > k[i].r)
        {
            mp[a[r]]--;
            if(mp[a[r]] == 0) kind--;
            r--;
        }
        
        ans[k[i].id] = kind;
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

## 1普通莫队概率类

原文件：`算法/莫队/1普通莫队概率类.cpp`

```cpp
/*
在l到r的范围内，选两个数字，相同的概率是多少，要化简到最小
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

struct node{
    int l,r,id;
};

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int> a(n+1);
    for(int i = 1;i <= n;i++) cin >> a[i];

    int len = sqrt(n);
    int num = (n + len - 1) / len;

    vector<int> b(n+1);
    for(int i = 1;i <= n;i++)
        b[i] = (i - 1) / len + 1;

    vector<int> bl(num + 1),br(num + 1);
    for(int i = 1;i <= num;i++)
    {
        bl[i] = (i - 1) * len + 1;
        br[i] = min(n, i * len);
    }

    vector<node> k(m);
    for(int i = 0;i < m;i++)
    {
        cin >> k[i].l >> k[i].r;
        k[i].id = i;
    }

    sort(all(k),[&](node a,node c){
        if(b[a.l] != b[c.l]) return b[a.l] < b[c.l];
        return a.r < c.r;
    });

    vector<pair<int,int>> ans(m);

    vector<int> mp(n + 1, 0); 
    int l = 1, r = 0;         
    int now = 0;

    for(int i = 0; i < m; i++)
    {
        while(l < k[i].l)
        {
            now -= mp[a[l]] * (mp[a[l]] - 1) / 2;
            mp[a[l]]--;
            now += mp[a[l]] * (mp[a[l]] - 1) / 2;
            l++;
        }

        while(l > k[i].l)
        {
            l--;
            now -= mp[a[l]] * (mp[a[l]] - 1) / 2;
            mp[a[l]]++;
            now += mp[a[l]] * (mp[a[l]] - 1) / 2;
        }

        while(r < k[i].r)
        {
            r++;
            now -= mp[a[r]] * (mp[a[r]] - 1) / 2;
            mp[a[r]]++;
            now += mp[a[r]] * (mp[a[r]] - 1) / 2;
        }

        while(r > k[i].r)
        {
            now -= mp[a[r]] * (mp[a[r]] - 1) / 2;
            mp[a[r]]--;
            now += mp[a[r]] * (mp[a[r]] - 1) / 2;
            r--;
        }

        int len = k[i].r - k[i].l + 1;
        int base = len * (len - 1) / 2;

        ans[k[i].id] = {now, base};
    }

    for(int i = 0;i < m; i++)
    {
        if(ans[i].first == 0)
        {
            cout << "0/1" << endl;
            continue;
        }
        int g = gcd(ans[i].first, ans[i].second);
        cout << ans[i].first / g << "/" << ans[i].second / g << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int TT = 1;
    cin >> TT;
    while (TT--)
        solve();
}
```

## 2带修莫队

原文件：`算法/莫队/2带修莫队.cpp`

```cpp
/*
与普通莫队相比，多了一个修改操作

node也就多了一个属性 t

块长设置为n的三分之二次方

排序顺序
（1）l所在块从小到大
（2）r所在块从小到大
（3）t从小到大

时间复杂度为n的五分之三次方
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

struct node
{
    int l,r,id,t;
};

void solve()
{
    int m,n;
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1;i <= n;i++) cin >> a[i];
    int len = max(1ll,(int)pow(n,2.0 / 3.0));
    int num = (n + len - 1) / len;
    vector<int> b(n + 1);
    for(int i = 1;i <= n;i++)
    {
        b[i] = (i - 1) / len + 1;
    }
    vector<int> bl(num + 1), br(num + 1);
    for(int i = 1;i <= num;i++)
    {
        bl[i] = (i - 1) * len + 1;
        br[i] = min(n,i * len);
    }
    int idb = 0;
    int T = 0;
    vector<pair<int,int>> up;
    vector<node> k;
    for(int i = 1;i <= m;i++)
    {
        char op;
        cin >> op;
        if(op == 'Q')
        {
            idb++;
            int x,y;
            cin >> x >> y;
            node p;
            p.l = x, p.r = y, p.id = idb, p.t = T;
            k.push_back(p);
        }
        else{
            T++;
            int x,y;
            cin >> x >> y;
            up.push_back({x,y});
        }
    }
    sort(all(k),[&](node x,node y){
        if(b[x.l] != b[y.l]) return b[x.l] < b[y.l];
        if(b[x.r] != b[y.r]) return b[x.r] < b[y.r];
        return x.t < y.t;
    });
    vector<int> ans(idb + 1);
    vector<int> mp(1e6 + 1);
    int l = 1, r = 0, kind = 0;
    int now = 0;
    for(int i = 0;i < idb; i++)
    {
        while(l < k[i].l)
        {
            mp[a[l]]--;
            if(mp[a[l]] == 0) kind--;
            l++;
        }
        while(l > k[i].l)
        {
            l--;
            mp[a[l]]++;
            if(mp[a[l]] == 1) kind++;
        }
        while(r < k[i].r)
        {
            r++;
            mp[a[r]]++;
            if(mp[a[r]] == 1) kind++;
        }
        while(r > k[i].r)
        {
            mp[a[r]]--;
            if(mp[a[r]] == 0) kind--;
            r--;
        }
        while(now < k[i].t)
        {
            now++;
            int w = up[now - 1].first;
            if(l <= w && w <= r)
            {
                mp[a[w]]--;
                if(mp[a[w]] == 0) kind--;
            }
            swap(a[w],up[now-1].second);
            if(l <= w && w <= r)
            {
                mp[a[w]]++;
                if(mp[a[w]] == 1) kind++;
            }
        }
        while(now > k[i].t)
        {
            
            int w = up[now - 1].first;
            if(l <= w && w <= r)
            {
                mp[a[w]]--;
                if(mp[a[w]] == 0) kind--;
            }
            swap(a[w],up[now-1].second);
            if(l <= w && w <= r)
            {
                mp[a[w]]++;
                if(mp[a[w]] == 1) kind++;
            }
            now--;
        }
        ans[k[i].id] = kind;
    }
    for(int i = 1;i <= idb;i++)
    {
        cout << ans[i] << endl;
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

## 3只增回滚莫队

原文件：`算法/莫队/3只增回滚莫队.cpp`

```cpp
/*
给定一个长度为n的数组，如果一段范围内，数字x出现c次
他的重要度就是 x * c ，求范围上每种数字的重要度的最大值

窗口加入数字时，区间信息和答案信息都更新
窗口删数字时，只更新区间信息不更新答案信息

对于l在同一区块的分两种
一种是r也在同一区块，进行暴力求解
第二种是r在其他区，利用回溯的方法一次一次进行扩充

答案信息利用回滚来更新

排序策略：
（1）l所在块从小到大
（2）r从小到大
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

struct node
{
    int l, r, id;
};

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int> a(n+1);
    for(int i = 1;i <= n;i++) cin >> a[i];

    vector<int> unique_vals = a;
    sort(all(unique_vals));
    unique_vals.erase(unique(unique_vals.begin(), unique_vals.end()), unique_vals.end());

    // 离散化映射，使用 map 或者直接在 unique_vals 中二分查找
    unordered_map<int, int> compress;

    for (int i = 0; i < unique_vals.size(); i++) {
        compress[unique_vals[i]] = i;
    }

    // 用离散化后的值替换原数组
    for (int i = 1; i <= n; i++) {
        a[i] = compress[a[i]];
    }


    int len = sqrt(n);
    int num = (n + len - 1) / len;
    vector<int> b(n+1);
    for(int i = 1; i <= n; i++)
    {
        b[i] = (i - 1) / len + 1;
    }
    vector<int> bl(num + 1),br(num + 1);
    for(int i = 1;i <= num; i++)
    {
        bl[i] = (i - 1) * len + 1;
        br[i] = min(n, i * len);
    }
    vector<node> k(m);
    for(int i = 0; i < m;i++)
    {
        cin >> k[i].l >> k[i].r;
        k[i].id = i;
    }
    vector<int> ans(m);
    sort(all(k),[&](node x, node y){
        if(b[x.l] != b[y.l]) return b[x.l] < b[y.l];
        return x.r < y.r;
    });
                            //qi代表到哪个任务
    for(int nk = 1, qi = 0; nk <= num && qi < m;nk++) //两个截止条件，一个任务数量，一个块数
    {
        int now = 0; 
        vector<int> mp(unique_vals.size(),0);
        int l = br[nk] + 1, r = br[nk];
        for( ; qi < m && b[k[qi].l] == nk; qi++) //当前任务的左边界在这块上
        {
            if(k[qi].r <= br[nk])
            {
                int tnow = 0;
                vector<int> tmp(unique_vals.size(),0);
                for(int i = k[qi].l;i <= k[qi].r; i++) tmp[a[i]]++;
                for(int i = k[qi].l; i <= k[qi].r; i++) tnow = max(tnow, unique_vals[a[i]] * tmp[a[i]]);
                ans[k[qi].id] = tnow;
            }
            else{
                while(r < k[qi].r)
                {
                    r++;
                    mp[a[r]]++;
                    now = max(now, unique_vals[a[r]] * mp[a[r]]);
                }
                int temp = now;//对于你这个块内的查询，因为你的r是递增的，那么你的r1就可以真实的往前走，而你的l可能是参差不齐，那么你就一直维护在一个固定值，然后记录你扩展l之前的答案，那么对于下一个l，你直接再次扩展就好了
                while(l > k[qi].l)
                {
                    l--;
                    mp[a[l]]++;
                    now = max(now, unique_vals[a[l]] * mp[a[l]]);
                }
                ans[k[qi].id] = now;
                now = temp;
                while(l <= br[nk])
                {
                    mp[a[l]]--;
                    l++;
                }
            }
        }
    }
    for(int i = 0;i < m; i++)
    {
        cout << ans[i] << endl;
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

