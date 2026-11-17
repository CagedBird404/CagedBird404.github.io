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