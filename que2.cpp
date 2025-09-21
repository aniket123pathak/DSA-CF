#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
            long long n,i,a,s=0;
            cin>>n;
            for(i=0;i<n-1;i++){
                cin>>a;
                s=s+a;
            }
            long long sum = (n*(n+1))/2;
            cout<<sum-s<<endl;
        }
};

int main () {
    Solution s;
    s.solve();
    return 0;
}