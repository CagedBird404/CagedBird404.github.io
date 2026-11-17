/*
p是模数
*/

vector<int> inv(n + 1);
for(int i = 2;i <= n;i++)
{
    inv[i] = p - (p / i * inv[p % i] % p) % p;
}
