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
            for(i=n;i>=1;i--){
                cout<<i<<" ";
            }
            cout<<n<<" ";
            for(i=1;i<n;i++){
                if(i==n-1){
                    cout<<i<<endl;
                    return;
                }
                cout<<i<<" ";
            }
            cout<<endl;
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