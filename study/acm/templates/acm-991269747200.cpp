#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

bool isPrime(i64 n) {
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;
    for (i64 d = 3; d <= n / d; d += 2) if (n % d == 0) return false;
    return true;
}
