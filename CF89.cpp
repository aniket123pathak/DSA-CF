#include <iostream>
#include <vector>
#include<cmath>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void solve()
    {
        long long n, k, i;
        cin >> n >> k;
        vector<long long> a(n * k);
        for (i = 0; i < n * k; i++)
        {
            cin >> a[i];
        }
        if (k == 1)
        {
            cout<<a[((n+1)/2)-1]<<endl;
            return;
        }
        long long median = (n+1)/2;
        if(n%2==0){
            median+=1;
        }
        long long p2=n*k;
        long long sum=0;
        while(k--){
            p2=p2-(median);
            sum+=a[p2];
        }

        cout<<sum<<endl;
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