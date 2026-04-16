#include <iostream>
#include <string>
using namespace std;

int main() {
    string text, pattern;

    cout << "Enter the text: ";
    cin >> text;

    cout << "Enter the pattern: ";
    cin >> pattern;

    int n = text.length();
    int m = pattern.length();
    bool found = false;

    // Brute Force Matching
    for (int i = 0; i <= n - m; i++) {
        int j;

        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }

        // If pattern found
        if (j == m) {
            cout << "Pattern found at index: " << i << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Pattern not found!" << endl;
    }

    return 0;
}