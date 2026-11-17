#include<bits/stdc++.h>
using namespace std;
int hanoi(int n,char F,char A,char T)
{
    if(n==1)
    {
        cout<<"move"<<n<<"from"<<F<<"to"<<T;
        return;
    }
    hanoi(n-1,F,T,A);
    cout<<"move"<<n<<"from"<<F<<"to"<<T;
    hanoi(n-1,A,F,T);
}
/*递归思想：
    1、确定函数是什么作用
    2、从最简单问题（源头问题）开始，一步一步进行拆分
    3、拆分的问题都可以再用函数解决
    4，函数不一定是直接解决问题的，可能也是一种解决手段
    5、注意：一定要坚定自己的函数作用
*/
int main(){

}