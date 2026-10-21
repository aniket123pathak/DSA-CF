#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i;
        cin>>n;
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        sort(a.begin(),a.end());
        vector<ll>pf(n);
        pf[0]=a[0];
        for(i=1;i<n;i++){
            pf[i]=pf[i-1]+a[i];
        }
        ll ans = 0;
        for(i=1;i<n;i++){
            ll sm1 = pf[n-1]-pf[n-i-1];
            ll sm2 = pf[n-1-i];
            ans = max(ans ,sm1*(n-i)+sm2*i);
        }
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