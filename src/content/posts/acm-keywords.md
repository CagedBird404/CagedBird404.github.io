---
title: "ACM竞赛模板 · 知识点与关键词"
published: 2026-11-16
category: ACM竞赛模板
tags: ["知识点索引"]
description: "点击关键词了解概念，再跳到相关模板。"
pinned: false
---

[返回分类目录](/posts/acm-index/)

[动态规划](#dp) · [二分查找](#binary-search) · [前缀和](#prefix) · [差分](#difference) · [树状数组](#fenwick) · [线段树](#segment-tree) · [ST表](#sparse-table) · [倍增](#doubling) · [最近公共祖先](#lca) · [DFS](#dfs) · [BFS](#bfs) · [图论](#graph) · [拓扑排序](#topological) · [Dijkstra](#dijkstra) · [负环](#negative-cycle) · [强连通分量](#scc) · [并查集](#dsu) · [二分图匹配](#matching) · [网络流](#flow) · [快速幂](#fast-power) · [GCD](#gcd) · [逆元](#inverse) · [素数](#prime) · [欧拉函数](#phi) · [Lucas定理](#lucas) · [高斯消元](#gaussian) · [KMP](#kmp) · [Trie](#trie) · [字符串哈希](#hash) · [后缀自动机](#sam) · [状态压缩](#bitmask) · [优先队列](#heap) · [迭代器](#iterator) · [莫队](#mo) · [离散化](#discretization) · [复杂度](#complexity)

<a id="dp"></a>

## 动态规划

用状态概括已经处理的信息，再通过转移复用子问题结果。先明确状态含义、初值、转移顺序和答案位置。

- [01背包问题](/posts/acm-b56927a13e82/)
- [数位dp](/posts/acm-927f6f82d7ce/)

<a id="binary-search"></a>

## 二分查找

在有序区间或具有单调性的答案空间中，每次排除一半候选。lower_bound 找第一个不小于目标的位置。

- [最长上升子序列](/posts/acm-30bcfb439008/)
- [ST表](/posts/acm-227c4f00c3c6/)

<a id="prefix"></a>

## 前缀和

先记录从起点到各位置的累积值，再通过相减得到区间和。

- [前缀，差分](/posts/acm-018da06c2817/)
- [1树状数组（范围查询，单点修改）](/posts/acm-1b60614dae05/)

<a id="difference"></a>

## 差分

用相邻元素的变化量表示原数组；一次区间加可转成两个端点的增减。

- [前缀，差分](/posts/acm-018da06c2817/)
- [树上差分](/posts/acm-181d67d85ef4/)

<a id="fenwick"></a>

## 树状数组

用 lowbit 划分前缀区间，支持动态前缀统计。经典单点加、前缀求和均为 O(log n)。

- [1树状数组（范围查询，单点修改）](/posts/acm-1b60614dae05/)
- [3树状数组（范围查询，范围修改）](/posts/acm-9a6738cce8bd/)

<a id="segment-tree"></a>

## 线段树

将区间递归二分，合并子区间信息；懒标记把区间更新推迟到必要时下传。

- [1线段树基础加法](/posts/acm-d8256bf91c8f/)
- [2线段树加法和乘法](/posts/acm-2091698e6dfc/)

<a id="sparse-table"></a>

## ST表

预处理长度为 2 的幂的区间信息。重叠两段的 O(1) 查询适用于最值、GCD 等幂等运算。

- [ST表](/posts/acm-227c4f00c3c6/)
- [st表求gcd](/posts/acm-2086585b015c/)

<a id="doubling"></a>

## 倍增

把一次操作扩展成 1、2、4、8…步，按二进制组合查询。

- [LCA共同祖先问题（倍增）](/posts/acm-6355aeace8f7/)
- [ST表](/posts/acm-227c4f00c3c6/)

<a id="lca"></a>

## 最近公共祖先

树上同时作为两个节点祖先的最深节点；常用倍增预处理后查询。

- [LCA共同祖先问题（倍增）](/posts/acm-6355aeace8f7/)
- [树上差分](/posts/acm-181d67d85ef4/)

<a id="dfs"></a>

## DFS

沿当前分支深入，再回溯其他分支；适用于连通分量、树形状态和搜索枚举。深链需注意递归栈。

- [Tarjan](/posts/acm-18decad757c7/)
- [树型dp](/posts/acm-cde7944003fd/)

<a id="bfs"></a>

## BFS

用队列逐层扩展，单位边权图中首次到达即可确定最短距离。

- [bfs 多源找最近最大值](/posts/acm-addc6cc81933/)
- [AC自动机](/posts/acm-774260652a67/)

<a id="graph"></a>

## 图论

先明确有向还是无向、点边编号、是否存在负权、是否连通，再选择算法。

- [Tarjan](/posts/acm-18decad757c7/)
- [Johnson](/posts/acm-c0539a530149/)

<a id="topological"></a>

## 拓扑排序

在 DAG 中安排所有边都从前指向后的节点顺序；常用入度归零队列实现。

- [P_4017_最大食物链(拓扑排序)](/posts/acm-bb016f9e4308/)
- [期望dp](/posts/acm-95f75c628fe0/)

<a id="dijkstra"></a>

## Dijkstra

每次扩展当前距离最小的候选节点，适用于非负边权；有负边时不能直接使用。

- [Dijkstra](/posts/acm-38c0561d770b/)
- [Johnson](/posts/acm-c0539a530149/)

<a id="negative-cycle"></a>

## 负环

总权重为负的有向环。若可达并能影响目标，则通常不存在有限最短距离。

- [Bellman–Ford](/posts/acm-dce7821d1c99/)
- [差分约束](/posts/acm-67eb16b713f6/)

<a id="scc"></a>

## 强连通分量

有向图中极大的两两可达节点集合；缩点后形成 DAG，可用于 2-SAT。

- [Tarjan](/posts/acm-18decad757c7/)
- [2-sat问题](/posts/acm-921f68f2aebd/)

<a id="dsu"></a>

## 并查集

维护动态合并的集合，用路径压缩与按秩或按大小合并优化查找。

- [并查集](/posts/acm-3d2063ca1841/)
- [最小生成树（Kruskal + 并查集）](/posts/acm-7739952a2dae/)

<a id="matching"></a>

## 二分图匹配

在两侧节点间选择互不共享端点的边；最大匹配可由增广路或网络流求解。

- [最大匹配法dfs](/posts/acm-2e047f003844/)
- [最小路覆盖问题](/posts/acm-8830d80818b6/)

<a id="flow"></a>

## 网络流

容量限制下从源点向汇点输送流量；残量网络和反向边是增广的关键。

- [最大流EK](/posts/acm-d5f52484032e/)
- [最小路覆盖问题](/posts/acm-8830d80818b6/)

<a id="fast-power"></a>

## 快速幂

利用指数的二进制展开，通过反复平方把乘法次数降至 O(log e)。

- [快速幂](/posts/acm-48c8db93529d/)
- [矩阵快速幂](/posts/acm-89a27b6cbc0e/)

<a id="gcd"></a>

## GCD

最大公约数。欧几里得算法使用 gcd(a,b)=gcd(b,a%b) 递归缩小问题。

- [01裴蜀定理](/posts/acm-6a724df7489d/)
- [02拓展欧几里得算法](/posts/acm-0df06f54651e/)

<a id="inverse"></a>

## 逆元

a 在模 m 下的逆元满足 a*x≡1(mod m)，存在条件是 gcd(a,m)=1。

- [求逆](/posts/acm-efd4aac231ba/)
- [1逆元](/posts/acm-00eb98730042/)

<a id="prime"></a>

## 素数

大于 1 且只有 1 与自身两个正因数的整数。小范围可筛法，大整数需合适判素算法。

- [判断质数](/posts/acm-991269747200/)
- [费马小定理判断素数](/posts/acm-3e49a74959bd/)

<a id="phi"></a>

## 欧拉函数

phi(n) 表示 1..n 中与 n 互质的整数数目，phi(1)=1。

- [欧拉函数](/posts/acm-fe9d3ad89533/)
- [欧拉降幂](/posts/acm-e7ceeddced74/)

<a id="lucas"></a>

## Lucas定理

质数模数下，将组合数按 p 进制拆为小组合数乘积；预处理规模取决于 p。

- [大数组合数](/posts/acm-51bdf9fde205/)
- [求逆](/posts/acm-efd4aac231ba/)

<a id="gaussian"></a>

## 高斯消元

通过行变换求线性方程组。需要区分无解、唯一解、无穷多解，并注意浮点误差或模域运算。

- [高斯消元法](/posts/acm-44b3164718f4/)
- [期望dp](/posts/acm-95f75c628fe0/)

<a id="kmp"></a>

## KMP

前缀函数记录最长相同真前后缀长度，用于在线性时间内匹配模式串。

- [KMp算法字符串](/posts/acm-e8086e7e153a/)
- [AC自动机](/posts/acm-774260652a67/)

<a id="trie"></a>

## Trie

将公共前缀合并为树路径的字符串结构；AC 自动机在 Trie 上加入失配转移。

- [AC自动机](/posts/acm-774260652a67/)
- [KMp算法字符串](/posts/acm-e8086e7e153a/)

<a id="hash"></a>

## 字符串哈希

把子串映射到数值以快速比较，但哈希相同并不保证原串相同，需要考虑碰撞。

- [哈希前缀字符串双](/posts/acm-c3a6c2d6240d/)
- [后缀自动机](/posts/acm-17cf51dc4e49/)

<a id="sam"></a>

## 后缀自动机

把具有相同 endpos 集合的子串合并成状态，常用于不同子串计数等问题。

- [后缀自动机](/posts/acm-17cf51dc4e49/)
- [最小表示法](/posts/acm-0bd63d098ff8/)

<a id="bitmask"></a>

## 状态压缩

用二进制位表示有限集合；位数能装下不代表 2^n 的时间和内存可承受。

- [状压dp](/posts/acm-48022e812913/)
- [二进制暴力组合数组的数](/posts/acm-decba90bda9a/)

<a id="heap"></a>

## 优先队列

以堆维护当前最大或最小元素；默认 priority_queue 是大顶堆。

- [STL priority（排序优化）](/posts/acm-a4adadab1a7a/)
- [Dijkstra](/posts/acm-38c0561d770b/)

<a id="iterator"></a>

## 迭代器

指向容器位置的抽象；end 是尾后位置，不能解引用。修改容器后需确认迭代器是否失效。

- [STL 迭代器](/posts/acm-89b5bc55087e/)
- [STL vector](/posts/acm-e019318b825d/)

<a id="mo"></a>

## 莫队

重排离线区间询问，通过维护左右端点减少重复计算；带修改和回滚版本有不同维护要求。

- [1普通莫队](/posts/acm-ec9347e15883/)
- [3只增回滚莫队](/posts/acm-cd676791c6e8/)

<a id="discretization"></a>

## 离散化

把实际出现的值映射为有序排名，保留相对大小关系，但不保留原始距离。

- [离散化天际线](/posts/acm-eed522332a27/)
- [1普通莫队](/posts/acm-ec9347e15883/)

<a id="complexity"></a>

## 复杂度

区分预处理、单次操作、总复杂度和额外空间；计算量还受数据结构常数及输入规模影响。

- [板子简洁版](/posts/acm-32e5ca0175a7/)
- [01背包问题](/posts/acm-b56927a13e82/)

