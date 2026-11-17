#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int floorLog2(unsigned long long x) {
    int answer = -1;
    while (x) { ++answer; x >>= 1; }
    return answer;
}
