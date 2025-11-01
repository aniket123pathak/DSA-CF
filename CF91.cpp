#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
            long long n,i;
            cin>>n;
            if(n==2){
                cout<<"NO\n";
                return;
            }
            if(n%2!=0){
                cout<<"YES\n";
                return;
            }
            while(n!=1){
                if(n%2==0){
                    n/=2;
                }
                else{
                    cout<<"YES\n";
                    return;
                }
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