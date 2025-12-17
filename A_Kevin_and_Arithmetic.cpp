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
        vector<long long> a(n), e, o;
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] % 2 == 0)
                e.push_back(a[i]);
            else
                o.push_back(a[i]);
        }

        long long sum = 0;
        long long count = 0;

        if (!e.empty())
        {
            sum += e.back();
            e.pop_back();
            if (sum % 2 == 0)
            {
                count++;
            }
            while (sum % 2 == 0)
            {
                sum /= 2;
            }
        }
        while (!o.empty())
        {
            sum += o.back();
            o.pop_back();
            if (sum % 2 == 0)
            {
                count++;
            }
            while (sum % 2 == 0)
            {
                sum /= 2;
                
            }
        }

        while (!e.empty())
        {
            sum += e.back();
            e.pop_back();
            if (sum % 2 == 0)
            {
                count++;
            }
            while (sum % 2 == 0)
            {
                sum /= 2;
                
            }
        }
        cout << count << endl;
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