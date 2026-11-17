/*
图游戏概念
任何局面都认为是图中的点，每一个局面都可以通过一种行动，走向图中的另一个点
如果当前行动有若干个，那么后继节点就有若干个。最终，必败局面的点认为没有后继节点
每个公平游戏都可以对应一张图

我们规定必败点是A，那么sg(A) = 0
假设状态点是B，那么sg(B) = 查看B所有后继节点的sg值，其中没有出现过的最小自然数
如果sg(B) != 0，那么状态B为必胜态， = 0 则为必败态

sg定理，如果一个ICG游戏(总)，由若干个独立的ICG子游戏构成，那么：
sg(总) = sg(分1) ^ sg(分2) ^ sg(分3)......
*/

//我其实更倾向于把他归于一类思想，主要也是打表记忆化的手段
//下面是P8369

#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;
vector<int> sg(1001);
vector<int> vi(1001);
int a,b,c;

int cc(int x)
{
    if(x < min({a,b,c})) return 0;
    if(vi[x]) return sg[x];
    vi[x] = 1;
    set<int> S;
    
    for(int i = 0;i <= x;i++)
    {
        int o = 0;
        if(i <= x - a) S.insert(cc(i) ^ cc(x - i - a));
        if(i <= x - b) S.insert(cc(i) ^ cc(x - i - b));
        if(i <= x - c) S.insert(cc(i) ^ cc(x - i - c));
    }
    int k = 0;
    while(S.count(k)) k++;
    return sg[x] = k;
}

void solve()
{
    cin >> a >> b >> c;
    int q;
    cin >> q;
    while(q--)
    {
        int x;
        cin >> x;
        cout << (!cc(x) ? 2 : 1) << endl;
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