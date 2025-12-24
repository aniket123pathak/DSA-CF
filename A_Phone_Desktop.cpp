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
        ll x, y;
        cin >> x >> y;
        ll minSc = 0;
        ll rem = 0;
        if (x == 0 && y!=0)
        {
            if (y % 2 == 0)
            {
                cout << y / 2 << endl;
            }
            else
            {
                cout << y / 2 + 1 << endl;
            }
            return;
        }

        if (y == 0 && x!=0)
        {
            if (x % 15 == 0)
            {
                cout << x / 15 << endl;
            }
            else
            {
                cout << x / 15 + 1 << endl;
            }
            return;
        }

        if (y % 2 == 0)
        {
            minSc += y / 2;
            rem = minSc * 7;
        }
        else
        {
            minSc += (y / 2) + 1;
            rem = (minSc - 1) * 7 + (11);
        }

        if (x <= rem)
        {
            cout << minSc << endl;
            return;
        }

        x = x - rem;

        if (x % 15 == 0)
        {
            x = x / 15;
        }
        else
        {
            x = x / 15 + 1;
        }

        cout << minSc + x << endl;
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