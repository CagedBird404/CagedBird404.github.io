#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    deque<int> values(3, 7);
    values.push_back(9);
    values.push_front(1);
    cout << values.front() << ' ' << values.back() << '\n';
    values.pop_front(); values.pop_back();
    values.insert(values.begin() + 1, 5);
    values.erase(values.begin());
    cout << values.at(0) << '\n';
}
