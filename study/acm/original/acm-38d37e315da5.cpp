#include<bits/stdc++.h>
using namespace std;
int main(){
    string s(100,'0');//100个0
    string s1="awa";
    cout<<s1<<endl;
    s1[0]='b';//更改第一个字母
    string s2="123",s3="123";
    if(s2==s3)
    {
        cout<<"yes"<<endl;
    }
    s1+="a4g";
    cout<<s1+s2<<endl;//把两个字符串加在一起
    cout<<s1.substr(2,3)<<endl;//-创建子字符串，从第二位开始，往后数三位
    if(s1.find("aw")!=string::npos)//如果找到，则返回子字符串起始点的下标
    {
        cout<<"yes"<<endl;
    }
    int x=stoi(s2);//long long->stoll,float->stof,double->stod,long double->stold
    cout<<x<<endl;//string转成其他整形
    int c=13455;
    string s4=to_string(c);
    cout<<s4<<endl;//将其他整形转换成string
}