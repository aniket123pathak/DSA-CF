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
        ll n,i,x,y;
        cin>>n>>x>>y;
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        ll sum =0;
        for(i=0;i<n;i++){
            sum+=(a[i]/x)*y;
        }
        ll mx = 0;
        for(i=0;i<n;i++){
            mx=max(mx,sum+a[i]-((a[i]/x)*y));
        }
        cout<<mx<<endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution s;
    int tc;
    cin >> tc;
    while (tc-- > 0)
    {
        s.solve();
    }
    return 0;
}   