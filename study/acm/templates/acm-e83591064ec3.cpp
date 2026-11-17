#include<bits/stdc++.h>
using namespace std;
int main()
{
    unordered_set<int> s;
    /*
    他和set底层不同，set升序排列，去重，底层是红黑树，查找复杂度为logn
    unordered_set，无序，去重，底层是哈希表，查找平均复杂度是 O(1)，最坏为 O(n)
    */
   s.insert(2);
   s.insert(5);
   cout << s.count(2) << endl;
   if(s.find(5) != s.end()) cout << 5 << endl;
}