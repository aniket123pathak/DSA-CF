#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        void solve()
        {
            long long n,i,heightD=0;
            cin>>n;
            vector<long long> d(n),l(n),r(n);
            for(i=0;i<n;i++)
            {
                cin>>d[i];
            }
            for(i=0;i<n;i++)
            {
                cin>>l[i]>>r[i];
            }

            for(i=0;i<n;i++)
            {
                

            }

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