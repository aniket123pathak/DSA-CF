#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
            long long n,i;
            cin>>n;
            vector<long long>a(n);
            for(i=0;i<n;i++){
                cin>>a[i];
            }
            long long ans=a[0];
            for(i=1;i<n;i++){
                ans = ans&a[i];
            }
            cout<<ans<<endl;
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