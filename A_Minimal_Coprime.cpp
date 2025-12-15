#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
            long long l,r;
            cin>>l>>r;

            if(l==1&&r==1){
                cout<<"1\n";
                return;
            }

            if(l==r){
                cout<<"0\n";
                return ;
            }

            cout<<r-l<<endl;
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