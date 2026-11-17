---
title: "C++ 零散知识点"
published: 2026-11-16
category: ACM竞赛模板
tags: [学习笔记, C++]
description: "保留原意整理的学习笔记。"
draft: false
---

[返回分类目录](/posts/acm-index/) · [相关知识点](/posts/acm-keywords/)


> 整理修正：修正 getchar() 的括号、include 的 # 及加法恒等式括号。补充：位移的乘除类比限于适当类型、移位范围和无溢出的情况；ASCII 大小写相差 32 不适用于所有字符编码。原“结构体函数”示例仍是待修正草稿，不能直接编译；卡特兰数代码存在整数溢出上限。

# 有关字符
* getchar() 输入
* putchar(char) 输出
* toupper(char) 将字母转化成大写
```cpp
putchar(toupper(getchar()));  
```
* 数字转化字母
```cpp
for(int i=0;i<26;i++)
{
    cout<<(char)(i+'a')<<endl;
}
```
* 字母相减是数字
* 用char(字母-32)，也可以转换大小写，大写字母对应数字比小写小
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
char c;
cin>> c;
cout<< char(c-32)<<endl;
}
```
* string 中如果有数字。将其减48，或者-'0'，
就可以当做数字使用
```cpp
string a="938602";
int c=(a[2]-48) * (a[5]-'0');
cout<< c;
```
## 有关输入输出
```cpp
#include <cstdio> //头文件
... ...
scanf("输入控制符", 输入参数);
printf("输出控制符", 输出参数);
```
1、 %d:读入一个 32 位有符号整数。 （%1d代表读入的整数都是1位）
2、%u：读入一个 32 位无符号整数。
3、%lld：读入一个 64 位有符号整数。
4、%llu：读入一个 64 位无符号整数。
5、%f：读入一个 float 类型。
6、%lf：读入一个 double 类型。

>当然，如果输入中有多余的已知字符，可以在 scanf 中用该字符占位
>例如输入是 2021.805，使用如下代码读入,a,b 的值分别为 2021,805。
```cpp
scanf("%d.%d",&a,&b);
printf("%d.%d",b,a);
```

* isupper(char)等，可以作为判断条件，判断字符是否为这个类型，适配于string，可以遍历检验其种类
```cpp
while(isupper(char))   //大写字母
while(islower(char))   //小写字母
while(isdigit(char))   //数字
```

* 如果在cout里面要输出特殊符号，前面要加\
### 数学知识点
* 质因数分解定理：每个大于1的自然数要么是质数，要么能唯一分解为有限个质数乘积

* 费马大定理：当n>=3时，方程pow(a,n) + pow(b,n)=pow(m,n)没有正整数解

* 取模运算有结合律，而且10的k次方取模，会有循环
## 二进制
* 左移和右移
左移就是乘2，右移就是除2
比如3的二进制是11
左移就是110，就是6
右移就是01，就是1（向下取整了）
以下是表现形式
```cpp
int a=6;
int c=(a >>=1);   //1就代表移动位数
int b=(a <<=1);
```
* 二进制本质，最后一位是0，就是偶数，1是奇数

*  位运算操作符
1、 &    按位与运算
   规则：只有当两个对应位置都为1，结果才为1，否则为0
   用途：提取特定位，判断奇偶性
   以下是表达形式
```cpp
while(a & 1)    //检测a是否为单数
{
    a=a*3+1;
}
```

或者这样
```cpp
int x=0b1010;
int y=0b1100;
int z=x & y;   //1000,表示为8
```
2、 |
规则：两个对应位只要有1，结果位就为1
用途：设置特定位为1
以下为表现形式
```cpp
int x=0b1010;
int y=0b0101;
int z=x | y;    //0b1111（15）
```
3、 ^ 按位异或
规则：两个对应位不同时为 1，相同时为 0
用途：翻转特定位、交换两个数（无需临时变量）
运算法则：a^x = b 时，那么x 必须是 a^b 

4、 ~ 按位取反
规则：将所有位翻转（1 变 0，0 变 1）
注意：符号位也会被翻转（对有符号数可能导致负数）
```cpp
int x=0b1010;
int y=~x;
```

* 可以用 0b 前缀表示二进制数
例如
```cpp
int a=0b1010;   // 等价于10
int b=0b1100;   // 等价于15
```

* 公式 a + b = 2 * (a & b) + (a ^ b);
   这个恒等式可以帮助理解加法中的进位与不进位部分，实际代码还需要注意整数范围与溢出
   1、a & b是为了计算进位的，如果有两个1，就应该向上进位，那么就在当前位置保留一个1，然后通过 * 2，进行进位。
   2、a ^ b是为了计算不进位的，如果在同一位置上有一个0和一个1，那么就保留一个1
   3、最终将两部分结合到一起就可以得出解数

## 函数
* 结构体定义的函数，里面所包含的变量都可以直接当结构体形式使用
```cpp
struct a{
    int b;
    int c;
    int d;
};
a hanshu(int a,int b)
{
    int d=a.a + b.a;
}
```
# 卡特兰数（Catalan Number）详解

卡特兰数是组合数学中一个重要的数列，用于解决**有约束条件的计数问题**，其核心是将“大问题分解为独立子问题”的递归思想。


## 一、定义与递推关系

### 1. 递归公式
卡特兰数的递归定义为：
\[
C_0 = 1, \quad C_n = \sum_{i=0}^{n-1} C_i \cdot C_{n-1-i} \quad (n \geq 1)
\]
其中，\(C_n\) 表示第 \(n\) 个卡特兰数。


### 2. 递推公式
通过递归式可推导出递推形式（迭代计算更高效）：
初始化 \(C_0 = 1\)，对于 \(n \geq 1\)，有：
\[
C_n = \frac{2(2n-1)}{n+1} \cdot C_{n-1}
\]


### 3. 通项公式
用二项式系数表示的通项为：
\[
C_n = \frac{1}{n+1} \binom{2n}{n} = \binom{2n}{n} - \binom{2n}{n-1}
\]


## 二、典型应用场景

卡特兰数能解决多类“**有约束的排列/组合计数问题**”，以下是经典场景：

### 1. 栈的出栈序列数
给定 \(n\) 个元素的入栈序列 \(1,2,\dots,n\)，求所有可能的合法出栈序列总数。
- 示例：\(n=3\) 时，合法序列有 `123、132、213、231、321`，共 \(5\) 种（即 \(C_3=5\)）。


### 2. 括号匹配问题
求 \(n\) 对括号（`(` 和 `)`）的**有效组合数**（左括号与右括号数量相等且任意前缀中左括号数≥右括号数）。
- 示例：\(n=2\) 时，有效组合为 `(())、()()`，共 \(2\) 种（即 \(C_2=2\)）。


### 3. 二叉树的形态数
求 \(n\) 个节点能构成的**不同形态的二叉树总数**。
- 示例：\(n=3\) 时，有 \(5\) 种不同形态（即 \(C_3=5\)）。


### 4. 凸多边形三角划分
将一个 \(n+2\) 边形**用 \(n-1\) 条不相交的对角线划分成三角形**的方案数。
- 示例：四边形（\(n=2\)）有 \(2\) 种划分方式（即 \(C_2=2\)）。


## 三、示例计算

以 \(n=0\) 到 \(n=5\) 为例，计算卡特兰数：

| \(n\) | \(C_n\) |
|-------|---------|
| 0     | 1       |
| 1     | 1       |
| 2     | 2       |
| 3     | 5       |
| 4     | 14      |
| 5     | 42      |


## 四、代码实现

### 1. 递归法（带记忆化）
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> catalan;

ll calcCatalan(int n) {
    if (catalan[n] != -1) return catalan[n];
    if (n == 0 || n == 1) return catalan[n] = 1;
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        res += calcCatalan(i) * calcCatalan(n - 1 - i);
    }
    return catalan[n] = res;
}

int main() {
    int n;
    cin >> n;
    catalan.assign(n + 1, -1);
    cout << calcCatalan(n) << endl;
    return 0;
}
```


### 2. 迭代法（递推）
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> catalan(n + 1);
    catalan[0] = 1;
    for (int i = 1; i <= n; ++i) {
        catalan[i] = 0;
        for (int j = 0; j < i; ++j) {
            catalan[i] += catalan[j] * catalan[i - 1 - j];
        }
    }
    cout << catalan[n] << endl;
    return 0;
}
```


### 3. 通项公式法（利用二项式系数）
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll comb(int n, int k) {
    if (k < 0 || k > n) return 0;
    ll res = 1;
    for (int i = 1; i <= k; ++i) {
        res = res * (n - k + i) / i;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    ll c = comb(2 * n, n) / (n + 1);
    cout << c << endl;
    return 0;
}
```


## 五、总结
卡特兰数是组合数学中解决“**有约束计数问题**”的利器，其核心思想是**递归分解子问题**。掌握它的递推关系和应用场景，能高效解决栈序列、括号匹配、二叉树形态等经典问题，是算法学习和竞赛中的重要知识点。

## 二叉树

> 对于ABC 这样的节点，都有A左子树，B根，C右子树

* 先序
根 -> 左子树 -> 右子树
* 中序
左子树 -> 根 -> 右子树
* 后序
左子树 -> 右子树 -> 根


## max(a,b),min(a,b)和abs(a,b)的关系

max(a,b) = (a + b + abs(a - b)) / 2;
min(a,b) = (a + b - abs(a - b)) / 2;

那么 abs(a - b) = max(a,b) - min(a,b);