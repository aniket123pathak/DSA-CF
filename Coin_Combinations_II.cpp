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
        for(i=0;i<n;i++){
            vector<ll>temp(x+1,0);
            temp[0]=1;
            for(ll j=1;j<=x;j++){
                ll notTake = dp[j];
                ll take = 0;
                if(j>=a[i]){
                    take = temp[j-a[i]];
                }
                temp[j] = (take+notTake)%(ll)(1e9+7);
            }
            dp=temp;
        }
        cout<<dp[x]<<endl;
        
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