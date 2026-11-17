#include<bits/stdc++.h>
using namespace std;
int main(){
    int num;
    cin>> num;
    vector<int> arr(100);
    for(int i=0;i<100;i++)
    {
        cin>> arr[i];
    }
    int l=0;
    r=arr.size()-1;
    m=0;
    while(l<=r)
    {
        m=(l+r)/2;
        if(arr[m]==num)
        {
            cout<< "true"<<endl;
            break;
        }
        else if(arr[m]<num)
        {
            l=m+1;
        }
        else
        {
            r=m-1;
        }
    }
}