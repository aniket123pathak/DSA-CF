#include<iostream>
using namespace std;

void pairs()
{
    pair<int,int> p = {1,2};
    cout<<p.first<<endl;
    cout<<p.second<<endl;

    pair<int,pair<int,int>> a = {1,{2,3}};
    cout<<a.first<<endl;
    cout<<a.second.first<<endl;
    cout<<a.second.second<<endl;

    pair<int,int> arr[] = {{1,2},{3,4},{5,6}};
    cout<<arr[1].first<<endl;
    cout<<arr[1].second<<endl;
}

int main (){
    pairs();
    return 0;
}