// #pragma GCC optimize(2)
#include <bits/stdc++.h> // 万能头
using namespace std;
#define int long long                 // 这样不用打long long了 用int 代替long long
#define endl '\n'                     // '\n' 比 endl 快 将endl 定义为 \n
#define all(x) (x).begin(), (x).end() // sort(all(x)) 比较方便,比如sort(all(v))

constexpr int MOD = 1e9 + 7;
// -9.2e18 ~ 9.2e18
//算法中常用模数，注意同余原理，加减法，组成数的余数相同

void solve()
{
}
//将每组测试用例的处理逻辑写在里面

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);                // 解绑iostream和stdio 让运行速度变快 感兴趣可以ai搜
    cout << setiosflags(ios::fixed) << setprecision(2);// 控制小数输出位数是2 那个数字可以根据需求改
    cout << setiosflags(ios::fixed) << setprecision(2);
    int TT = 1;
    cin >> TT; // 有的要求输入多组测试用例
    while (TT--)
    {
        solve(); // 这里面写每一组的代码
        cout << endl;
    }
}
