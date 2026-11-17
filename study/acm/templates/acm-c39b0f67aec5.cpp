#include <bits/stdc++.h>
using namespace std;
int binarySearch(const vector<long long>& a, long long x) {
    int l = 0, r = (int)a.size();
    while (l < r) {
        int mid = l + (r-l)/2;
        if (a[mid] < x) l = mid+1; else r = mid;
    }
    return l < (int)a.size() && a[l] == x ? l : -1;
}
// O(log n) 时间，O(1) 额外空间。
