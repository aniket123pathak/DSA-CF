#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void solve()
    {
        long long n, c, i, j, coin = 0;
        cin >> n >> c;
        vector<long long> v(n), m(0);
        for (i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] <= c)
            {
                m.push_back(v[i]);
            }
        }
        coin = n - m.size();
        long long ms = m.size();
        while (ms > 0)
        {
            sort(m.begin(), m.end());
            if (m[ms - 1] > c)
            {
                coin++;
            }
            m.pop_back();
            ms = m.size();
            for (j = 0; j < m.size(); j++)
            {
                m[j] *= 2;
                if (m[j] > c)
                {
                    coin++;
                    m.erase(m.begin() + j);
                }
            }
        }
         cout << coin << endl;
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