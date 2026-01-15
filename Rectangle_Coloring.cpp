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
        ll l, w, r, g, b;
        cin >> l >> w >> r >> g >> b;

        vector<ll> side;
        vector<ll> clr;

        side.push_back(l);
        side.push_back(l);
        side.push_back(w);
        side.push_back(w);

        clr.push_back(r);
        clr.push_back(g);
        clr.push_back(b);

        sort(side.begin(), side.end());
        sort(clr.begin(), clr.end());

        ll cost = 0;

        while (!side.empty())
        {
            cost++;
            if (clr.back() >= side.back())
            {
                clr.back() -= side.back();
                side.pop_back();
            }
            else
            {
                side.back() -= clr.back();
                clr.back() = 0;
            }

            sort(clr.begin(), clr.end());
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