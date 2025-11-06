#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void solve()
    {
        long long n, i, j;
        cin >> n;
        vector<long long> a(n);

        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        if (n == 1)
        {
            cout << "0\n";
            return;
        }
        long long count = 0;

        for (i = n - 1; i > 0; i--)
        {
            while (a[i] <= a[i - 1])
            {
                if (a[i] == 0 )
                {
                    cout << "-1\n";
                    return;
                }
                a[i - 1] /= 2;
                count++;
            }
        }
        cout << count << endl;
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