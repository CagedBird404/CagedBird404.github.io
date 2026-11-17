#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    pair<int, int> point{1, 2};
    cout << point.first << ' ' << point.second << '\n';
    map<int, int> mapping{{1, 9}, {2, 3}};
    vector<pair<int, int>> values(mapping.begin(), mapping.end());
    sort(values.begin(), values.end(), [](const auto& a, const auto& b) {
        return tie(a.second, a.first) < tie(b.second, b.first);
    });
    for (auto [key, value] : values) cout << key << ' ' << value << '\n';
}
