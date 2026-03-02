#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

// Class representing the Transportation Network
class TransportNetwork {
private:
    int numCities;
    unordered_map<string, int> cityToIndex;
    unordered_map<int, string> indexToCity;
    
    // Adjacency list: vector of vectors containing pairs of (neighbor_index, route_cost)
    vector<vector<pair<int, int>>> adjList;

public:
    // Constructor
    TransportNetwork() {
        numCities = 0;
    }

    // Add a new city to the network
    void addCity(string cityName) {
        if (cityToIndex.find(cityName) == cityToIndex.end()) {
            cityToIndex[cityName] = numCities;
            indexToCity[numCities] = cityName;
            adjList.push_back(vector<pair<int, int>>());
            numCities++;
        }
    }

    // Add a bidirectional route between two cities
    void addRoute(string city1, string city2, int cost) {
        // Ensure both cities exist
        if (cityToIndex.find(city1) == cityToIndex.end() || 
            cityToIndex.find(city2) == cityToIndex.end()) {
            cout << "Error: One or both cities not found in the network.\n";
            return;
        }

        int u = cityToIndex[city1];
        int v = cityToIndex[city2];

        // Add edge in both directions (undirected graph)
        adjList[u].push_back({v, cost});
        adjList[v].push_back({u, cost});
    }

    // Visualize the network as a formatted adjacency list
    void visualizeNetwork() {
        cout << "\n=== Transportation Network Visualization ===\n";
        for (int i = 0; i < numCities; ++i) {
            cout << "[" << indexToCity[i] << "] connects to:\n";
            for (auto edge : adjList[i]) {
                cout << "  -> " << indexToCity[edge.first] 
                     << " (Cost/Distance: " << edge.second << ")\n";
            }
        }
        cout << "============================================\n";
    }

    // Determine and display the Minimum Spanning Tree using Prim's Algorithm
    void findMST() {
        if (numCities == 0) {
            cout << "The network is empty.\n";
            return;
        }

        // Priority queue to pick the minimum weight edge: pair<weight, vertex>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> key(numCities, 1e9);     // Store minimum weight to include node in MST
        vector<int> parent(numCities, -1);   // Store the MST structure
        vector<bool> inMST(numCities, false); // Track nodes already included in MST

        // Start from the first city (index 0)
        int startNode = 0;
        pq.push({0, startNode});
        key[startNode] = 0;

        int totalCost = 0;

        while (!pq.empty()) {
            // Extract the minimum cost node
            int u = pq.top().second;
            pq.pop();

            // If already in MST, skip
            if (inMST[u]) continue;

            // Include in MST
            inMST[u] = true;

            // Iterate through all adjacent cities
            for (auto edge : adjList[u]) {
                int v = edge.first;
                int weight = edge.second;

                // If v is not in MST and weight of (u, v) is smaller than current key of v
                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    pq.push({key[v], v});
                    parent[v] = u; // Update parent to construct the tree
                }
            }
        }

        // Display the Minimum Spanning Tree
        cout << "\n=== Minimum Spanning Tree (Optimal Network Routes) ===\n";
        bool isConnected = true;
        for (int i = 1; i < numCities; ++i) {
            if (parent[i] != -1) {
                cout << indexToCity[parent[i]] << " <---> " << indexToCity[i] 
                     << " \t| Cost: " << key[i] << "\n";
                totalCost += key[i];
            } else {
                isConnected = false;
            }
        }
        
        cout << "------------------------------------------------------\n";
        if (isConnected) {
            cout << "Total Cost of Minimum Spanning Tree: " << totalCost << "\n";
        } else {
            cout << "Note: The network is disconnected. MST could not reach all cities.\n";
        }
        cout << "======================================================\n";
    }
};

int main() {
    TransportNetwork network;
    int numCities, numRoutes;

    cout << "Enter the number of cities: ";
    cin >> numCities;

    cout << "Enter the names of the cities:\n";
    for (int i = 0; i < numCities; ++i) {
        string cityName;
        cin >> cityName;
        network.addCity(cityName);
    }

    cout << "Enter the number of routes: ";
    cin >> numRoutes;

    cout << "Enter the routes (City1 City2 Cost):\n";
    for (int i = 0; i < numRoutes; ++i) {
        string city1, city2;
        int cost;
        cin >> city1 >> city2 >> cost;
        network.addRoute(city1, city2, cost);
    }

    // 1. Visualize the complete network
    network.visualizeNetwork();

    // 2. Compute and display the Minimum Spanning Tree
    network.findMST();

    return 0;
}