#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long kad(vector<long long>& array)
    {
        long long sum = array[0];
        long long best = array[0];
        for (long long k = 1; k < array.size(); k++)
        {
            sum = max(array[k], sum + array[k]);
            best = max(best, sum);
        }
        return best;
    }

    void solve()
    {
        long long n, k, i;
        cin >> n >> k;
        vector<long long> a(n),sumArr(n);
        for (i = 0; i < n; i++){
            cin >> a[i];
            sumArr[0]=a[0];
            if(i>0)
                sumArr[i]+=sumArr[i-1]+a[i];
        }
        vector<long long> b(n);
        for (i = 0; i < n; i++)
            cin >> b[i];
        if (k % 2 == 0)
        {
            cout << kad(a) << endl;
            return;
        }
        if(n==1){
            cout<<a[0] + b[0]<<endl;
            return;
        }
        vector<long long>dp1(n),dp2(n);

        long long sum = a[0];
        long long best = a[0];
        dp1[0]=a[0];
        for (long long k = 1; k < a.size(); k++)
        {
            sum = max(a[k], sum+a[k]);
            dp1[k]=sum;
        }

        dp2[0]=a[0]+b[0];

        for(i=1;i<a.size();i++){
            long long max1 = a[i]+b[i];
            long long max2 = max(dp1[i-1]+max1,max1);
            dp2[i]=max(dp2[i-1]+a[i],max2);
        }

        cout << *max_element(dp2.begin(),dp2.end()) << endl;


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