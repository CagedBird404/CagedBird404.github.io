/*
KMP解决的是s1字符串是否包含s2，如果包含返回s1包含s2的最左开头位置，不包含返回-1
暴力的话肯定是O(n*m) KMP是O(m + n)

next数组的含义：
    对于s2求，不包含当前位置，他的前缀和后缀最大匹配长度（不能包含整体）
        a a b a a b s a a b a a a 无
next:  -1 0 1 0 1 2 3 0 1 2 3 4 5 2 

简单来说，不匹配就跳回去，next数组就是将暴力的查询的每次建立了联系
建立next数组也一样，前两个能确定是 -1 和 0 后面就是看当前和前面前缀延伸的下一个字符是否匹配
如果是就加上1，不是就跳回再前面的前缀延伸，继续查看是否匹配

通过迭代+回溯的方式，高效算出next数组的每个值，核心是利用已有的前缀信息快速定位最长匹配，
避免重复比较。
复杂度O n+m
*/
// KMP算法优化模板
// 1. 该模板实现了KMP算法，计算了模式串的部分匹配表（next数组）。
// 2. 使用了std::vector来存储next数组，避免了数组越界的风险。
// 3. `solve()` 函数可以根据需要填充具体的字符串匹配逻辑。
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

void solve()
{
    string s1,s2;
    cin >> s1 >> s2;
    int n = s1.size(),m = s2.size();
    vector<int> next(m);
    int j = 0;
    for(int i = 1;i < m;i++)
    {
        while(j && s2[i] != s2[j])
        j = next[j-1];
        if(s2[i] == s2[j]) j++;
        next[i] = j;
    }
/*
对于KMP还有一种用法，每一位的p = i - next[i],如果i % p == 0 那么这就是最小的长度对于的s，若干个s可以拼接成
前面的字符串，而p就是最小单元长度
*/
    j = 0;
    for(int i = 0;i < n;i++)
    {
        while(j && (j == m || s1[i] != s2[j]))
        j = next[j-1];
        if(s1[i] == s2[j]) j++;
        if(j == m) 
        cout << i - m + 1  << endl;
    }
    for(int i = 0;i < m;i++)
    {
        cout << next[i] << " ";
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
        //cout << endl;
    }
}