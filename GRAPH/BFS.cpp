#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

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

    queue<ll>que;
    vector<ll>visited(n+1,0);
    vector<ll>bfs;

    cout<<"Enter the starting vertex : ";
    ll sv;
    cin>>sv;
    que.push(sv);
    visited[sv]=1;
    while(!que.empty()){
        ll cur = que.front();
        que.pop();
        bfs.push_back(cur);
        for(ll neighbour : al[cur]){
            if(visited[neighbour]!=1){
                que.push(neighbour);
                visited[neighbour]=1;
            }
        }
    }
    for(i=0;i<bfs.size();i++){
        cout<<bfs[i]<<" ";
    }
    return 0;
}