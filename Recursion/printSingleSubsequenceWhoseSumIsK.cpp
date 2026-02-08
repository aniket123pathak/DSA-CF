#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

bool printAllSubsequencesSumIsK(vector<int>& a,vector<int>& arr,int sum ,int idx,int n,int k){
    if(idx==n){
        if(sum==k){
            for(const auto i : arr){
                cout<<i<<" ";
            }
            cout<<endl;
            return true;
        }
        return false;
    }
    arr.push_back(a[idx]);
    if(printAllSubsequencesSumIsK(a,arr,sum+a[idx],idx+1,n,k))return true;
    arr.pop_back();
    if(printAllSubsequencesSumIsK(a,arr,sum,idx+1,n,k)) return true;

    return false;
    
}

int main() {
    vector<int> a = {1,2,3};
    int n = a.size();
    vector<int> arr;
    int sum =0;
    int k = 3;
    printAllSubsequencesSumIsK(a,arr,sum,0,n,k);
    return 0;
}