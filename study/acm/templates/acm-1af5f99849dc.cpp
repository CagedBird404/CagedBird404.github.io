#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    list<int> values{1, 2, 3};
    values.push_front(0); values.push_back(4);
    auto it = next(values.begin(), 2);
    values.insert(it, 99);
    it = values.erase(it);  // 接收下一个有效位置。
    list<int> extra{6, 7};
    values.splice(it, extra);
    values.sort(); values.unique();
    for (int x : values) cout << x << ' ';
    cout << '\n';
}
