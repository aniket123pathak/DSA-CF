#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

void printAllSubsequences(vector<int>& a,vector<int>& arr,int idx,int n){
    if(idx>=n){
        for(int i = 0;i<arr.size();i++){
            cout<<arr[i]<<" ";
        }
        if(arr.size()==0){
        cout<<"{}"<<endl;
        return;
    }
        cout<<endl;
        return;
    }

    arr.push_back(a[idx]);// picking up an element 
    printAllSubsequences(a,arr,idx+1,n);
    arr.pop_back();// not picking up an element
    printAllSubsequences(a,arr,idx+1,n);
}

int main() {
    vector<int> a = {1,2,3};

    vector<int> arr;
    printAllSubsequences(a,arr,0,a.size());

    return 0;
}