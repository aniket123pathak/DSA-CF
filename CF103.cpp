#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
            long long x,y;
            cin>>x>>y;
            if(x==y || y==1){
                cout<<"-1\n";
                return;
            }
            if(x<y){
                cout<<"2\n";
                return;
            }

            if(x-1>y){
                cout<<"3\n";
                return;
            }

            cout<<"-1\n";

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