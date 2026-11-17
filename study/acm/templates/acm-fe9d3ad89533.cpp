#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 phi(i64 n) {
    i64 answer = n;
    for (i64 p = 2; p <= n / p; ++p) if (n % p == 0) {
        answer = answer / p * (p - 1);
        while (n % p == 0) n /= p;
    }
    if (n > 1) answer = answer / n * (n - 1);
    return answer;
}
