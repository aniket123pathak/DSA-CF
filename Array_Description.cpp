#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:

    ll bigDihh(ll i,ll prev,ll& m,vector<ll>& a,vector<vector<ll>>& dp){
        if(i<0){
            return 1;
        }
        if(dp[i][prev]!=-1){
            return dp[i][prev];
        }
        if(a[i]!=0){
            if(abs(prev-a[i])>1){
                return 0;
            }
            return bigDihh(i-1,a[i],m,a,dp);
        }
        ll ans1 = bigDihh(i-1,prev,m,a,dp);
        ll ans2 = 0;
        if(prev>1){
            ans2 = bigDihh(i-1,prev-1,m,a,dp);
        }
        ll ans3 = 0;
        if(prev<m){
            ans3 = bigDihh(i-1,prev+1,m,a,dp);
        }
        return dp[i][prev]=(ans1+ans2+ans3)%(ll)(1e9+7);

    }

    void solve()
    {
        ll n,i,m;
        cin>>n>>m;
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        vector<vector<ll>>dp(n,vector<ll>(m+1,-1));
        ll ans =0;
        if(a[n-1]==0){
            for(i=1;i<=m;i++){
                ans = (ans+bigDihh(n-2,i,m,a,dp))%(ll)(1e9+7);
            }
        }
        else{
            ans = bigDihh(n-2,a[n-1],m,a,dp);
        }
        cout<<ans<<endl;
        return;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution s;
    s.solve();
    return 0;
}