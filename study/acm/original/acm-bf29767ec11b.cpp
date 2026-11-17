#include<bits/stdc++.h>//可以用来去重，排序
using namespace std;//set中一个元素在集合中只能出现一次，multiset中可以出现多次，两个都会从小到大排好序
int main(){
    set<int> st;
    st.insert(1);
    st.insert(2);
    st.insert(0);
    st.erase(2);//删除
    st.find(1);//寻找元素
    st.count(2);//查询有几个，set中返回值只有两个1或0
    if(st.count(1))
    {
        cout<<"yes"<<endl;
    };
    cout<<st.size()<<endl;
    //st.clear();//清空
    cout<<st.empty()<<endl;
    for(auto&&i:st)
    {
        cout<<i<<endl;
    };
    //迭代器进行遍历
    for(set<int>::iterator it=st.begin();it!=st.end();++it)
    {
        cout<<*it<<endl;
    };
}