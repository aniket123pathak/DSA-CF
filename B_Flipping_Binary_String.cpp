#include <bits/stdc++.h>
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
        string s;
        cin >> s;
        ll count0 = 0; // 1 1 1=?  1 0 0     1 1 1 1=> 1 0 0  => 0 0 0 1 1

        for (i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                count0++;
            }
        }
        if (count0 == n)
        {
            cout << 0 << endl;
            return;
        }
        ll count1 = n - count0;

        if (count1 % 2 == 0)
        {
            cout << count1 << endl;
            for (i = 0; i < n; i++)
            {
                if (s[i] == '1')
                {
                    cout << i + 1 << " ";
                }
            }
            cout << endl;
            return;
        }
        if (count0 % 2 != 0)
        {
            cout << count0 << endl;
            for (i = 0; i < n; i++)
            {
                if (s[i] == '0')
                {
                    cout << i + 1 << " ";
                }
            }
            cout << endl;
            return;
        }
            cout << -1 << endl;
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