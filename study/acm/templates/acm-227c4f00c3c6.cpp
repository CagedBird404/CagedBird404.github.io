#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct SparseTable {
    vector<int> logarithm;
    vector<vector<i64>> table;
    explicit SparseTable(const vector<i64>& a) {
        int n = (int)a.size(); logarithm.resize(n + 1);
        for (int i = 2; i <= n; ++i) logarithm[i] = logarithm[i / 2] + 1;
        table.assign(n ? logarithm[n] + 1 : 0, vector<i64>(n));
        if (!n) return;
        table[0] = a;
        for (int k = 1; k < (int)table.size(); ++k)
            for (int i = 0; i + (1 << k) <= n; ++i)
                table[k][i] = max(table[k - 1][i], table[k - 1][i + (1 << (k - 1))]);
    }
    i64 query(int l, int r) const {
        int k = logarithm[r - l + 1];
        return max(table[k][l], table[k][r - (1 << k) + 1]);
    }
};
