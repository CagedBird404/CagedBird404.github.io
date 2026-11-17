#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

vector<i64> inverses(int n, i64 p) {
    vector<i64> inv(n + 1);
    if (n >= 1) inv[1] = 1;
    for (int i = 2; i <= n; ++i)
        inv[i] = p - (__int128)(p / i) * inv[p % i] % p;
    return inv;
}
