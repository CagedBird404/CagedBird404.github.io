/*
这是我刚学算法时，学到递归，
突发奇想写的废物线段树
并无用处，留作纪念
*/

/*
线段树
首先需要建树
需要想好每个节点所需要的信息
和分治一样，先想好分的过程，再想如何合
建立树的过程为 自低向上分治计算合并    时间复杂度O(n)
查询的过程为   自项先向下分治查找合并  时间复杂度O(log(n))
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

constexpr int MOD = 1e9 + 7;

struct Node // 先建立节点，节点中的元素都和规则有关
{
    int sum;  // 区间总和
    int qmax; // 最大前缀和
    int hmax; // 最大后缀和
    int Max;  // 最大子区间和
};

vector<int> a;    // 原数组
vector<Node> seg; // 线段树

Node merge(Node L, Node R) // 合并两个分支,merge一般代表合并区间的意思
{                          // 要找出合并原则
    if (L.sum == LLONG_MIN / 2)
        return R;
    if (R.sum == LLONG_MIN / 2)
        return L;
    Node b;
    b.sum = L.sum + R.sum;
    b.qmax = max(L.qmax, L.sum + R.qmax);
    b.hmax = max(R.hmax, L.hmax + R.sum);
    b.Max = max({L.Max, R.Max, L.hmax + R.qmax});
    return b;
}

Node build(int idx, int l, int r) // 建立树，idx代表序号
{                                 // 建树就是把分支已经细化成单个元素了，再返回节点里的元素
    if (l == r)
    {
        int val = a[l];
        return seg[idx] = {val, val, val, val};
    }
    int mid = l + (r - l) / 2;
    Node L = build(idx * 2, l, mid);         // 代表向下分支的左边
    Node R = build(idx * 2 + 1, mid + 1, r); // 代表向下分支的右边
    return seg[idx] = merge(L, R);
}

void update(int idx, int l, int r, int pos, int val) // 将第pas个数修改成val，再恢复树
{
    if (l == r)
    {
        seg[idx] = {val, val, val, val};
        return;
    }
    int mid = l + (r - l) / 2;
    if (pos > mid)
        update(idx * 2 + 1, mid + 1, r, pos, val);
    else
        update(idx * 2, l, mid, pos, val);
    seg[idx] = merge(seg[idx * 2], seg[idx * 2 + 1]); // 修复
}

Node tree(int idx, int l, int r, int ql, int qr)
{
    if (l > qr || r < ql) // 不在范围内
    {
        return {LLONG_MIN / 2, LLONG_MIN / 2, LLONG_MIN / 2, LLONG_MIN / 2};
    }
    if (l >= ql && r <= qr)
    {
        return seg[idx];
    }
    int mid = l + (r - l) / 2;
    Node L = tree(idx * 2, l, mid, ql, qr);
    Node R = tree(idx * 2 + 1, mid + 1, r, ql, qr);
    return merge(L, R);
}
void solve()
{

    int n;
    cin >> n;
    a.resize(n + 1);
    seg.resize(4 * n + 5);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        Node ans = tree(1, 1, n, l, r);
        cout << ans.Max << endl;
    }
}
// 将每组测试用例的处理逻辑写在里面

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int TT = 1;
    // cin >> TT;
    while (TT--)
    {
        solve();
        cout << endl;
    }
}