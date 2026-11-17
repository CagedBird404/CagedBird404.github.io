#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    map<string, int> frequency;
    vector<string> words{"app", "app", "vcr"};
    for (const string& word : words) ++frequency[word];
    if (frequency.find("app") != frequency.end()) cout << frequency.at("app") << '\n';
    for (const auto& [word, count] : frequency) cout << word << ' ' << count << '\n';
}
