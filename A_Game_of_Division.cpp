#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void solve()
    {
        long long n, k, i, j;
        cin >> n >> k;
        vector<long long> a(n);
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        bool check = true;
        for (i = 0; i < n; i++)
        {
            check = true;
            for (j = 0; j < n; j++)
            {
                if (i != j)
                {
                    if (abs(a[i] - a[j]) % k == 0)
                    {
                        check = false;
                        break;
                    }
                }
            }
            if (check)
            {
                cout << "YES\n";
                cout << i + 1 << endl;
                return;
            }
        }

        cout << "NO\n";
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