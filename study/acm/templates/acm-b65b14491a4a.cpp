#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 unboundedKnapsack(int capacity, const vector<pair<int, i64>>& items) {
    vector<i64> dp(capacity + 1);
    for (auto [cost, value] : items)
        for (int j = cost; j <= capacity; ++j)
            dp[j] = max(dp[j], dp[j - cost] + value);
    return dp[capacity];
}
