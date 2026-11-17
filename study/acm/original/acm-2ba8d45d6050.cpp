pair<long long, long long> fib_fast(long long n) {
    if (n == 0) return {0, 1};  // 基线条件：F(0)=0，F(1)=1
    auto [a, b] = fib_fast(n >> 1);  // 递归计算 k = n//2，得到 {F(k), F(k+1)}
    long long c = a * (2*b - a);     // 恒等式：F(2k) = F(k) * (2*F(k+1) - F(k))
    long long d = a*a + b*b;         // 恒等式：F(2k+1) = F(k)^2 + F(k+1)^2
    if ((n & 1) == 0) return {c, d}; // n为偶数时，n=2k → 返回 {F(2k), F(2k+1)}
    else return {d, c + d};          // n为奇数时，n=2k+1 → 返回 {F(2k+1), F(2k+2)}（因F(2k+2)=F(2k+1)+F(2k)）
}