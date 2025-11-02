#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

class Solution {
    public:
        void solve()
        {
            long long n,i,count1=0,count0=0;
            cin>>n;
            vector<long long>a(n);
            for(i=0;i<n;i++){
                cin>>a[i];
                if(a[i]==1){
                    count1++;
                }
                if(a[i]==0){
                    count0++;
                }
            }

            if(count0==n||count1==0){
                cout<<"0\n";
                return;
            }
            if(count0==0){
                cout<<count1<<endl;
                return;
            }
            long long ans = (long long)(pow(2,count0)+0.5);//pow returns double..
            cout<<(ans*count1)<<endl;
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
