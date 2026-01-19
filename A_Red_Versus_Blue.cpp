#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define v(a, n) vector<long long> a(n)
#define fin(i, x, n, a)     \
    for (i = x; i < n; i++) \
    cin >> a[i]

/*
15 17 5 =>3

_ B _ B _ B _ B _ B _

*/

class Solution
{
public:
    void solve()
    {
        ll n, r, b, i;
        cin >> n >> r >> b;
        ll gap = b + 1;
        ll div = r / gap;
        ll rem = r % gap;

        while (b != 0)
        {
            for (i = 0; i < div; i++)
            {
                cout << "R";
            }
            if (rem > 0)
            {
                cout << "R";
                rem--;
            }
            cout << "B";
            b--;
        }

        for (i = 0; i < div; i++)
        {
            cout << "R";
        }
        if (rem > 0)
        {
            cout << "R";
            rem--;
        }

        cout << "\n";
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