/*
二进制掩码枚举法
二进制掩码枚举是一种通过二进制数的位状态来表示 “选取 / 不选取” 的暴力枚举方法，
核心是用二进制数的每一位对应原始序列中元素的选取状态。

假设原始序列有n个元素（字符串，数组），我们需要枚举所有可能的子序列（包含空序列）
用一个 n 位的二进制数（称为“掩码”，mask）表示选举规则：
* 掩码的第i位为1  就选第i个元素，加入子序列

范围限制
时间复杂度 O(n * 2^n)
空间复杂度O(n)
一般可使用范围为 n <= 20
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
    string s;
    cin >> s;
    int ok=0;
    for(int i=0;i < (1 << n);i++)  // 最大范围是2^n
    {
        string m1,m2;
        vector<int> a;
        for(int j=0;j<n;j++)
        {
            if(i & (1 << j))
            {
                m1 += s[j];
                a.push_back(j+1);
            }
            else{
                m2 += s[j];
            }
        }
        int ok1=1;         // 后面是检测规则
        for(int i=1;i<m1.size();i++)
        {
            if(m1[i] < m1[i-1])
            {
                ok1=0;
                break;
            }
        }
        if(!ok1) continue;
        if(m2 == string(m2.rbegin(),m2.rend()))
        {
            cout<<a.size()<<endl;
            for(int i=0;i<a.size();i++)
            {
                cout<<a[i]<<" ";
            }
            ok=1;
            break;
        }
    }
    if(!ok)
    {
        cout<<"-1";
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);                
    cout << setiosflags(ios::fixed) << setprecision(2); 
    int TT = 1;
    cin >> TT; 
    while (TT--)
    {
        solve(); 
        cout << endl;
    }
}