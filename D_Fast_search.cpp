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
        ll n,i,k;
        cin>>n;
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        cin>>k;
        sort(a.begin(),a.end());
        for(i=0;i<k;i++){
            ll x,y;
            cin>>x>>y;
            auto lb = lower_bound(a.begin(),a.end(),x);
            auto ub = upper_bound(a.begin(),a.end(),y);
            cout<<ub-lb<<" ";
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution s;
    s.solve();
    return 0;
}