#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,x;
        cin>>n>>x;
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        vector<ll>dp(x+1,0);
        dp[0]=1;
        for(i=1;i<=x;i++){
            for(ll j=0;j<n;j++){
                if(i>=a[j]){
                    dp[i] = (dp[i]+dp[i-a[j]])%(ll)(1e9+7);
                }
            }
        }
        cout<<dp[x];
        
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