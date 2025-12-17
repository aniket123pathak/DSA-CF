#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void solve()
    {
        long long n, i, j = 1;
        cin >> n;
        vector<long long> a(n), hash(n + 1, 0), hash2(n + 1, 0);
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            hash2[a[i]]++;
        }

        for (i = 0; i < n; i++)
        {
            if (hash[a[i]] == 0)
            {
                cout << a[i] << " ";
                hash[a[i]]++;
            }
            else
            {
                while (j <= n)
                {
                    if (hash2[j] == 0)
                    {
                        cout << j << " ";
                        j++;
                        break;
                    }
                    j++;
                }
            }
        }
        cout << endl;
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