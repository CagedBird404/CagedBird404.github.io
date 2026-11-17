#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

pair<i64, i64> fibonacciPair(i64 n, i64 mod) {
    if (n == 0) return {0, 1 % mod};
    auto [a, b] = fibonacciPair(n / 2, mod);
    i64 c = a * ((2 * b - a + mod) % mod) % mod;
    i64 d = (a * a + b * b) % mod;
    return (n & 1) ? make_pair(d, (c + d) % mod) : make_pair(c, d);
}
