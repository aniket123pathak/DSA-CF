#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void solve()
    {
        string a;
        cin >> a;
        long long n = a.length();
        long long i, count0 = 0, count5 = 0;
        long long index0 = 0, index5 = 0;
        long long temp0 = -1, temp5 = -1;
        long long ans0 = INT64_MAX, ans5 = INT64_MAX;
        for (i = n - 1; i > 0; i--)
        {
            if (a[i] == '5')
            {
                index5 = i;
                count5++;
                break;
            }
        }
        for (i = n - 1; i > 0; i--)
        {
            if (a[i] == '0')
            {
                index0 = i;
                count0++;
                break;
            }
        }

        if (count5 > 0)
        {
            for (i = index5 - 1; i >= 0; i--)
            {
                if (a[i] == '2' || a[i] == '7')
                {
                    temp5 = i;
                    break;
                }
            }
            if (temp5 != -1)
            {
                ans5 = (n - 1 - index5) + (index5 - temp5 - 1);
            }
        }

        if (count0 > 0)
        {
            for (i = index0 - 1; i >= 0; i--)
            {
                if (a[i] == '0' || a[i] == '5')
                {
                    temp0 = i;
                    break;
                }
            }
            if (temp0 != -1)
            {
                ans0 = (n - 1 - index0) + (index0 - temp0 - 1);
            }
        }
        cout << min(ans0, ans5) << endl;
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