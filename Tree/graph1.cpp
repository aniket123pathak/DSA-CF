#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
private:
    int numVertices;
    // Adjacency list to store the graph
    vector<vector<int>> adjList; 

public:
    // Constructor
    Graph(int vertices) {
        numVertices = vertices;
        adjList.resize(vertices);
    }

    // Function to add an undirected edge
    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src); 
    }

    // Function to perform Breadth First Traversal
    void BFS(int startVertex) {
        // Track visited vertices to avoid infinite loops
        vector<bool> visited(numVertices, false);
        queue<int> q;

        // Mark the starting vertex as visited and enqueue it
        visited[startVertex] = true;
        q.push(startVertex);

        cout << "Breadth First Traversal starting from vertex " << startVertex << ":\n";

        while (!q.empty()) {
            // Dequeue a vertex and print it
            int currentVertex = q.front();
            q.pop();
            cout << currentVertex << " ";

            // Get all adjacent vertices of the dequeued vertex
            for (int neighbor : adjList[currentVertex]) {
                // If a neighbor hasn't been visited, mark it and enqueue it
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << "\n";
    }
};

int main() {
    int vertices, edges;

    cout << "Enter the number of vertices (numbered 0 to V-1): ";
    cin >> vertices;

    Graph g(vertices);

    cout << "Enter the number of edges: ";
    cin >> edges;

    cout << "Enter the edges (source and destination separated by space):\n";
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        
        // Basic validation to prevent out-of-bounds errors
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            g.addEdge(u, v);
        } else {
            cout << "Invalid edge! Vertices must be between 0 and " << vertices - 1 << ".\n";
            i--; // Decrement i to retry this edge
        }
    }

    int startNode;
    cout << "Enter the starting vertex for BFS: ";
    cin >> startNode;

    if (startNode >= 0 && startNode < vertices) {
        g.BFS(startNode);
    } else {
        cout << "Invalid starting vertex!\n";
    }

    return 0;
}