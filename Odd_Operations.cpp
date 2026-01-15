#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
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
        string s = to_string(n);

        if (n % 2 != 0)
        {
            cout << "0\n";
            return;
        }

        if (s.length() == 1 && n % 2 == 0)
        {
            cout << "-1\n";
            return;
        }
        ll x = n;
        bool check = false;

        while (x > 0)
        {
            if ((x % 10) % 2 != 0)
            {
                check = true;
            }
            x /= 10;
        }

        if (check)
        {
            cout << "1\n";
            return;
        }

        x = n;
        vector<ll> rem;
        while (x > 0)
        {
            rem.push_back(x % 10);
            x /= 10;
        }
        
        ll mx = *max_element(rem.begin(),rem.end());
        ll count = 0;
        
        if(mx==rem[0]){
            count=1;
        }

        cout<<count+2<<endl;
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