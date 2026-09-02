#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,j;
        cin>>n;
        vector<vector<char>>a(n,vector<char>(n));
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        if(a[0][0]=='*'){
            cout<<0<<endl;
            return;
        }
        vector<ll>dp(n,0);
        dp[0]=1;
        for(i=0;i<n;i++){
            if(a[0][i]!='*'){
                dp[i]=1;
            }
            else{
                break;
            }
        }
        
        for(i=1;i<n;i++){
            vector<ll>cur(n,0);
            for(j=0;j<n;j++){
                if(a[i][j]!='*'){
                    if(j==0){
                        cur[j]=(cur[j]+dp[j])%(ll)(1e9+7);
                    }
                    else{
                        cur[j] = (cur[j-1]+dp[j])%(ll)(1e9+7);
                    }
                }
            }
            dp=cur;
        }
        cout<<dp[n-1];
        
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