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
        ll n,i,x;
        cin >> n>>x;
        vector<ll> a(n);
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<ll> b(n);
        for (i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        vector<ll> c(n);
        for (i = 0; i < n; i++)
        {
            cin >> c[i];
        }
        //so all unset bits from x must be unset if such occurs start with anothe stack and check until failure 
        ll ck = 0;

        for (i = 0; i < n; i++)
        {
            if ((a[i] | x) == x)
            {
                ck |= a[i];
            }
            else
            {
                break;
            }
        }
        for (i = 0; i < n; i++)
        {
            if ((b[i] | x) == x)
            {
                ck |= b[i];
            }
            else
            {
                break;
            }
        }

        for (i = 0; i < n; i++)
        {
            if ((c[i] | x) == x)
            {
                ck |= c[i];
            }
            else
            {
                break;
            }
        }

        if (ck == x)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
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