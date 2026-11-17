#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size(), m = s2.size();
    vector<int> next(26, -1);
    // 记录模式串中字符最后出现的位置
    for (int i = 0; i < m; i++)
    {
        next[s2[i] - 'a'] = i;
    }
    int now = 0;
    while (now <= n - m)
    {
        int ok = 1;
        // 当前窗口匹配
        for (int i = 0; i < m; i++)
        {
            if (s1[now + i] != s2[i])
            {
                ok = 0;
                break;
            }
        }

        if (ok)
        {
            cout << now << endl;
        }
        if (now + m >= n)
            break;
        char c = s1[now + m];
        if (next[c - 'a'] == -1)
        {
            now += m + 1;
        }
        else
        {
            now += m - next[c - 'a'];
        }
    }

    return 0;
}