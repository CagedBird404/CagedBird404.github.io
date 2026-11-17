#include<bits/stdc++.h>
using namespace std;
//vector<类型> 数组名(长度[初值])
int main(){
    vector<int> arr;//100行，初值为1
    vector<vector<int>> dp(5,vector<int>(6,2));//6行，5列，初值为2
    vector<vector<vector<int>>> dp2(9,vector<vector<int>>(6,vector<int>(5,0)));
    arr.push_back(1);//尾接         //9为x轴，6为y轴，5为z轴
    arr.push_back(2);
    arr.push_back(3);

    arr.emplace_back(4);//可以节省时间

    
    //arr.pop_back();//尾删
    cout<<arr.size()<<endl;
    cout<<arr.empty()<<endl;//判断是否为空集，是空返回1，否则为0
    //一般用于 if(arr.enpty()){}
    arr.resize(5,3)//改变数组长度，空的用0补充，后面数字为改变的初值，只对空余部分有效
    

    //删除小技巧：如果你想删某一项,但是不能有顺序
    arr[k] = arr.back();
    arr.pop_back();
    return 0;
}