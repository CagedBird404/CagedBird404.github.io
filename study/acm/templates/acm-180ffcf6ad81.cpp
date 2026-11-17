#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    stack<double> values;
    values.push(1.0); values.push(1.4);
    while (!values.empty()) {
        cout << values.top() << '\n'; values.pop();
    }
}
