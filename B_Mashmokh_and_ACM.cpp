#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,k,i,j;
        cin>>n>>k;
        ll mod = 1e9+7;
        vector<vector<ll>>divisors(n+1);
        for(i=1;i<=n;i++){
            for(j=1;j*j<=i;j++){
                if(i%j==0){
                    divisors[i].push_back(j);
                    if(i/j!=j){
                        divisors[i].push_back(i/j);
                    }
                }
            }
        }

        vector<vector<ll>>dp(k+1,vector<ll>(n+1,0));
        for(i=1;i<=n;i++){
            dp[1][i]=1;
        }

        for(i=2;i<=k;i++){
            for(j=1;j<=n;j++){
                ll sz = divisors[j].size();
                for(ll k =0;k<sz;k++){
                    dp[i][j]=(dp[i][j]+dp[i-1][divisors[j][k]])%mod;
                }
            }
        }
        ll ans = 0;
        for(i=1;i<=n;i++){
            ans = (ans+dp[k][i])%mod;
        }
        cout<<ans<<endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution s;
    int tc;
    s.solve();
    return 0;
}