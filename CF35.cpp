#include <iostream>
using namespace std;

class Solution {
public:
    void sub() {
        long long n, k;
        string s;
        int count = 0;

        cin >> n >> k >> s;

        for (char c : s) {
            if (c == '1') count++;
        }

        if (count <= k || n < 2 * k) {
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }
    }
};

int main() {
    Solution s;
    int tc;
    cin >> tc;
    while (tc-- > 0)
        s.sub();
    return 0;
}