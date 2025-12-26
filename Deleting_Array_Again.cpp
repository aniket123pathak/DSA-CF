#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define v(a, n) vector<long long> a(n)
#define fin(i, x, n, a)     \
    for (i = x; i < n; i++) \
    cin >> a[i]

class Solution
{
public:
    void solve()
    {
        ll n, i, j;
        cin >> n;
        vector<ll> a(n);
        vector<ll> c(n);
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (i = 0; i < n; i++)
        {
            cin >> c[i];
        }
        ll x = n;
        ll cost = 0;
        while (x > 0)
        {
            ll minCi = INT64_MAX;
            ll tempIdx = 101;
            for (j = 0; j < x; j++)
            {
                minCi = min(minCi, c[j]);
                if (minCi == c[j])
                {
                    tempIdx = j;
                }
            }

            for (int k = tempIdx; k < x; k++)
            {
                cost += minCi * a[k];
            }
            x = tempIdx;
        }

        cout << cost << endl;
    }
};

int main()
{
    Solution s;
    int tc;
    cin >> tc;
    while (tc-- > 0)
    {
        s.solve();
    }
    return 0;
}