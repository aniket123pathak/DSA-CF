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
        vector<ll>dp(n+1);
        dp[1]=1;
        dp[2]=2;
        dp[3]=4;
        dp[4]=8;
        dp[5]=16;
        dp[6]=32;

        for(i=7;i<=n;i++){
            dp[i]=(dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4]+dp[i-5]+dp[i-6])%(ll)(1e9+7);
        }

        cout<<dp[n]<<endl;
        
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