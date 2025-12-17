#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
            long long n,a,b;
            cin>>n>>a>>b;
            if(abs(a-b)%2!=0){
                cout<<"NO\n";
            }
            else{
                cout<<"YES\n";
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