#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct SuffixAutomaton {
    struct State { array<int, 26> next{}; int link = -1, length = 0; };
    vector<State> states{State{}};
    int last = 0;
    void extend(char ch) {
        int c = ch - 'a';
        int current = (int)states.size(); states.push_back(State{});
        states[current].length = states[last].length + 1;
        int p = last;
        while (p != -1 && !states[p].next[c]) {
            states[p].next[c] = current; p = states[p].link;
        }
        if (p == -1) states[current].link = 0;
        else {
            int q = states[p].next[c];
            if (states[p].length + 1 == states[q].length) states[current].link = q;
            else {
                int clone = (int)states.size(); states.push_back(states[q]);
                states[clone].length = states[p].length + 1;
                while (p != -1 && states[p].next[c] == q) {
                    states[p].next[c] = clone; p = states[p].link;
                }
                states[q].link = states[current].link = clone;
            }
        }
        last = current;
    }
    i64 distinctSubstrings() const {
        i64 answer = 0;
        for (int i = 1; i < (int)states.size(); ++i)
            answer += states[i].length - states[states[i].link].length;
        return answer;
    }
};
