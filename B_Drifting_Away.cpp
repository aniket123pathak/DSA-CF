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
        string a;
        cin >> a;
        n = a.length();
        if (n == 1)
        {
            cout << "1\n";
            return;
        }
        for (i = 0; i < n-1; i++)
        {
            if (a[i] != '<' && a[i + 1] != '>')
            {
                cout << "-1\n";
                return;
            }
        }
        ll countLeft = 0;
        ll countRight = 0 ;
        for (i = 0; i < n; i++)
        {
            if (a[i] == '>')
            {
                countLeft++;
            }
            if (a[i] == '<')
            {
                countRight++;
            }
            
        }
        ll max1 =n - min(countLeft, countRight);
        cout<<max1<<endl;
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