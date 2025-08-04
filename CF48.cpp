#include <iostream>
using namespace std;

class Solution
{
public:
    void solve()
    {
        long long x, k, i, count = 0;
        cin>>x>>k;
        if (x == 2 && k == 1)
        {
            cout << "Yes\n";
            return;
        }
        if (x == 1 && k == 2)
        {
            cout << "Yes\n";
            return;
        }
        if (x % 2 == 0)
        {
            cout << "No\n";
            return;
        }
        for (i = 1; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                count++;
                if (x / i != i)
                {
                    count++;
                }
            }
        }
        if (count == 2 && k == 1)
        {
            cout << "Yes\n";
            return;
        }
        cout<<"No\n";
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