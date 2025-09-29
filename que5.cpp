#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void solve()
    {
        long long n, i;
        cin >> n;
        long long count = 0;

        if (n == 1)
        {
            cout << "1" << endl;
            return;
        }

        if (n == 2 || n == 3)
        {
            cout << "NO SOLUTION\n";
            return;
        }

        if (n == 4)
        {
            for (i = 2; i <= n; i += 2)
            {
                cout << i << " ";
            }
            for (i = 1; i <= n; i += 2)
            {
                cout << i << " ";
            }
            cout << endl;
            return;
        }

        for (i = 1; i <= n; i += 2)
        {
            cout << i << " ";
        }
        for (i = 2; i <= n; i += 2)
        {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main()
{
    Solution s;
    s.solve();
    return 0;
}

// 5 -> 1 3 5 2 4