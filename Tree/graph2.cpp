#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    int numVertices;
    // Adjacency list to store the graph
    vector<vector<int>> adjList; 

    // Recursive helper function for DFS
    void DFSUtil(int vertex, vector<bool>& visited) {
        // Mark the current node as visited and print it
        visited[vertex] = true;
        cout << vertex << " ";

        // Recur for all the vertices adjacent to this vertex
        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

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

    // Function to initiate Depth First Traversal
    void DFS(int startVertex) {
        // Track visited vertices to avoid infinite loops
        vector<bool> visited(numVertices, false);
        
        cout << "Depth First Traversal starting from vertex " << startVertex << ":\n";
        
        // Call the recursive helper function
        DFSUtil(startVertex, visited);
        
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
    cout << "Enter the starting vertex for DFS: ";
    cin >> startNode;

    if (startNode >= 0 && startNode < vertices) {
        g.DFS(startNode);
    } else {
        cout << "Invalid starting vertex!\n";
    }

    return 0;
}