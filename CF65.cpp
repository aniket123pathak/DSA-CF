#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution
{
public:
    void solve()
    {
        long long n, i, sum = 0, max = 0, sumOther = 0;
        long double d = 0;
        long double px, py, fpx, fpy;
        cin >> n >> px >> py >> fpx >> fpy;
        vector<long long> v(n);
        for (i = 0; i < n; i++)
        {
            cin >> v[i];
            sum += v[i];
        }
        d = sqrt(((px - fpx) * (px - fpx)) + ((py - fpy) * (py - fpy)));
        if (n == 1)
        {
            if (sum == d)
            {
                cout << "yes\n";
                return;
            }
            cout << "No\n";
            return;
        }
        if (n == 2 && px == fpx && py == fpy)
        {
            if (v[0] == v[1])
            {
                cout << "Yes\n";
                return;
            }
            else
            {
                cout << "No\n";
                return;
            }
        }
        if (d - (int)d > 0 || d > sum)
        {
            cout << "No\n";
            return;
        }

        v.push_back(d);
        sort(v.begin(), v.end());
        max = v[n - 1];
        sumOther = sum - max;
        if (px == fpx && py == fpy)
        {
            if (max <= sumOther)
            {
                cout << "Yes\n";
                return;
            }
            else
            {
                cout << "No\n";
                return;
            }
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