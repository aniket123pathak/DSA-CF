#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

class Solution {
public:
    void solve()
    {
        ll n, i, j;
        cin >> n;
        vector<ll> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<bool> check(n, false);
        ll count = 0;

        for (i = 0; i < n; i++) {
            if (a[i] == 1) {
                count++;
                check[i] = true;
            }
            else {
                for (j = 0; j < i; j++) {
                    if (a[i] - 1 == a[j] && check[j]) {
                        count++;
                        check[i] = true;
                        break;
                    }
                }
            }
        }
        cout<<count<<endl;
    }
};

int main() {
    Solution s;
    int tc;
    cin >> tc;
    while (tc-- > 0)
    {
        s.solve();
    }
    return 0;
}