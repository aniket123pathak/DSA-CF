#include <iostream>
using namespace std;

class Solution
{
public:
    void solve()
    {
        int k;
        cin >> k;

        if (k % 2 == 1)
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