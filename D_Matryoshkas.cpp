#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define ll long long
#define v(a, n) vector<long long> a(n)
#define fin(i, x, n, a)     \
    for (i = x; i < n; i++) \
    cin >> a[i]

/*
    doll sizes should be consecative
    initially min set size will be the maxfrequency of element in input
    and if tber are any gaps in elememts in array then also min set size increses

    2 2 3 4 4 6 6 7 
*/

class Solution
{
public:
    void solve()
    {
        ll n, i;
        cin >> n;
        vector<ll> a(n);
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        map<ll, ll> map;

        for (i = 0; i < n; i++)
        {
            map[a[i]]++;
        }
        ll minSet = 0 ;
        for (const auto &[val,freq] : map)
        {
            minSet+=max((ll)0,map[val]-map[val-1]);
        }

        cout<<minSet<<endl;
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