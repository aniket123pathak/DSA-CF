#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void solve()
    {
        long long n, k, i, curMex = 0;
        cin >> n >> k; // 1 0
        vector<long long> a(n), hash(n + 2);
        for (i = 0; i < n; i++)
        {
            cin >> a[i]; // 1
            hash[a[i]]++;
        }
        for (i = 0; i <= n; i++)
        {
            if (hash[i] == 0)
            {
                curMex = i;
                break;
            }
        }
        if (curMex == k)
        {
            cout << "0\n";
            return;
        }
        if (curMex > k)
        {
            cout << hash[k]<<endl;
            return;
        }

        long long minCount = 0;

        for (i = curMex; i < k; i++)
        {
            if (hash[i] == 0)
            {
                minCount++;
            }
        }

        cout<<max(hash[k],minCount)<<endl;
        
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