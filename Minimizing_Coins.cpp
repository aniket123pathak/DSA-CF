#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:

    int coin(int i,int x,vector<int>& a,vector<vector<int>>& dp){
        if(x==0){
            return 0;
        }
        if(i<0){
            return INT_MAX;
        }
        if(dp[i][x]!=-1){
            return dp[i][x];
        }
        // not take 
        int notTake = coin(i-1,x,a,dp);
        //take 
        int take = INT_MAX;
        if(a[i]<=x){
            int res = coin(i,x-a[i],a,dp);
            if(res!=INT_MAX){
                take = 1 + res;
            }
        }
        return dp[i][x] = min(take,notTake);
    }

    void solve()
    {
        int n,i,x;
        cin>>n>>x;
        vector<int>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        
        // int ans = coin(n-1,x,a,dp);
        // if(ans==INT_MAX){
        //     cout<<-1<<endl;
        //     return;
        // }
        // cout<<ans<<endl;
        // vector<int>dp(x+1,INT_MAX);
        // dp[0]=0;
        // for(int i=1;i<=n;i++){
        //     vector<int>cur(x+1,INT_MAX);
        //     for(int j=0;j<=x;j++){
        //         int notTake = dp[j];
        //         int take = INT_MAX;
        //         if(a[i-1]<=j){
        //             int res = cur[j-a[i-1]];
        //             if(res!=INT_MAX){
        //                 take = 1+res;
        //             }
        //         }
        //         cur[j]=min(take,notTake);
        //     }
        //     dp=cur;
        // }
        // if(dp[x]==INT_MAX){
        //     cout<<-1<<endl;
        //     return;
        // }
        // cout<<dp[x]<<endl;;

        vector<int>dp(x+1);
        dp[0]=0;
        for(i=1;i<=x;i++){
            dp[i]=1e9;
            for(int j = 0;j<n;j++){
                if(i>=a[j]){
                    dp[i]=min(dp[i],dp[i-a[j]]+1);
                }
            }
        }
        if(dp[x]==1e9){
            cout<<-1<<endl;
            return;
        }
        cout<<dp[x]<<endl;

        return;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution s;
    s.solve();
    return 0;
}