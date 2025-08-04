#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
            int n,x,mxd=0;
            cin>>n>>x;
            vector<int>v(n);
            for(int i=0;i<n;i++)
            {
                cin>>v[i];
            }
            for(int i=1;i<n;i++)
            {
                if(v[i]-v[i-1]>mxd)
                {
                    mxd=v[i]-v[i-1];
                }
            }
            cout<<max(v[0],max(2*(x-v[n-1]),mxd))<<"\n";
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