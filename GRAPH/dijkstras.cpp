#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

vector<int> dijkstras(int V , vector<vector<pair<int,int>>> adj, int S){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    vector<int> distance(V, INT_MAX);
    distance[S] = 0;

    pq.push({0, S});

    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(dis > distance[node]) continue;

        for(auto it : adj[node]){
            int adjNode = it.first;
            int edgeWeight = it.second;

            if(dis + edgeWeight < distance[adjNode]){
                distance[adjNode] = dis + edgeWeight;
                pq.push({distance[adjNode], adjNode});
            }
        }
    }
    return distance;
}

int main() {
    
    return 0;
}