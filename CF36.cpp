#include <iostream>
using namespace std;

class Solution
{
public:
    void solve()
    {
        long long n;
        cin>>n;
        long long arr[2*100000],i;
        for(i = 0;i<n;i++)
        {
            cin>>arr[i];
        }
        if(n==1)
        {
            cout<<arr[0]<<"\n";
            return ;
        }
        int sum=0;
        for(i=1;i<n;i++)
        {
            arr[i]=arr[i]+arr[i-1]-1;
        }
        cout<<arr[n-1]<<"\n";

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