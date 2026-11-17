#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// items 中每一项为 {体积, 价值}；体积必须为正。
i64 knapsack01(int capacity, const vector<pair<int, i64>>& items) {
    vector<i64> dp(capacity + 1, 0);
    for (auto [cost, value] : items) {
        for (int j = capacity; j >= cost; --j) {
            dp[j] = max(dp[j], dp[j - cost] + value);
        }
    }
    return dp[capacity];
}
