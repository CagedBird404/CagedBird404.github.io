#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int lisLength(const vector<i64>& a) {
    vector<i64> tails;
    for (i64 x : a) {
        auto it = lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) tails.push_back(x);
        else *it = x;
    }
    return (int)tails.size();
}
int ldsLength(vector<i64> a) {
    // 使用降序比较器，避免对 LLONG_MIN 取负溢出。
    vector<i64> tails;
    for (i64 x : a) {
        auto it = lower_bound(tails.begin(), tails.end(), x, greater<i64>());
        if (it == tails.end()) tails.push_back(x); else *it = x;
    }
    return (int)tails.size();
}
