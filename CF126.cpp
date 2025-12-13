#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void solve()
    {
        long long n, i, count1 = 0, count0 = 0;
        cin >> n;
        string a;
        cin >> a;
        for (i = 0; i < n; i++)
        {
            if (a[i] == '1')
            {
                count1++;
            }
        }
        if (count1 == 1)
        {
            cout << n - count1 << endl;
            return;
        }
        if (count1 == n)
        {
            cout << "0" << endl;
            return;
        }

        long long conti0 = 1, temp = 0, tempLast = 0, tempFirst = 0;
        for (i = n - 1; i >= 0; i--)
        {
            if (a[i] == '0')
            {
                tempLast++;
            }
            else
            {
                break;
            }
        }
        for (i = 0; i < n; i++)
        {
            if (a[i] == '0')
            {
                tempFirst++;
            }
            else
            {
                break;
            }
        }
        conti0 = tempFirst + tempLast;
        for (i = 0; i < n; i++)
        {
            if (a[i] == '0')
            {
                temp++;
            }
            else
            {
                conti0 = max(conti0, temp);
                temp = 0;
            }
        }

        cout << conti0 << endl;
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