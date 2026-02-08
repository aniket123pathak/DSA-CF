#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

int printAllSubsequencesSumIsK(vector<int>& a,int sum ,int idx,int n,int k){
    if(idx==n){
        if(sum==k){
            return 1;
        }
        return 0;
    }
    int l =printAllSubsequencesSumIsK(a,sum+a[idx],idx+1,n,k);
    int r =printAllSubsequencesSumIsK(a,sum,idx+1,n,k);
    return l+r;
}

int main() {
    vector<int> a = {1,2,3};
    int n = a.size();
    int sum =0;
    int k = 3;
    cout<<printAllSubsequencesSumIsK(a,sum,0,n,k)<<endl;
    return 0;
}