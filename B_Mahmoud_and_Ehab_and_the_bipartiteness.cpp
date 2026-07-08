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
        vector<vector<ll>>adj(n,vector<ll>());
        for(i=0;i<n-1;i++){
            ll u;
            ll v;
            cin>>v;
            cin>>u;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<ll>clr(n,-1);
        queue<ll>q;
        q.push(0);
        clr[0]=0;
        while(!q.empty()){
            ll cur = q.front();
            q.pop();
            for(auto it : adj[cur]){
                if(clr[it]==-1){
                    clr[it]=abs(clr[cur]-1);
                    q.push(it);
                }
            }
        }
        ll cnt1=0;
        ll cnt0 =0;
        for(i=0;i<n;i++){
            if(clr[i]==1){
                cnt1++;
            }
            if(clr[i]==0){
                cnt0++;
            }
        }
        ll totalPsblEdges = cnt1*cnt0;
        ll curEdges = n-1;

        cout<<totalPsblEdges-curEdges<<endl;

        return;
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