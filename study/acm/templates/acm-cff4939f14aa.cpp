#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

string binaryDigits(unsigned long long x, int bits) {
    string result;
    for (int i = bits - 1; i >= 0; --i) result += char('0' + ((x >> i) & 1ULL));
    return result;
}
