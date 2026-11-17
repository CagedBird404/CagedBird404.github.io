#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 countWithout4(i64 n) {
    if (n < 0) return 0;
    string digits = to_string(n);
    vector<i64> memo(digits.size(), -1);
    function<i64(int, bool)> dfs = [&](int pos, bool tight) -> i64 {
        if (pos == (int)digits.size()) return 1;
        if (!tight && memo[pos] != -1) return memo[pos];
        int limit = tight ? digits[pos] - '0' : 9;
        i64 ans = 0;
        for (int d = 0; d <= limit; ++d) {
            if (d == 4) continue;
            ans += dfs(pos + 1, tight && d == limit);
        }
        if (!tight) memo[pos] = ans;
        return ans;
    };
    return dfs(0, true);
}
i64 countRangeWithout4(i64 l, i64 r) {
    return countWithout4(r) - (l <= 0 ? 0 : countWithout4(l - 1));
}
