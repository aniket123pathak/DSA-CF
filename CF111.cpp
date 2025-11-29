#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void solve()
    {
        long long n;
        cin >> n;
        if (n == 1)
        {
            cout << n << endl;
            return;
        }
        if (n == 2)
        {
            cout << "9" << endl;
            return;
        }
        if (n * n - 1 < 4 * n)
        {
            cout << (n * n - 1) + (n * n) + (n * n - 2) + (n * n - 1 - n) << endl;
            return;
        }
        cout<<(n*n-1-n)+(n*n-1-n-1)+(n*n-1-n+1)+(n*n-1)+(n*n-1-n-n)<<endl;
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