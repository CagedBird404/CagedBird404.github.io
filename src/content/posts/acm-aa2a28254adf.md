---
title: "分治 平面最近点对"
published: 2026-11-16
category: ACM竞赛模板
tags: ["基础算法·搜索与分治"]
description: "分治 平面最近点对的学习实现与使用笔记。"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

分治 平面最近点对的学习实现与使用笔记。

## 使用说明

这里记录我的实现和理解。使用时，我会先确认输入输出、下标和数据范围，再按具体题目调整。

> 我在这份代码里用了 `#define int long long`。使用时要留意它对接口和内存的影响；也可以改用 `using i64 = long long`，显式选择需要的整数类型。

<!-- ACM_VALIDATION -->

## 代码

```cpp
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

int ksm(int base,int a)
{
    int ans=1;
    while(a)
    {
        if (a & 1)
        {
            ans = ans * base;
        }
        base = base * base;
        a >>=1;
    }
    return ans;
}

struct date{
    int x;
    int y;
};
int cal(date a,date b)
{
    return ksm((a.x - b.x) , 2) + ksm((a.y - b.y) , 2);
}
vector<date> a;
int ans; 
int fz(int l,int r)
{
    if(l>=r)
    {
        return LLONG_MAX;
    }
    if(l+1 == r)
    {
        return cal(a[l],a[r]);
    }
    int mid = l + (r - l) / 2;
    int s=fz(l,mid);
    int h=fz(mid + 1,r);
    ans = min(s,h);
    vector<date> p;
    for (int i = l;i<=r ;i++)
    {
        if((a[i].x - a[mid].x) * (a[i].x - a[mid].x) < ans)
        {
            p.emplace_back(a[i]);
        }
    }
    sort(all(p),[](auto a,auto b){
        return a.y < b.y;
    });
    for (int i=0;i<p.size();i++)
    {
        for(int j=i+1;j<p.size();j++)
        {
            if((p[i].y - p[j].y) * (p[i].y - p[j].y) < ans)
            {
                ans = min(ans,cal(p[i],p[j]));
            }
            else{
                break;
            }
        }
    }
    return ans;
}
void solve()
{
    ans = LLONG_MAX;
    int n;
    cin >> n;
    a.resize(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i].x >> a[i].y;
    }
    sort(all(a),[](date a,date b){
        return a.x<b.x;
    });
    cout<<fz(0,n-1);

}
//将每组测试用例的处理逻辑写在里面

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
```

## 相关知识点

[DFS](/posts/acm-keywords/#dfs) · [BFS](/posts/acm-keywords/#bfs) · [二分查找](/posts/acm-keywords/#binary-search)

- [最长上升子序列](/posts/acm-30bcfb439008/)
- [ST表](/posts/acm-227c4f00c3c6/)
- [Tarjan](/posts/acm-18decad757c7/)
- [树型dp](/posts/acm-cde7944003fd/)
- [bfs 多源找最近最大值](/posts/acm-addc6cc81933/)

