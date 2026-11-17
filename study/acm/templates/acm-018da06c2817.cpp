#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

vector<i64> prefixSum(const vector<i64>& a) {
    vector<i64> prefix(a.size());
    for (int i = 1; i < (int)a.size(); ++i) prefix[i] = prefix[i - 1] + a[i];
    return prefix;
}
i64 rangeSum(const vector<i64>& prefix, int l, int r) { return prefix[r] - prefix[l - 1]; }
struct Difference {
    vector<i64> diff;
    explicit Difference(int n) : diff(n + 2) {}
    void add(int l, int r, i64 value) { diff[l] += value; diff[r + 1] -= value; }
    vector<i64> restore() const {
        int n = (int)diff.size() - 2;
        vector<i64> a(n + 1);
        for (int i = 1; i <= n; ++i) a[i] = a[i - 1] + diff[i];
        return a;
    }
};
