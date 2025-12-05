#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void solve()
    {
        long long n,q,i,j,totalSum = 0;
        cin >> n>>q;
        vector<long long> a(n),dp(n);
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            totalSum+=a[i];
            dp[i]=totalSum;
        }
        for(j=0;j<q;j++){
            long long l,r,k;
            cin>>l>>r>>k;

            long long sum1 = 0;
            if(l>1){
                sum1= dp[r-1]-dp[l-2];
            }
            else{
                sum1 = dp[r-1];
            }
            long long sum2 = (r-l+1)*k;

            long long sum3 = totalSum-sum1+sum2;

            
            if(sum3%2==0){
                cout<<"NO\n";
            }
            else{
                cout<<"YES\n";
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