#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

vector<i64> primeFactors(i64 n) {
    vector<i64> factors;
    for (i64 d = 2; d <= n / d; ++d) {
        if (n % d != 0) continue;
        factors.push_back(d);
        while (n % d == 0) n /= d;
    }
    if (n > 1) factors.push_back(n);
    return factors;
}
