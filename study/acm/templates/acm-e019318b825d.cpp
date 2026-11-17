#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    vector<int> values{1, 2, 3};
    vector<vector<int>> matrix(5, vector<int>(6, 2));  // 5 行 6 列。
    values.push_back(4);
    values.resize(6, 3);
    int index = 1;
    // 不要求保序时，用末尾元素覆盖待删除位置。
    values[index] = values.back(); values.pop_back();
    for (int x : values) cout << x << ' ';
    cout << '\n';
}
