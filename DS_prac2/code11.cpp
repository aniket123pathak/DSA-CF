#include <iostream>
#include <set>
using namespace std;

// Function to display set
void displaySet(set<string> s) {
    for (auto i : s)
        cout << i << " ";
    cout << endl;
}

int main() {
    set<string> spanish, german;
    int n, m;
    string name;

    // Input Spanish attendees
    cout << "Enter number of Spanish attendees: ";
    cin >> n;
    cout << "Enter names:\n";
    for (int i = 0; i < n; i++) {
        cin >> name;
        spanish.insert(name);
    }

    // Input German attendees
    cout << "\nEnter number of German attendees: ";
    cin >> m;
    cout << "Enter names:\n";
    for (int i = 0; i < m; i++) {
        cin >> name;
        german.insert(name);
    }

    // Union
    set<string> unionSet = spanish;
    unionSet.insert(german.begin(), german.end());

    // Intersection
    set<string> intersectionSet;
    for (auto s : spanish) {
        if (german.find(s) != german.end()) {
            intersectionSet.insert(s);
        }
    }

    // Difference (Spanish - German)
    set<string> differenceSet;
    for (auto s : spanish) {
        if (german.find(s) == german.end()) {
            differenceSet.insert(s);
        }
    }

    // Display results
    cout << "\nSpanish Set: ";
    displaySet(spanish);

    cout << "German Set: ";
    displaySet(german);

    cout << "Union: ";
    displaySet(unionSet);

    cout << "Intersection: ";
    displaySet(intersectionSet);

    cout << "Difference (Spanish - German): ";
    displaySet(differenceSet);

    return 0;
}