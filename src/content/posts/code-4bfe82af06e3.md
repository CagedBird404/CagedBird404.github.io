---
title: "算法 · 递归"
published: 2026-11-16
category: "算法"
tags: [学习笔记, C++]
description: "按主题整理的原始学习代码，保留注释与实现。"
draft: false
---

本文整理自我的本地学习代码，按文件分节，保留原有实现与注释。

> 整理说明：这些是不同阶段的练习、模板和实验代码，未逐一编译或验证，不代表所有实现均正确。使用时需结合题目、输入范围和编译环境。部分代码使用 GCC 的 `bits/stdc++.h`，Windows 小程序可能依赖 `windows.h`、`conio.h`。

## 分治 平面最近点对

原文件：`算法/递归/分治 平面最近点对.cpp`

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

## 分治 排序

原文件：`算法/递归/分治 排序.cpp`

```cpp
#include <iostream>
#include <vector>
using namespace std;

// 合并两个有序子数组
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;   // 左半部分长度
    int n2 = right - mid;      // 右半部分长度

    // 临时数组
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    // 合并两个临时数组到原数组
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // 处理剩余的元素
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// 递归归并排序
void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;  // 递归结束条件

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);       // 排序左半部分
    mergeSort(arr, mid + 1, right);  // 排序右半部分
    merge(arr, left, mid, right);    // 合并左右两部分
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 6, 3};

    cout << "排序前：";
    for (int x : arr) cout << x << " ";
    cout << endl;

    mergeSort(arr, 0, arr.size() - 1);

    cout << "排序后：";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
```

## 分治 逆序对

原文件：`算法/递归/分治 逆序对.cpp`

```cpp
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

void solve()
{
    
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
        cout << endl;
    }
}
```

## 分治 静态区间子区间最大和

原文件：`算法/递归/分治 静态区间子区间最大和.cpp`

```cpp
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

int fz(int l,int r,vector<int> &a)
{
    if(l==r)
    {
        return a[l];
    }
    int mid=l + (r - l)/2;
    int lmax=fz(l,mid,a);//不断细分，最后返回左边最大值
    int rmax=fz(mid+1,r,a);//返回右边最大值
    vector<int> L(mid-l+1);
    vector<int> R(r-mid);
    //一共三种情况，在左边，在右边，拼接，如果是拼接那就一定左加右大于单独的左和右，最后输出他仨最大的就行
    for(int i=0;i<mid-l+1;i++) L[i]=a[i+l];
    for(int j=0;j<r-mid;j++) R[j]=a[j+mid+1];
    int Max1=LLONG_MIN,Max2=LLONG_MIN,Max3=LLONG_MIN,Max=LLONG_MIN;
    for(int i=(mid-l);i>=0;i--)//后缀和处理，和前缀和一样，结果不影响，目的是和右半部分的前缀和组合，能拼接
    {
        int f=0;
        f+=L[i];
        Max1=max(Max1,f);//类似dp的寻找最大值
    }
    for(int i=0;i<(r-mid);i++)
    {
        int e=0;
        e+=R[i];
        Max2=max(Max2,e);
    }
    Max3=Max1+Max2;
    Max=max({Max3,lmax,rmax});
    return Max;
}


void solve()
{
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>> l >> r;
        cout<<fz(l,r,a)<<endl;
    }
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
        cout << endl;
    }
}
```

## 回溯 分数字

原文件：`算法/递归/回溯 分数字.cpp`

```cpp
// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

constexpr int MOD = 998244353;
// -9.2e18 ~ 9.2e18
int ans;
double n,k;
void dp(double now,double s,double num)
{
    //cout<<now<<" ";
    if(num==1) 
    {
        ans++;
        return;
    }
    
    double Max=now-(num-1);
    double Min=(now+num-1) / num;
     Max=min(Max,s);
    for(int i=Min;i<=Max;i++)
    {
        dp(now-i,i,num-1);
    }
}

void solve()
{
    ans=0;
    cin>>n>>k;
    dp(n,n,k);
    cout<<ans;
}


signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    //cout << setiosflags(ios::fixed) << setprecision(2);
    int TT = 1;
     //cin >> TT;
    while (TT--)
    {
        solve();
         cout << endl;
    }
}
```

## 深化-斐波那契

原文件：`算法/递归/深化-斐波那契.cpp`

```cpp
#include<bits/stdc++.h>   //记忆化搜索
using namespace std;
int n;vector<int> saved(n+1,-1);
//进行优化，他会有很多分支，
int f(int n){           //计算很多重复数据，太慢，
    if(n<=2)            //将其保存，再调用，会快很多
    {                   //最后输出保存的数据就行
        return 1;
    }
    if(saved[n]==-1)
    {
        saved[n]=f(n-1)+f(n-2);
    }
    return saved[n];
}
int main(){
cin>> n;saved = vector<int> (n+1,-1);
cout<<f(n);
}
```

## 简单-阶乘函数

原文件：`算法/递归/简单-阶乘函数.cpp`

```cpp
#include<bits/stdc++.h.
using namespace std;
int fact(int n)//传递参数，拆解问题
{
    if (n==1) return 1;
    return fact(n - 1) * n;
}
int main(){
    
}
```

## 经典递归-汉诺塔

原文件：`算法/递归/经典递归-汉诺塔.cpp`

```cpp
#include<bits/stdc++.h>
using namespace std;
int hanoi(int n,char F,char A,char T)
{
    if(n==1)
    {
        cout<<"move"<<n<<"from"<<F<<"to"<<T;
        return;
    }
    hanoi(n-1,F,T,A);
    cout<<"move"<<n<<"from"<<F<<"to"<<T;
    hanoi(n-1,A,F,T);
}
/*递归思想：
    1、确定函数是什么作用
    2、从最简单问题（源头问题）开始，一步一步进行拆分
    3、拆分的问题都可以再用函数解决
    4，函数不一定是直接解决问题的，可能也是一种解决手段
    5、注意：一定要坚定自己的函数作用
*/
int main(){

}
```

