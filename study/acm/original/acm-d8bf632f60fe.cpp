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