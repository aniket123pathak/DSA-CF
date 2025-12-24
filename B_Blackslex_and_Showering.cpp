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
        v(a, n);
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }


        ll maxDiff = INT64_MIN;
        ll x;

        for (i = 1; i < n - 1; i++)
        {
            if (abs(a[i + 1] - a[i]) + abs(a[i] - a[i - 1]) > abs(a[i + 1] - a[i - 1]))
            {
                maxDiff = max(maxDiff, abs(a[i + 1] - a[i]) + abs(a[i] - a[i - 1]) - abs(a[i + 1] - a[i - 1]));
                if (maxDiff == abs(a[i + 1] - a[i]) + abs(a[i] - a[i - 1]) - abs(a[i + 1] - a[i - 1]))
                {
                    x = i;
                }
            }
        }

        ll fs1 = 0;
        ll fs2 = 0;

        for (i = 1; i < n - 1; i++)
        {
            fs1 += abs(a[i] - a[i + 1]);
        }

        for (i = 0; i < n - 2; i++)
        {
            fs2 += abs(a[i] - a[i + 1]);
        }

        vector<ll> temp;

        for (i = 0; i < n; i++)
        {
            if (x != i)
            {
                temp.push_back(a[i]);
            }
        }
        ll sk=0;
        for(i=0;i<temp.size()-1;i++){
            sk+=abs(temp[i]-temp[i+1]);
        }
        
        ll min1 = min(fs1,fs2);
        cout<<min(min1,sk)<<endl;

        // for (i = 0; i < n - 1; i++)
        // {
        //     maxDiff = max(maxDiff, abs(a[i + 1] - a[i]));
        // }
        // ll x, y;
        // for (i = 0; i < n - 1; i++)
        // {
        //     if (abs(a[i + 1] - a[i]) == maxDiff)
        //     {
        //         x = i;
        //         y = i + 1;
        //     }
        // }

        // vector<ll>k;
        // vector<ll>z;

        // for(i=0;i<n;i++){
        //     if(i!=x){
        //         k.push_back(a[i]);
        //     }
        //     if(i!=y){
        //         z.push_back(a[i]);
        //     }
        // }
        // ll sumK=0;
        // ll sumZ=0;
        // for(i=0;i<n-2;i++){
        //     sumK+=abs(k[i]-k[i+1]);
        //     sumZ+=abs(z[i]-z[i+1]);
        // }

        // cout<<min(sumK,sumZ)<<endl;
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