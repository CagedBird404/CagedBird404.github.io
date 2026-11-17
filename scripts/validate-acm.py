"""Compile study templates without executing untrusted archived programs."""
from pathlib import Path
import concurrent.futures,json,subprocess,tempfile,re

root=Path(__file__).resolve().parent.parent
catalog=json.loads((root/'study/acm/catalog.json').read_text(encoding='utf8'))

def check(item):
    try:
        result=subprocess.run(['g++','-std=c++17','-fsyntax-only','-w','-fmax-errors=2',str(root/item['source'])],capture_output=True,text=True,timeout=45)
        return {**item,'syntax_passed':result.returncode==0,'diagnostic':result.stderr[-3500:]}
    except subprocess.TimeoutExpired:
        return {**item,'syntax_passed':False,'diagnostic':'编译检查超时'}

with concurrent.futures.ThreadPoolExecutor(max_workers=4) as pool:
    report=list(pool.map(check,catalog))
for item in report:
    article=root/item['article']
    text=article.read_text(encoding='utf8')
    message=('**验证状态：** GCC C++17 语法检查通过。语法通过不代表所有输入边界和算法正确性均已验证。' if item['syntax_passed'] else '> **待完善：** 当前仍是代码片段或存在编译问题，不应作为可直接提交的完整程序。请结合原题与上下文使用。')
    article.write_text(text.replace('<!-- ACM_VALIDATION -->',message),encoding='utf8')

(root/'public/acm-validation.json').write_text(json.dumps(report,ensure_ascii=False,indent=2),encoding='utf8')
failed=[{'path':x['path'],'repaired':x['repaired'],'diagnostic':x['diagnostic']} for x in report if not x['syntax_passed']]
print(json.dumps({'total':len(report),'syntax_passed':sum(x['syntax_passed'] for x in report),'failures':failed},ensure_ascii=False),flush=True)
if any(x['repaired'] and not x['syntax_passed'] for x in report):
    raise SystemExit('A repaired template failed compilation')

# Tests below run only the explicitly reviewed reusable functions.
test_paths=['算法/dp/01背包问题.cpp','算法/dp/完全背包问题.cpp','算法/dp/分组背包问题.cpp','算法/dp/最长公共子序列.cpp','算法/dp/最长上升子序列.cpp','算法/dp/数位dp.cpp','算法/dp/状压dp.cpp','算法/dp/有依赖的背包.cpp','算法/dp/期望dp.cpp','算法/分解质因数.cpp','算法/快速幂/快速幂.cpp','算法/快速幂/矩阵快速幂.cpp','算法/数论/03二元一次方程.cpp','算法/数论/组合数问题/大数组合数.cpp','算法/Tarjan.cpp','算法/最短路径/多源/Johnson.cpp','算法/ST表.cpp','算法/字符串/后缀自动机.cpp','算法/字符串/KMp算法字符串.cpp','算法/数论/素数/费马小定理判断素数.cpp','算法/数论/欧拉函数.cpp','算法/数论/欧拉降幂.cpp']
test_paths += ['算法/dfs深度优先搜索/二分搜索.cpp', '算法/排序/归并排序.cpp', '算法/树/树上差分.cpp', '算法/递归/简单-阶乘函数.cpp']
lookup={x['path']:x for x in catalog}
code='#include <bits/stdc++.h>\nusing namespace std;\n'
for i,p in enumerate(test_paths):
    source=(root/lookup[p]['source']).read_text(encoding='utf8')
    source=re.sub(r'^#include[^\n]*\n','',source,flags=re.M)
    code+=f'namespace t{i} {{\n'+source+'\n}\n'
code+=r'''
int main() {
    mt19937 rng(404);
    for (int test=0;test<120;++test) {
        int n=1+rng()%8,V=rng()%20;
        vector<pair<int,long long>> items;
        for(int i=0;i<n;++i) items.push_back({1+(int)(rng()%8),(int)(rng()%20)-3});
        long long brute=0;
        for(int mask=0;mask<(1<<n);++mask) {
            int cost=0;long long value=0;
            for(int i=0;i<n;++i) if(mask>>i&1) {cost+=items[i].first;value+=items[i].second;}
            if(cost<=V) brute=max(brute,value);
        }
        assert(t0::knapsack01(V,items)==brute);
        vector<long long>a(n);
        for(auto&x:a)x=(int)(rng()%11)-5;
        int best=0;
        for(int mask=0;mask<(1<<n);++mask) {
            bool ok=true,first=true;long long last=0;int len=0;
            for(int i=0;i<n;++i) if(mask>>i&1) {if(!first&&a[i]<=last)ok=false;first=false;last=a[i];++len;}
            if(ok)best=max(best,len);
        }
        assert(t4::lisLength(a)==best);
    }
    assert(t1::unboundedKnapsack(8,{{3,5},{4,7}})==14);
    assert(t2::groupedKnapsack(4,{{{2,4},{2,5}},{{3,8}}})==8);
    assert(t3::lcsLength("abcde","ace")==3);
    assert(t3::lcsLength("","x")==0);
    for(int n=0;n<1000;++n){long long brute=0;for(int x=0;x<=n;++x)if(to_string(x).find('4')==string::npos)++brute;assert(t5::countWithout4(n)==brute);}
    assert(t6::hamiltonPath({{0,2,9},{2,0,3},{9,3,0}})==5);
    assert(t7::dependencyKnapsack(5,{0,0,1},{0,2,2},{0,3,8})==11);
    assert(t7::dependencyKnapsack(2,{0,0,1},{0,2,2},{0,3,8})==3);
    auto expectation=t8::dagExpectedSteps({{1,2},{2},{}});assert(abs(expectation[0]-1.5)<1e-9);
    assert((t9::primeFactors(60)==vector<long long>{2,3,5}));
    assert(t9::primeFactors(1).empty());
    assert(t10::modPow(-2,3,5)==2);assert(t10::modPow(7,0,1)==0);
    auto matrix=t11::matrixPow({{1,1},{1,0}},10,1000000007);assert(matrix[0][1]==55);
    long long x,y;assert(t12::linearEquation(6,9,3,x,y)&&6*x+9*y==3);assert(!t12::linearEquation(6,9,4,x,y));
    for(int p:{2,3,5,7,11}) {t13::Lucas lucas(p);for(int n=0;n<25;++n){long long c=1;for(int k=0;k<=n;++k){assert(lucas.choose(n,k)==c%p);c=c*(n-k)/(k+1);}}}
    auto scc=t14::stronglyConnectedComponents({{1},{0,2},{}});assert(scc[0]==scc[1]&&scc[1]!=scc[2]);
    const long long INF=1LL<<60;
    for(int test=0;test<60;++test) {
        int n=2+rng()%6;vector<t15::Edge> edges;vector<vector<long long>> d(n,vector<long long>(n,INF));
        for(int i=0;i<n;++i)d[i][i]=0;
        // DAG allows negative edges, but no negative cycles.
        for(int i=0;i<n;++i)for(int j=i+1;j<n;++j)if(rng()%2){long long w=(int)(rng()%15)-5;edges.push_back({i,j,w});d[i][j]=w;}
        for(int k=0;k<n;++k)for(int i=0;i<n;++i)for(int j=0;j<n;++j)if(d[i][k]!=INF&&d[k][j]!=INF)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        auto result=t15::johnson(n,edges);assert(result&&*result==d);
    }
    assert(!t15::johnson(2,{{0,1,-2},{1,0,1}}));
    t16::SparseTable st({-3,8,4,2});assert(st.query(0,3)==8&&st.query(2,3)==4);
    for(int test=0;test<100;++test){string s;for(int i=0,n=rng()%10;i<n;++i)s+=char('a'+rng()%3);t17::SuffixAutomaton sam;for(char c:s)sam.extend(c);set<string> all;for(int i=0;i<(int)s.size();++i)for(int len=1;i+len<=(int)s.size();++len)all.insert(s.substr(i,len));assert(sam.distinctSubstrings()==(long long)all.size());}
    assert((t18::kmpMatches("aaaa","aa")==vector<int>{0,1,2}));
    assert((t18::kmpMatches("ab","")==vector<int>{0,1,2}));
    for(int n=0;n<10000;++n){bool prime=n>=2;for(int d=2;d*d<=n;++d)if(n%d==0)prime=false;assert(t19::millerRabin(n)==prime);}
    assert(!t19::millerRabin(561));assert(t19::millerRabin(18446744073709551557ULL));
    assert(t20::phi(1)==1&&t20::phi(12)==4);
    for(int m=2;m<50;++m)for(int a=1;a<m;++a)if(gcd(a,m)==1)for(int e=0;e<15;++e)assert(t21::eulerPower(a,to_string(e),m)==t10::modPow(a,e,m));
    assert(t22::binarySearch({1,2,2,5},2)==1);
    assert(t22::binarySearch({},2)==-1);
    vector<long long> sortable{3,-1,3,0}; t23::mergeSort(sortable);
    assert((sortable==vector<long long>{-1,0,3,3}));
    auto cover=t24::pathCounts({{},{2},{1,3},{2}},{{1,3},{2,3}});
    assert((cover==vector<long long>{0,1,2,2}));
    assert(t25::factorial(0)==1 && t25::factorial(20)==2432902008176640000LL);
    cout<<"ACM regression tests passed: knapsack, LIS/LCS, digit DP, graph, number theory, strings.\n";
}
'''
with tempfile.TemporaryDirectory() as temp:
    source=Path(temp)/'regression.cpp';binary=Path(temp)/'regression'
    source.write_text(code,encoding='utf8')
    subprocess.run(['g++','-std=c++17','-O2',str(source),'-o',str(binary)],check=True,timeout=90)
    subprocess.run([str(binary)],check=True,timeout=45)

# Verify every article-to-article link and explicit knowledge anchor before deploy.
posts={p.stem:p for p in (root/'src/content/posts').glob('*.md')}
broken=[]
for p in posts.values():
    text=p.read_text(encoding='utf8')
    for dest,anchor in re.findall(r'\]\(/posts/([^/#]+)/?(?:#([^)]*))?\)',text):
        if dest not in posts: broken.append(f'{p.name}: missing {dest}')
        elif anchor and f'id="{anchor}"' not in posts[dest].read_text(encoding='utf8'):broken.append(f'{p.name}: missing anchor {dest}#{anchor}')
if broken:raise SystemExit('\n'.join(broken))
print('Internal links and knowledge anchors passed',flush=True)

