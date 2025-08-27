#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void solve()
    {
        long long n;
        cin >> n;
        vector<long long> v(n);
        for (long long i = 0; i < n; ++i)
        {
            cin >> v[i];
        }

        if (v[0] == 1)
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
    long long tc;
    cin >> tc;
    while (tc-- > 0)
    {
        s.solve();
    }
    return 0;
}