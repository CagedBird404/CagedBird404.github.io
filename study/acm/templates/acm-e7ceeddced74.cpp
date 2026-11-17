#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 eulerPhi(i64 n) {
    i64 result = n;
    for (i64 p = 2; p <= n / p; ++p) if (n % p == 0) {
        result = result / p * (p - 1);
        while (n % p == 0) n /= p;
    }
    if (n > 1) result = result / n * (n - 1);
    return result;
}
i64 eulerPower(i64 a, const string& exponent, i64 mod) {
    if (mod == 1) return 0;
    if (gcd(a, mod) != 1) throw invalid_argument("base and modulus must be coprime");
    i64 cycle = eulerPhi(mod), e = 0;
    for (char ch : exponent) e = (e * 10 + ch - '0') % cycle;
    a %= mod; if (a < 0) a += mod;
    i64 result = 1;
    while (e) {
        if (e & 1) result = result * a % mod;
        a = a * a % mod; e >>= 1;
    }
    return result;
}
