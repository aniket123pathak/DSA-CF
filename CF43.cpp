#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void solve()
    {
        
        int n, i;
        cin >> n;
        int count0 = 0;
        int count1 = 0;
        vector<int> a(n);
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 1)
            {
                count1++;
            }
        }
        if (count1 == n)
        {
            cout << "Yes\n";
            return ;
        }

        for (i = 1; i < n; i++)
        {
            if (a[i] == 0 && a[i - 1] == 0)
            {
                cout << "Yes\n";
                return ;
            }
        }

        cout << "No\n";
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