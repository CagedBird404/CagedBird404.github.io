#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 groupedKnapsack(int capacity, const vector<vector<pair<int, i64>>>& groups) {
    vector<i64> dp(capacity + 1);
    for (const auto& group : groups) {
        auto next = dp;  // 不选当前组。
        for (auto [cost, value] : group)
            for (int j = cost; j <= capacity; ++j)
                next[j] = max(next[j], dp[j - cost] + value);
        dp.swap(next);
    }
    return dp[capacity];
}
