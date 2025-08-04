#include<iostream>
using namespace std;

class Solution {
    public:
        void solve()
        {
            int n;
            cin>>n;
            int min=0;
            int max=1001;
            while(n>0)
            {
                min=n%10;
                if(min<max)
                {
                    max=min;
                }
                n=n/10;
            }
            cout<<max<<"\n";
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