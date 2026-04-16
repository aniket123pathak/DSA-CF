#include <iostream>
#include <map>
#include <list>
using namespace std;

class Graph {
    map<string, list<string>> adj;  // adjacency list

public:
    // Add city
    void addCity(string city) {
        adj[city]; // creates entry if not exists
    }

    // Add route (undirected)
    void addRoute(string city1, string city2) {
        adj[city1].push_back(city2);
        adj[city2].push_back(city1);
    }

    // Display graph
    void display() {
        cout << "\nTransportation Network:\n";
        for (auto pair : adj) {
            cout << pair.first << " -> ";
            for (auto neighbor : pair.second) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g;
    int choice;
    string city1, city2;

    do {
        cout << "\n--- Transportation Network ---";
        cout << "\n1. Add City";
        cout << "\n2. Add Route";
        cout << "\n3. Display Network";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter city name: ";
                cin >> city1;
                g.addCity(city1);
                break;

            case 2:
                cout << "Enter source city: ";
                cin >> city1;
                cout << "Enter destination city: ";
                cin >> city2;
                g.addRoute(city1, city2);
                break;

            case 3:
                g.display();
                break;

            case 4:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice!";
        }

    } while (choice != 4);

    return 0;
}