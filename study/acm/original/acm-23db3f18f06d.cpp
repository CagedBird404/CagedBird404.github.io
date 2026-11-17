/*
时间复杂度nlogn;

总的来说就是让左面排好序右面排好序，在归到一起

先将他归并到最小，再两两合并，其中每个数都不会重复计算
因为你从虽小上来的，所以进行操作的每两个都是有序的、
就可以用双指针进行排序，排序后再覆盖到原数组对应的位置上

也正是因为是将其分成多个区间计算，所以在进行逆序对计算时就不会往后找
而且分的精细，所以也不会缺失
*/

#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

vector<int> a, b;

void gb(int l, int r)
{
    if(l == r) return;
    int mid = l + (r - l) / 2;
    gb(l, mid);
    gb(mid + 1, r);
    int i = l;
    int j = mid + 1;
    int t = l;
    while(i <= mid && j <= r)
    {
        if(a[i] < a[j])
        {
            b[t++] = a[i];
            i++;
        }
        else{
            b[t++] = a[j];
            j++;
        }
    }
    while(i <= mid) b[t++] = a[i++];
    while(j <= r) b[t++] = a[j++];
    for(int k = l; k <= r; k++) a[k] = b[k];
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            for(int i = 0;i )
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