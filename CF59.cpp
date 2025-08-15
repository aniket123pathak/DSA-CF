#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void solve()
    {
        long long n,i, count = 0;
        cin >> n;
        vector<long long> a(n), b(n);
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        for(i=0;i<n;i++)
        {
            if(a[i]<=b[i])
            {
                continue;
            }
            else
            {
                count += a[i]-b[i];
            }
        }
        cout<<count+1<<"\n";

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