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
        ll curLen = 0;
        ll time = 0;
        for (i = 0; i < n; i++)
        {
            if (s[i] == '#')
            {
                curLen++;
            }
            else
            {
                if (curLen % 2 == 0)
                {
                    time = max(time, curLen / 2);
                }
                else
                {
                    time = max(time, (curLen + 1) / 2);
                }
                curLen = 0;
            }
        }
        if (curLen % 2 == 0)
        {
            time = max(time, curLen / 2);
        }
        else
        {
            time = max(time, (curLen + 1) / 2);
        }

        cout << time << endl;

        return;
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