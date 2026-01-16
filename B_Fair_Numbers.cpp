#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define v(a, n) vector<long long> a(n)
#define fin(i, x, n, a)     \
    for (i = x; i < n; i++) \
    cin >> a[i]

class Solution
{
public:
    void solve()
    {
        ll n, i;
        cin >> n;

        if (n <= 12)
        {
            cout << n << "\n";
            return;
        }

        bool fair = false;

        while (!fair)
        {
            ll x = n;
            vector<ll> digits(10, 0);
            while (x > 0)
            {
                if (x % 10 != 0 && x % 10 != 1)
                {
                    if (digits[x % 10] == 0)
                    {
                        digits[x % 10]++;
                    }
                    if (digits[2] != 0 && digits[3] != 0 && digits[4] != 0 && digits[5] != 0 && digits[6] != 0 && digits[7] != 0 && digits[8] != 0 && digits[9] != 0)
                    {
                        break;
                    }
                }
                x = x / 10;
            }
            bool check = true;
            for (i = 1; i < 10; i++)
            {
                if (digits[i] != 0 && n % i != 0)
                {
                    check = false;
                    break;
                }
            }
            if (check)
            {
                cout << n << "\n";
                return;
            }
            else
            {
                n++;
            }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution s;
    int tc;
    cin >> tc;
    while (tc-- > 0)
    {
        s.solve();
    }
    return 0;
}