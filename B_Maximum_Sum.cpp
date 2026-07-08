#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,k;
        cin>>n>>k;
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        sort(a.begin(),a.end());

        vector<ll>pf(n);
        vector<ll>sf(n);

        pf[0]=a[0];
        for(i=1;i<n;i++){
            pf[i]=pf[i-1]+a[i];
        }
        sf[0]=a[n-1];
        for(i=1;i<n;i++){
            sf[i]=sf[i-1]+a[n-1-i];
        }
        ll ans = INT64_MIN;
        for(i=0;i<=k;i++){
            ll mn = 0 ;
            if(i!=0){
                mn = pf[i*2-1];
            }
            ll mx = 0;
            if(i!=k){
                mx = sf[k-1-i];
            }

            ans = max(ans,pf[n-1]-(mn+mx));
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