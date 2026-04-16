#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> parent;
    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        parent[a] = b;
    }
    int kruskalsMST(int V, vector<vector<int>> &edges)
    {
        // wt, u, v
        vector<pair<int, pair<int, int>>> adj;
        for (auto it : edges)
        {
            adj.push_back({it[2], {it[0], it[1]}});
        }
        sort(adj.begin(), adj.end());
        parent.resize(V);
        for (int i = 0; i < V; i++)
            parent[i] = i; // khudka parent khud hi.. (starting meinn)
        int mstWt = 0;
        for (auto it : adj)
        {
            int w = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (find(u) != find(v))
            {
                mstWt += w;
                unite(u, v);
            }
        }

        return mstWt;
    }
};