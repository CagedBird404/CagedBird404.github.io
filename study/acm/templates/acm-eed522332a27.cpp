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