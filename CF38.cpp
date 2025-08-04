#include<iostream>
using namespace std;

class Solution {
    public:
        void solve ()
            {
                long long  a,b,c,d;
                cin>>a>>b>>c>>d;
                long long gf = min(a,c);
                long long f = min(b,d)-1;

                if(f-gf>=0)
                {
                    cout<<"Flower\n";
                }
                else{
                    cout<<"Gellyfish\n";
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