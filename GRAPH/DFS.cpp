#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

void DFS(ll sv,vector<ll>& dfs,vector<ll>& visited,vector<vector<ll>>& adj){
    visited[sv]=1;
    dfs.push_back(sv);

    for(ll neighbour : adj[sv]){
        if(visited[neighbour]!=1){
            DFS(neighbour,dfs,visited,adj);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll m,n,i;
    cin>>n>>m;
    vector<vector<ll>>al(n+1);
    for(i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        al[x].push_back(y);
        al[y].push_back(x);
    }
    vector<ll>visited(n+1,0);
    vector<ll>dfs;
    ll sv;
    cin>>sv;
    DFS(sv,dfs,visited,al);
    for(i=0;i<dfs.size();i++){
        cout<<dfs[i]<<" ";
    }
    return 0;
}