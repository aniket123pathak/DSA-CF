#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void solve()
    {
        int n;
        cin >> n;

        vector<int> v(n);

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        for (int i = 1; i < n; i++)
        {
            if (abs(v[i] - v[i - 1]) == 5 || abs(v[i] - v[i - 1]) == 7)
            {
            }
            else
            {
                cout << "No\n";
                return;
            }
        }
        cout << "Yes\n";
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