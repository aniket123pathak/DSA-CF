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
            if (a[i] == 1 && i != n - 1)
            {
                a[i]++;
            }
        }
        for (i = 1; i<n; i++)
        {
            if(a[i]%a[i-1]==0){
                a[i]++;
            }
        }

        for (i = 0; i < n; i++)
        {
            if (i == n - 1)
            {
                cout << a[i] << endl;
                return;
            }
            cout << a[i] << " ";
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