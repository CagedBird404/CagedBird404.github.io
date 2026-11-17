/*
二叉树是一种树形结构
他的子节点最多只能有两个
最开始的节点叫做根节点

满二叉树：每个节点要么有两个节点，要么没有节点
完全二叉树：除了最后一层，其他全为满节点，最后一层节点是从左到右连续的
二叉搜索树：每个左节点小于根节点，右节点大于根节点
平衡二叉树：左右节点的高度差不超过1

对于遍历顺序：
前序遍历：根->左->右
中序遍历：左->根->右
后序遍历：左->右->根
*/

#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

void solve()
{
    
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