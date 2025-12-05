#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void solve()
    {
        long long n, i;
        cin >> n;
        vector<long long> a(n);
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        long long maxm1 = a[n - 1] - a[0];
        long long maxm2 = INT64_MIN;
        for (i = 0; i < n - 1; i++)
        {
            maxm2 = max(maxm2, a[i] - a[i + 1]);
        }

        long long maxm3 = INT64_MIN;
        for(i=1;i<n;i++){
            maxm3=max(maxm3,a[i]-a[0]);
        }
        long long maxm4 = INT64_MIN;
        for(i=0;i<n-1;i++){
            maxm4=max(maxm4,a[n-1]-a[i]);
        }

        cout<<max(max(maxm1,maxm2),max(maxm3,maxm4))<<endl;
  
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