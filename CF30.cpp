#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void beautiful()
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 1; i < n; i++)
        {
            if (abs(a[i - 1] - a[i]) <= 1)
            {
                cout << 0 << endl;
                return;
            }
        }
        for (int i = 1; i + 1 < n; i++)
        {
            if (a[i - 1] < a[i] && a[i] > a[i + 1])
            {
                cout << 1 << endl;
                return;
            }
            if (a[i - 1] > a[i] && a[i] < a[i + 1])
            {
                cout << 1 << endl;
                return;
            }
        }
        cout << -1 << endl;
    }
};

int main()
{
    Solution s;
    int tc;
    cin >> tc;
    while (tc > 0)
    {
        s.beautiful();
        tc--;
    }
    return 0;
}