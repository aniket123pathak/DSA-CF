#include <iostream>
#include <set>
using namespace std;

// Display function
void display(set<int> s) {
    for (int x : s)
        cout << x << " ";
    cout << endl;
}

int main() {
    set<int> A, B;
    int n, m, x;

    // Input Set A
    cout << "Enter number of elements in Set A: ";
    cin >> n;
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> x;
        A.insert(x);
    }

    // Input Set B
    cout << "\nEnter number of elements in Set B: ";
    cin >> m;
    cout << "Enter elements:\n";
    for (int i = 0; i < m; i++) {
        cin >> x;
        B.insert(x);
    }

    // Union
    set<int> unionSet = A;
    unionSet.insert(B.begin(), B.end());

    // Intersection
    set<int> intersectionSet;
    for (int a : A) {
        if (B.find(a) != B.end()) {
            intersectionSet.insert(a);
        }
    }

    // Difference (A - B)
    set<int> differenceSet;
    for (int a : A) {
        if (B.find(a) == B.end()) {
            differenceSet.insert(a);
        }
    }

    // Output
    cout << "\nSet A: ";
    display(A);

    cout << "Set B: ";
    display(B);

    cout << "Union: ";
    display(unionSet);

    cout << "Intersection: ";
    display(intersectionSet);

    cout << "Difference (A - B): ";
    display(differenceSet);

    return 0;
}