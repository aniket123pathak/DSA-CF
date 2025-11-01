#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

class Solution {
    public:
        void solve()
        {
            long double n,x,sum=0;
            long long i;
            long long max=0,min=0;
            cin>>n>>x;
            vector<long double>a(n);
            for(i=0;i<n;i++){
                cin>>a[i];
                sum+=a[i];
                max+=ceil(a[i]/x);
            }
            min=ceil(sum/x);
            cout<<min<<" "<<max<<endl;

        }
};

int main () {
    Solution s;
    int tc;
    cin>>tc;
    while(tc-->0)
    {
        s.solve();
    }
    return 0;
}