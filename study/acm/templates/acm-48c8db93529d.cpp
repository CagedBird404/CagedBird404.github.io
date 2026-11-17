#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 modPow(i64 a, i64 e, i64 mod) {
    if (mod <= 0 || e < 0) throw invalid_argument("invalid modulus or exponent");
    a %= mod;
    if (a < 0) a += mod;
    i64 result = 1 % mod;
    while (e) {
        if (e & 1) result = (__int128)result * a % mod;
        a = (__int128)a * a % mod;
        e >>= 1;
    }
    return result;
}
