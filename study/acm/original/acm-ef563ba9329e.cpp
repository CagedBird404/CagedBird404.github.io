#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;


struct node
{
    int a;
    node* next;
};

void solve()
{
    node* f = new node; // 开头
    f -> next = NULL;
    node* e = f; // 结尾
    int x;
    while(cin >> x)
    {
        if(x == 0) break;
        node* k = new node;
        k -> next = NULL;
        k -> a = x;
        e -> next = k;
        e = k;
    }
    node* p = f -> next;
    while(p != NULL)
    {
        cout << p -> a << " ";
        p = p-> next;
    }
}

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);                
    cout << setiosflags(ios::fixed) << setprecision(2); 
    int TT = 1;
    cin >> TT; 
    while (TT--)
    {
        solve(); 
        cout << endl;
    }
}