#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void solve()
    {
        long long n, i, countOdd = 0, countEven = 0;
        cin >> n;
        vector<long long> t(n);
        for (i = 0; i < n; i++)
        {
            cin >> t[i];
            if (t[i] % 2 == 0)
                countEven++;
            else
                countOdd++;
        }

        if (countEven == 0)
        {
            for (i = 0; i < n; i++)
            {
                if(i==n-1){
                    cout<<t[i]<<endl;
                    break;
                }
                cout << t[i] << " ";
            }
        }
        else if(countOdd==0){
            for (i = 0; i < n; i++)
            {
                if(i==n-1){
                    cout<<t[i]<<endl;
                    break;
                }
                cout << t[i] << " ";
            }
        }
        else{
            sort(t.begin(),t.end());
            for (i = 0; i < n; i++)
            {
                if(i==n-1){
                    cout<<t[i]<<endl;
                    break;
                }
                cout << t[i] << " ";
            }
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