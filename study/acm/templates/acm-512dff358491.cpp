#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int lcsLength(const string& a, const string& b) {
    vector<int> dp(b.size() + 1);
    for (char x : a) {
        int diagonal = 0;
        for (int j = 1; j <= (int)b.size(); ++j) {
            int old = dp[j];
            if (x == b[j - 1]) dp[j] = diagonal + 1;
            else dp[j] = max(dp[j], dp[j - 1]);
            diagonal = old;
        }
    }
    return dp.back();
}
