#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,m;
        cin>>n>>m;
        vector<pair<ll,ll>>a(m);
        vector<vector<ll>>adj(n+1,vector<ll>());
        for(i=0;i<m;i++){
           cin>>a[i].first;
           cin>>a[i].second;
           ll mn = min(a[i].first,a[i].second);
           ll mx = max(a[i].first,a[i].second);
           adj[mn].push_back(mx);
        }
        for(i=1;i<=n;i++){
            sort(adj[i].begin(),adj[i].end());
        }
        ll left = 1;
        ll right = 1;
        ll maxR = INT64_MAX;
        ll ans = 0;
        for(i=1;i<=n;i++){
            if(right==maxR){
                ans+=((right-left)*(right-left+1))/2;
                i = left;
                left++;
                maxR = INT64_MAX;
            }
            if(adj[i].size()>0){
                maxR = min(maxR,adj[i][0]);
            }
            right++;
        }
        ans+=((right-left)*(right-left+1))/2;
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