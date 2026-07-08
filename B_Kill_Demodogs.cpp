#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,j;
        cin>>n;
        ll first = n%1000000007;
        ll second = (n+1)%1000000007;
        ll third = (4*n-1)%1000000007;

        ll fr = (first*second)%1000000007;
        ll sc = (fr*third)%1000000007;
        ll ans = (sc*337)%1000000007;

        cout<<ans<<endl;
        return;
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