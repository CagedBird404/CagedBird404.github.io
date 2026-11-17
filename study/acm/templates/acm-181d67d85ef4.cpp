#include <bits/stdc++.h>
using namespace std;
// g 使用 1..n 编号，必须是连通树；路径端点也在 1..n。
// O((n+q)log n) 时间，O(n log n) 空间。
vector<long long> pathCounts(const vector<vector<int>>& g,
                            const vector<pair<int,int>>& paths) {
    int n=(int)g.size()-1,LOG=1;
    while((1LL<<LOG)<=n) ++LOG;
    vector<vector<int>> up(LOG,vector<int>(n+1));
    vector<int> depth(n+1),order{1};
    for(int i=0;i<(int)order.size();++i) {
        int u=order[i];
        for(int v:g[u]) if(v!=up[0][u]) {
            up[0][v]=u;depth[v]=depth[u]+1;order.push_back(v);
        }
    }
    for(int k=1;k<LOG;++k) for(int u=1;u<=n;++u)
        up[k][u]=up[k-1][up[k-1][u]];
    auto lca=[&](int u,int v) {
        if(depth[u]<depth[v]) swap(u,v);
        int d=depth[u]-depth[v];
        for(int k=0;k<LOG;++k) if(d>>k&1) u=up[k][u];
        if(u==v) return u;
        for(int k=LOG-1;k>=0;--k) if(up[k][u]!=up[k][v]) {
            u=up[k][u];v=up[k][v];
        }
        return up[0][u];
    };
    vector<long long> difference(n+1);
    for(auto [u,v]:paths) {
        int p=lca(u,v);
        ++difference[u];++difference[v];
        --difference[p];--difference[up[0][p]];
    }
    for(int i=n-1;i>0;--i)
        difference[up[0][order[i]]]+=difference[order[i]];
    difference[0]=0;
    return difference;
}
