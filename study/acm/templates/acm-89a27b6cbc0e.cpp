#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

using Matrix = vector<vector<i64>>;
Matrix multiply(const Matrix& a, const Matrix& b, i64 mod) {
    int n = (int)a.size();
    Matrix c(n, vector<i64>(n));
    for (int i = 0; i < n; ++i)
        for (int k = 0; k < n; ++k)
            for (int j = 0; j < n; ++j)
                c[i][j] = (c[i][j] + (__int128)a[i][k] * b[k][j]) % mod;
    return c;
}
Matrix matrixPow(Matrix a, i64 e, i64 mod) {
    int n = (int)a.size();
    Matrix result(n, vector<i64>(n));
    for (int i = 0; i < n; ++i) result[i][i] = 1 % mod;
    for (auto& row : a) for (i64& x : row) x = (x % mod + mod) % mod;
    while (e) {
        if (e & 1) result = multiply(result, a, mod);
        a = multiply(a, a, mod); e >>= 1;
    }
    return result;
}
