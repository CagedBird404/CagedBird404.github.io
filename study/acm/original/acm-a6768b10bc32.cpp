/*
1代表障碍
0代表通路
2代表终点
3代表起点
dfs不能告诉你最小的长度，但是一定可以到达终点
*/
/*
他可以找所有路径，那就代表他的效率不高，在找最优这一条件上，不如bfs，但是可以记载数量
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

int ans,n,m;
vector<vector<int>> visited;
int moved[5]={-1,0,1,0,-1};
void mg(int x,int y,int num,vector<vector<int>> &a)
{
    for(int i=0;i<4;i++)
    {
        int nx=x+moved[i];
        int ny=y+moved[i+1];
        if(nx>=1 && nx<=n && ny>=1 && ny<=m)
        {
            if(a[nx][ny]==2)
            {
                ans = min(ans,num+1);
            }
            else if(a[nx][ny]==0 && !visited[nx][ny])
            {
                visited[nx][ny]=1;
                mg(nx,ny,num+1,a);
                visited[nx][ny]=0;

            }
        }
    }
    return;
}
void solve()
{
    ans = LLONG_MAX;
    cin >> n >> m;
    int x,y;
    
    vector<vector<int>> a(n+1,vector<int>(m+1));
    visited = a;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> a[i][j];
            if(a[i][j]==3)
            {
                x=i;
                y=j;
            }
            if(a[i][j]==2 || a[i][j]==1)
            {
                visited[i][j]=1;
            }
        }
    }
    mg(x,y,0,a);
    if(ans != LLONG_MAX)cout << ans << endl;
    else cout<<"-1"<<endl;
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