#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void solve()
    {
        long long n, i,totSum=0;
        cin >> n;
        vector<long long> a(n);
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            totSum+=a[i];
        }

        sort(a.begin(), a.end());

        vector<long long> odd;
        vector<long long> even;

        for (i = n - 1; i >= 0; i--)
        {
            if (a[i] % 2 == 0)
            {
                even.push_back(a[i]);
            }
            else
            {
                odd.push_back(a[i]);
            }
        }

        if (even.size() == n)
        {
            for (i = 0; i < n; i++)
            {
                cout << "0 ";
            }
            cout << endl;
            return;
        }

        if (odd.size() == n)
        {
            for (i = 0; i < n; i++)
            {
                if (i % 2 == 0)
                {
                    cout << odd[0] << " ";
                }
                else
                {
                    cout << "0 ";
                }
            }
            cout << endl;
            return;
        }

        vector<long long> sum(n);
        sum[0] = odd[0];

        long long j = 0;
        i = 1;


        while (i <= even.size())
        {
            sum[i] = sum[i - 1] + even[j];
            i++;
            j++;
        }

        while (i < n)
        {
            sum[i] = sum[i - 2];
            i++;
        }

        if(totSum%2==0){
            sum[n-1]=0;
        }
    
        for (i = 0; i < n; i++)
        {
            cout << sum[i] << " ";
        }
        cout << endl;
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