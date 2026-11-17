#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 exgcd(i64 a, i64 b, i64& x, i64& y) {
    if (b == 0) { x = 1; y = 0; return a; }
    i64 x1, y1;
    i64 g = exgcd(b, a % b, x1, y1);
    x = y1; y = x1 - (a / b) * y1;
    return g;
}
bool linearEquation(i64 a, i64 b, i64 c, i64& x, i64& y) {
    if (a == 0 && b == 0) { x = y = 0; return c == 0; }
    i64 g = exgcd(abs(a), abs(b), x, y);
    if (c % g) return false;
    x *= c / g; y *= c / g;
    if (a < 0) x = -x;
    if (b < 0) y = -y;
    return true;
}
