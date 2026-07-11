#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,m,j;
        cin>>n>>m;
        vector<bool>rowCheck(n+1,false);
        vector<bool>colCheck(n+1,false);
        vector<vector<ll>>grid1(n+1,vector<ll>(n+1,-1));
        vector<vector<ll>>grid2(n+1,vector<ll>(n+1,-1));
        vector<pair<ll,ll>>inp(m);
        for(i=0;i<m;i++){
           cin>>inp[i].first;
           cin>>inp[i].second;
        }

        for(i=m-1;i>=0;i--){
            if(!rowCheck[inp[i].first]){
                grid1[inp[i].first][inp[i].second]=1;
                rowCheck[inp[i].first]=true;
            }
        }

        for(i=m-1;i>=0;i--){
            if(!colCheck[inp[i].second]){
                grid2[inp[i].first][inp[i].second]=1;
                colCheck[inp[i].second]=true;
            }
        }
        ll ans = 0;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(grid1[i][j]==grid2[i][j]&&grid1[i][j]!=-1){
                    ans++;
                }
            }
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