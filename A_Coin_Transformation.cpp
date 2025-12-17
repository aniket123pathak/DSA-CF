#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
            long long n;
            cin>>n;
            if(n==1||n==2||n==3){
                cout<<"1\n";
                return;
            }
            long long coin = 1;
            while(n>3){
                n/=4;
                coin*=2;
            }
            cout<<coin<<endl;
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