#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,j,x;
        cin>>n>>x;
        vector<ll>h(n);
        for(i=0;i<n;i++){
           cin>>h[i];
        }
        vector<ll>s(n);
        for(i=0;i<n;i++){
           cin>>s[i];
        }
        vector<ll>dp(x+1,0);
        for(i=1;i<=n;i++){
            vector<ll>cur(x+1,0);
            for(j=1;j<=x;j++){
                ll notTake = dp[j];
                ll take = 0;
                if(h[i-1]<=j){
                    take = s[i-1] + dp[j-h[i-1]];
                }
                cur[j] = max(take,notTake);
            }
            dp=cur;
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