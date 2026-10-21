#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:

    ll shatShut(ll i,vector<ll>& a,ll& n,vector<ll>& dp){
        if(i==n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        ll notTake = 1 + shatShut(i+1,a,n,dp);
        ll take = 1e9;
        if(i+a[i]<n){
            take = shatShut(i+a[i]+1,a,n,dp);
        }
        return dp[i]=min(take,notTake);
    }

    void solve()
    {
        ll n,i;
        cin>>n;
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        vector<ll>dp(n,-1);
        ll ans = shatShut(0,a,n,dp);
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