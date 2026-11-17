#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

using u64 = unsigned long long;
u64 mulMod(u64 a, u64 b, u64 mod) { return (__uint128_t)a * b % mod; }
u64 powerMod(u64 a, u64 e, u64 mod) {
    u64 answer = 1;
    for (; e; e >>= 1, a = mulMod(a, a, mod)) if (e & 1) answer = mulMod(answer, a, mod);
    return answer;
}
bool millerRabin(u64 n) {
    if (n < 2) return false;
    for (u64 p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n % p == 0) return n == p;
    }
    u64 d = n - 1; int s = 0;
    while (!(d & 1)) { d >>= 1; ++s; }
    for (u64 a : {2ULL, 325ULL, 9375ULL, 28178ULL, 450775ULL, 9780504ULL, 1795265022ULL}) {
        if (a % n == 0) continue;
        u64 x = powerMod(a % n, d, n);
        if (x == 1 || x == n - 1) continue;
        bool witness = true;
        for (int r = 1; r < s; ++r) { x = mulMod(x, x, n); if (x == n - 1) { witness = false; break; } }
        if (witness) return false;
    }
    return true;
}
