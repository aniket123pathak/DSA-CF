#include <iostream>
using namespace std;

class Solution
{
public:
    void solve()
    {
        long long  x;
        cin>>x;
        long long z;
        for(long long y = 1; y<=x;y++)
        {
            z=x^y;
            if(x+y>z&&y+z>x&&x+z>y)
            {
                cout<<y<<"\n";
                return;
            }
        }
        cout<<"-1\n";
    }
};

int main()
{
    Solution s;
    int tc;
    cin >> tc;
    while (tc-- >0)
    {
        s.solve();
    }
    return 0;
}