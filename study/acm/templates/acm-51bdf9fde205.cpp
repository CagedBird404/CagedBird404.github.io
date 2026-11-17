#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct Lucas {
    int p;
    vector<i64> fact, inverseFact;
    i64 power(i64 a, i64 e) const {
        i64 result = 1;
        while (e) {
            if (e & 1) result = result * a % p;
            a = a * a % p; e >>= 1;
        }
        return result;
    }
    explicit Lucas(int prime) : p(prime), fact(p, 1), inverseFact(p, 1) {
        for (int i = 1; i < p; ++i) fact[i] = fact[i - 1] * i % p;
        inverseFact[p - 1] = power(fact[p - 1], p - 2);
        for (int i = p - 1; i >= 1; --i) inverseFact[i - 1] = inverseFact[i] * i % p;
    }
    i64 small(int n, int m) const {
        if (m > n) return 0;
        return fact[n] * inverseFact[m] % p * inverseFact[n - m] % p;
    }
    i64 choose(i64 n, i64 m) const {
        if (m < 0 || n < m) return 0;
        i64 result = 1;
        while (n || m) {
            result = result * small(n % p, m % p) % p;
            n /= p; m /= p;
        }
        return result;
    }
};
