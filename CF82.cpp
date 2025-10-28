#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
            long long a,b,c,d;
            cin>>a>>b>>c>>d;
            if(a==b&&b==c&&c==d){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
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