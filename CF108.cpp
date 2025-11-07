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
        }
        long long count = 0;
        i=0;
        long long x = 2;
        while(i<n){
            if(a[i]!=0){
                i++;
                count++;
                while(a[i]!=0 && i<n){
                    i++;
                }
            }
            else{
                i++;
            }
        }
        cout <<min(x,count)<< endl;
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