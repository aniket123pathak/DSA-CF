#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void solve()
    {
        long long n, l, r, i;
        cin >> n >> l >> r;

        vector<long long> a(n), left, right;
        long long sumLeft = 0, sumRight = 0;
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (i = 0; i < r; i++)
        {
            left.push_back(a[i]);
        }

        for (i = l - 1; i < n; i++)
        {
            right.push_back(a[i]);
        }

        sort(left.begin(), left.end());
        sort(right.begin(), right.end());

        for (i = 0; i < r - l + 1; i++)
        {
            sumLeft += left[i];
            sumRight += right[i];
        }
        cout << min(sumLeft, sumRight) << endl;
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
