#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

#define ll long long
#define v(a, n) vector<long long> a(n)
#define fin(i, x, n, a)     \
    for (i = x; i < n; i++) \
    cin >> a[i]

/*
    sort the array b,
    i have to print the n-1 elememts
    last one will be always biggest among all ex.1000000000+1
    smallest in b always first it has to occur n-1 or more times and
    i have to print the number after n-1 numbersmin b
    test case
    3 0 0 -2 0 -2 0 0 -2 -2

    imagin like this
    -2 -2 -2 -2       4
    0 0 0             3
    0 0               2
    3                 1
    1000000000+1

    -2 0 0 3 1000000+1 final a vector


*/
class Solution
{
public:
    void solve()
    {
        ll n, i;
        cin >> n;
        ll m = ((n * (n - 1)) / 2);
        vector<ll> b(m);
        for (i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        sort(b.begin(), b.end());
        ll x = 0;
        for (i=1;i<n;i++)
        {
            cout<<b[x]<<" ";
            x+=n-i;
        }
        cout<<1000000000<<endl;
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