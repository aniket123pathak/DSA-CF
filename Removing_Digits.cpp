#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:

    ll dihh(ll n,vector<ll>& dp){
        if(n==0){
            return 0;
        }
        if(n<0){
            return INT64_MAX;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        vector<ll>rem;
        ll x = n;
        while(x!=0){
            ll r = x%10;
            rem.push_back(r);
            x/=10;
        }
        ll ans = INT64_MAX;
        for(auto cur : rem){
            if(cur!=0){
                ans = min(ans, dihh(n-cur,dp));
            }
        }
        return dp[n]=ans+1;
    }

    void solve()
    {
        ll n,i;
        cin>>n;
        vector<ll>dp(n+1,INFINITY);
        //ll ans = dihh(n,dp);
        //cout<<ans<<endl;
        dp[0]=0;
        for(i=1;i<=n;i++){
            ll x = i;
            while(x!=0){
                ll r = x%10;
                if(r<=i&&r!=0){
                    dp[i] = min(dp[i],dp[i-r]+1);
                }
                x/=10;
            }
        }
        cout<<dp[n]<<endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution s;    
    s.solve();
    return 0;
}