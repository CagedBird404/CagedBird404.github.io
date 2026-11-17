#include <bits/stdc++.h>
using namespace std;
void hanoi(int n,char from,char auxiliary,char to) {
    if(n<=0) return;
    hanoi(n-1,from,to,auxiliary);
    cout << "move " << n << " from " << from << " to " << to << '\n';
    hanoi(n-1,auxiliary,from,to);
}
