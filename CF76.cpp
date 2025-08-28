#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    void solve() {
        int n, m;
        cin >> n >> m;
        string x, s;
        cin >> x >> s;

        for (int k = 0; k < 6; k++) {
            
            if ((int)x.length() >= m) {
                for (int i = 0; i <= (int)x.length() - m; i++) {
                    int j = 0;
                    while (j < m && x[i + j] == s[j]) {
                        j++;
                    }
                    if (j == m) {
                        cout << k << "\n";
                        return;
                    }
                }
            }
            x += x; 
        }
        cout << -1 << "\n";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution s;
    int tc;
    cin >> tc;
    while (tc-- > 0) {
        s.solve();
    }
    return 0;
}
