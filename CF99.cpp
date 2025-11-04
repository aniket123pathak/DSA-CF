#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
            long long a,b,c;
            cin>>a>>b>>c;

            
            
            if(a+c==2*b){
                cout<<"YES\n";
                return;
            }

            if(((2*b)-c)%a == 0 && ((2*b)-c) > 0){
                cout<<"YES\n";
                return;
            }

            if(((2*b)-a)%c == 0 && ((2*b)-a)>0 ){
                cout<<"YES\n";
                return;
            }

            if((a+c)%(2*b)==0){
                cout<<"YES\n";
                return;
            }

            cout<<"NO\n";
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