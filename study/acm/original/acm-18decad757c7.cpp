/*
强连通：若一张有向图的节点两两互达，则称这张图是强连通
强连通分量：极大的强连通子图，联通的一堆点可以互相到达

对图深搜时，每一个节点访问一次，被访问过的节点与边构成搜索树

树边：访问节点走过的边
返祖边：指向祖先节点的边
横叉边：右子树指向左子树的边
前向边：指向子树中节点的边

返祖边和树边必构成环，横叉边可能与树边构成环

如果节点x是某个强联通分量在搜索树上中遇到的第一个节点
那么这个强联通分量的其余节点肯定是在搜索树在，以x为根的子树中，节点x被称为这个强联通分量的根

*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

int dfn[N]; //节点第一次被访问的顺序
int low[N]; //从节点x出发，所能访问到的最早时间戳
int tot;
int stk[N], instk[N], top;
int scc[N], siz[N], cnt;
void solve()
{
    
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