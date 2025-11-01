#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

class Solution {
    public:
        void solve()
        {
            long long a,b;
            cin>>a>>b;
            if(a==b){
                cout<<"0 0\n";
                return;
            }
            cout<<abs(a-b)<<" ";
            long long x = a%abs(a-b);
            long long min_steps = min(x,(abs(a-b)-x));
            cout<<min_steps<<endl;
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