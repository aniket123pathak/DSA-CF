#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void solve()
    {
        long long n, k, i, level = 1;
        ;
        cin >> n >> k;
        vector<int> h(n);
        for (i = 0; i < n; i++)
        {
            cin >> h[i];
        }
        int hk = h[k - 1];
        int Hmax = *max_element(h.begin(), h.end());

        if (hk == Hmax)
        {
            cout << "YES\n";
            return;
        }

        vector<int> v = h;
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());

        int pos = lower_bound(v.begin(), v.end(), hk) - v.begin();
        bool ok = true;
        for (int i = pos; i + 1 < v.size(); ++i)
        {
            if (v[i + 1] - v[i] > hk)
            {
                ok = false;
                break;
            }
        }

        if (ok)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
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