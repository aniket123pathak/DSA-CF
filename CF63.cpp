#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void solve()
    {
        int n, i;
        long long count = 0;
        bool is_sorted = true;
        cin >> n;
        vector<long long> v(n);

        for (i = 0; i < n; i++)
        {
            cin >> v[i];
            if (i > 0)
            {
                if (v[i] <= v[i - 1])
                {
                    is_sorted = false;
                }
            }
        }
        if (is_sorted == true)
        {
            cout << "0\n";
            return;
        }
        if (n == 1)
        {
            cout << "0\n";
            return;
        }
        for (i = n - 1; i > 0; i--)
        {
            while (v[i] <= v[i - 1])
            {
                if (v[i] == 0)
                {
                    cout << "-1\n";
                    return;
                }

                v[i - 1] = v[i - 1] / 2;
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