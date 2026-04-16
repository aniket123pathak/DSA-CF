#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main()
{
    int n, m;
    cin >> n >> m; // nodes, edges
    vector<vector<pair<int, int>>> adj(n);
    // input edges: u v weight
    // adj list have -> nodes, edgeWt
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // remove if directed
    }
    int src, dest;
    cin >> src >> dest;
    vector<int> dist(n, INF);
    dist[src] = 0;
    // stores {distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, src});
    while (!pq.empty())
    {
        auto temp = pq.top();
        pq.pop();
        int dis = temp.first;
        int node = temp.second;
        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edgeWt = it.second;
            if (dis + edgeWt < dist[adjNode])
            {
                dist[adjNode] = dis + edgeWt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    cout << "Shortest Distance: " << dist[dest];
    return 0;
}