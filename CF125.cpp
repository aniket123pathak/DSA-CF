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
        vector<long long> a(n);
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        long count = 0;

        long long cur = 0;
        long long next = 1;

        while (next < n)
        {
            if (a[cur] > a[next])
            {
                count++;
                next++;
            }
            else
            {
                cur = next;
                next++;
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