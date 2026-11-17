//ST表通常采取预处理的方案存储不同长度的区间答案
//所有在查询时很方便
//一般用于解决区间最值，可重复贡献
/*
ST表通常需要注意
1.静态区间查询
2.运算满足结合律和幂等律
3.常见元素：
    区间最大最小
    区间GCD
    区间按位与，按位或
*/
//基本思路：倍增法
/*
预处理二维数组st[i][j]代表从i开始，长度为2……j的区间答案
状态转移方程：  st[i][j]=f(s[i][j-1],st[i+(2^(j-1))][j-1])
即为将长度为2^j的区间拆解成两个2^(j-1)
*/
//对于[L,R]
//令k=floor(log_2(R-L+1))
//ans = f(st[l][k],st[r-(1 << k)+1][k])


//这是最大值的
struct ST
{
    int maxn;
    vector<int> logtab;
    vector<vector<int>> st;
    ST(int maxk)
    {
        maxn = maxk;
    }
    void pre(const vector<int> &a)
    {
        // 预处理log表
        logtab.resize(maxn + 1);
        int K = __lg(maxn) + 1;
        st = vector<vector<int>>(maxn, vector<int>(K));
        logtab[1] = 0;
        for (int i = 2; i <= maxn; i++) {
            logtab[i] = logtab[i / 2] + 1;
        }
        // 预处理st表
        // 初始化
        for (int i = 0; i < maxn; i++) {
            st[i][0] = a[i];
        }
        // pre
        for (int j = 1; (1 << j) <= maxn; j++) {
            for (int i = 0; i + (1 << j) <= maxn; i++) {
                st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    int get(int l, int r)
    {
        int k = logtab[r - l + 1];
        return max(st[l][k], st[r - (1 << k) + 1][k]);
    }
};