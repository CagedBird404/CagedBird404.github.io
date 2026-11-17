---
title: "sg函数"
published: 2026-11-16
category: ACM竞赛模板
tags: ["数学·博弈论"]
description: "图游戏概念\r 任何局面都认为是图中的点，每一个局面都可以通过一种行动，走向图中的另一个点\r"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

图游戏概念 任何局面都认为是图中的点，每一个局面都可以通过一种行动，走向图中的另一个点

## 使用说明

这里记录我的实现和理解。使用时，我会先确认输入输出、下标和数据范围，再按具体题目调整。

图游戏概念
任何局面都认为是图中的点，每一个局面都可以通过一种行动，走向图中的另一个点
如果当前行动有若干个，那么后继节点就有若干个。最终，必败局面的点认为没有后继节点
每个公平游戏都可以对应一张图
我们规定必败点是A，那么sg(A) = 0
假设状态点是B，那么sg(B) = 查看B所有后继节点的sg值，其中没有出现过的最小自然数
如果sg(B) != 0，那么状态B为必胜态， = 0 则为必败态
sg定理，如果一个ICG游戏(总)，由若干个独立的ICG子游戏构成，那么：
sg(总) = sg(分1) ^ sg(分2) ^ sg(分3)......

> 我在这份代码里用了 `#define int long long`。使用时要留意它对接口和内存的影响；也可以改用 `using i64 = long long`，显式选择需要的整数类型。

<!-- ACM_VALIDATION -->

## 代码

```cpp
/*
图游戏概念
任何局面都认为是图中的点，每一个局面都可以通过一种行动，走向图中的另一个点
如果当前行动有若干个，那么后继节点就有若干个。最终，必败局面的点认为没有后继节点
每个公平游戏都可以对应一张图

我们规定必败点是A，那么sg(A) = 0
假设状态点是B，那么sg(B) = 查看B所有后继节点的sg值，其中没有出现过的最小自然数
如果sg(B) != 0，那么状态B为必胜态， = 0 则为必败态

sg定理，如果一个ICG游戏(总)，由若干个独立的ICG子游戏构成，那么：
sg(总) = sg(分1) ^ sg(分2) ^ sg(分3)......
*/

//我其实更倾向于把他归于一类思想，主要也是打表记忆化的手段
//下面是P8369

#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;
vector<int> sg(1001);
vector<int> vi(1001);
int a,b,c;

int cc(int x)
{
    if(x < min({a,b,c})) return 0;
    if(vi[x]) return sg[x];
    vi[x] = 1;
    set<int> S;
    
    for(int i = 0;i <= x;i++)
    {
        int o = 0;
        if(i <= x - a) S.insert(cc(i) ^ cc(x - i - a));
        if(i <= x - b) S.insert(cc(i) ^ cc(x - i - b));
        if(i <= x - c) S.insert(cc(i) ^ cc(x - i - c));
    }
    int k = 0;
    while(S.count(k)) k++;
    return sg[x] = k;
}

void solve()
{
    cin >> a >> b >> c;
    int q;
    cin >> q;
    while(q--)
    {
        int x;
        cin >> x;
        cout << (!cc(x) ? 2 : 1) << endl;
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
```

## 相关知识点

[动态规划](/posts/acm-keywords/#dp) · [复杂度](/posts/acm-keywords/#complexity)

- [01背包问题](/posts/acm-b56927a13e82/)
- [数位dp](/posts/acm-927f6f82d7ce/)
- [板子简洁版](/posts/acm-32e5ca0175a7/)

