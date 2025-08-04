#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void solve()
    {
        int n, i, j;
        cin >> n;
        vector<int> v(n);
        for (i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        sort(v.begin(), v.end());

        if (n == 1)
        {
            cout << "0\n";
            return;
        }
        int count = n;

        for (i = 0; i < n; i++)
        {
            for (j = i; j < n; j++)
            {
                if ((v[i] + v[j]) % 2 == 0)
                {
                    int rem = i + n - 1 - j;
                    if (rem < count)
                    {
                        count = rem;
                    }
                }
            }
        }
        cout << count << "\n";
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
