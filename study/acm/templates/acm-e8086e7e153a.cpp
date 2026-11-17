#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

vector<int> prefixFunction(const string& pattern) {
    vector<int> pi(pattern.size());
    for (int i = 1; i < (int)pattern.size(); ++i) {
        int j = pi[i - 1];
        while (j && pattern[i] != pattern[j]) j = pi[j - 1];
        if (pattern[i] == pattern[j]) ++j;
        pi[i] = j;
    }
    return pi;
}
vector<int> kmpMatches(const string& text, const string& pattern) {
    vector<int> result;
    if (pattern.empty()) {
        for (int i = 0; i <= (int)text.size(); ++i) result.push_back(i);
        return result;
    }
    auto pi = prefixFunction(pattern);
    int j = 0;
    for (int i = 0; i < (int)text.size(); ++i) {
        while (j && text[i] != pattern[j]) j = pi[j - 1];
        if (text[i] == pattern[j]) ++j;
        if (j == (int)pattern.size()) {
            result.push_back(i - j + 1); j = pi[j - 1];
        }
    }
    return result;
}
