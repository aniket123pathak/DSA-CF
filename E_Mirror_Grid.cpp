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
        ll n, i, j;
        cin >> n;
        ll count1 = 0;
        ll count0 = 0;
        vector<vector<ll>> a(n, vector<ll>(n));
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == 1)
                {
                    count1++;
                }
                else
                {
                    count0++;
                }
            }
        }
        if(count1==0||count0==0){
            cout<<0<<endl;
            return ;
        }

        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                
            }
        }


       
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