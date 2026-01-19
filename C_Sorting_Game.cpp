#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define v(a, n) vector<long long> a(n)
#define fin(i, x, n, a)     \
    for (i = x; i < n; i++) \
    cin >> a[i]

/*

1000010101

0000110101
*/
class Solution
{
public:
    void solve()
    {
        ll n, i;
        cin >> n;
        string s;
        cin >> s;

        if (is_sorted(s.begin(), s.end()))
        {
            cout << "Bob\n";
            return;
        }

        ll one = -1;
        ll zero = -1;

        for (i = 0; i < n - 1; i++)
        {
            if (s[i] == '1' && one == -1)
            {
                one = i;
                break;
            }
        }

        int j = one;
        while (j < n && s[j] == '1') {
            j++;
        }

        zero = j;
        while (j < n && s[j] == '0') {
            zero = j;
            j++;
        }

        cout << "Alice  \n";
        cout << "2\n";
        cout << one + 1 << " " << zero+1;
        cout << "\n";
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