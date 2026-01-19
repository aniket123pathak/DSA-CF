#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,k,i;
        cin>>n>>k;
        vector<ll>a(n);
        ll count=0;
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        k=a[k-1];
        cout<<count<<endl;
    }
};

int main() {
    Solution s;
        s.solve();
    return 0;
}