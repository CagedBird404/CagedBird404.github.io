#include<bits/stdc++.h>//一个键只能在映射中出现一次，键自动从小到大排序
using namespace std;
int main(){
    map<int,int> mp;
    mp[2]=1;
    mp[1]=3;
    mp[3]=10;
    mp[0]=6666;
    for(auto&&i:mp)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<mp[2]<<endl;
    mp.erase(2);//删去2这个键
    cout<<mp.count(2)<<endl;//返回有几个2
    cout<<mp.size()<<endl;
    mp.clear();
    while(mp.contains());   //可以作为判断条件，看是否有这个键
    cout<<mp.empty()<<endl;
    if(mp.find(2)!=mp.end())//如果寻找到了，返回2的迭代器，否则返回尾迭代器
    {
        cout<<"yes"<<endl;
    }
    else
    {
        cout<<"no"<<endl;
    }
    map<string,int> A;
    vector<string> B;
    B.push_back("app");
    B.push_back("app");
    B.push_back("app");
    B.push_back("vcr");
    B.push_back("vcr");
    B.push_back("app");
    for(int i=0;i<B.size();i++)
    {
        A[B[i]]++;
    };
    for(auto&&i:A)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
}
