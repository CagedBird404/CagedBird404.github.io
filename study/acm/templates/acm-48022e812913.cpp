#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 hamiltonPath(const vector<vector<i64>>& w) {
    int n = (int)w.size();
    if (n == 0) return 0;
    const i64 INF = (1LL << 60);
    vector<vector<i64>> dp(1 << n, vector<i64>(n, INF));
    dp[1][0] = 0;
    for (int mask = 1; mask < (1 << n); ++mask)
        for (int u = 0; u < n; ++u) if (dp[mask][u] != INF)
            for (int v = 0; v < n; ++v) if (!(mask >> v & 1))
                dp[mask | (1 << v)][v] = min(dp[mask | (1 << v)][v], dp[mask][u] + w[u][v]);
    return *min_element(dp.back().begin(), dp.back().end());
}
