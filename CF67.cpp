#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void solve()
    {
        long double n;
        long long i;
        cin >> n;
        vector<long long> v((int)n);
        for (i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        if (n == 1)
        {
            cout << "Yes\n";
            return;
        }

        long long index1 = v[0], newIndex = 0;

        sort(v.begin(), v.end());

        long long medianIndex = ceil((double)n / (double)2) - 1;

        for (i = 0; i < n; i++)
        {
            if (index1 == v[i])
            {
                newIndex = i;
            }
        }

        long long diff = medianIndex - newIndex, count = 0;

        if (diff == count)
        {
            cout << "Yes\n";
            return;
        }

        if (diff > 0)
        {
            for (i = 0; i < n; i++)
            {
                if (abs(v[i]) > index1)
                {
                    count++;
                }
            }
            if (count >= diff)
            {
                cout << "Yes\n";
                return;
            }
            else
            {
                cout << "NO\n";
                return;
            }
        }
        else
        {
            for (i = 0; i < n; i++)
            {
                if (abs(v[i]) < index1)
                {
                    count++;
                }
            }
            if (count >= abs(diff))
            {
                cout << "Yes\n";
                return;
            }
            else
            {
                cout << "NO\n";
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