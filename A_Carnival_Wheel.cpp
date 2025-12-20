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
            if(a==0){

            }

            long long maxP = INT64_MIN;
            for(int i=1;i<100000;i++){
                maxP=max(maxP,(a+i*b)%n);
            }
            cout<<maxP<<endl;
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