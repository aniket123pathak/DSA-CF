#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void solve()
    {
        long long a, b, x, y, count = 0;
        cin >> a >> b >> x >> y;
        if (a == b)
        {
            cout << "0\n";
            return;
        }
        if (a - b > 1)
        {
            cout << "-1\n";
            return;
        }
        if (a - b == 1)
        {
            if (a % 2 == 1)
            {
                cout << y << endl;
                return;
            }
            else
            {
                cout << "-1\n";
                return;
            }
        }
        if (a == 1)
        {
            count += x;
            a += 1;
        }

        while (a != b)
        {
            if (a % 2 == 0)
            {
                if (x > y)
                    count += y;
                else
                    count += x;

                a += 1;
            }
            else
            {
                count += x;
                a += 1;
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