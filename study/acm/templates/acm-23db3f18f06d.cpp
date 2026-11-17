#include <bits/stdc++.h>
using namespace std;
void mergeSort(vector<long long>& a) {
    vector<long long> buffer(a.size());
    function<void(int,int)> sortRange = [&](int l,int r) {
        if (r-l <= 1) return;
        int mid=l+(r-l)/2;
        sortRange(l,mid);sortRange(mid,r);
        int i=l,j=mid,k=l;
        while(i<mid && j<r) buffer[k++]=a[i]<=a[j]?a[i++]:a[j++];
        while(i<mid) buffer[k++]=a[i++];
        while(j<r) buffer[k++]=a[j++];
        copy(buffer.begin()+l,buffer.begin()+r,a.begin()+l);
    };
    sortRange(0,(int)a.size());
}
// O(n log n) 时间，O(n) 额外空间。
