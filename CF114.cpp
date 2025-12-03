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
            vector<long long>a(n),b(n);
            for(i=0;i<n;i++){
                cin>>a[i];
            }
            for(i=1;i<n-1;i++){
                if(a[i]==-1){
                    a[i]=0;
                }
            }
            if(a[0]==-1&&a[n-1]==-1){
                a[0]=a[n-1]=0;
            }
            if(a[0]==-1&&a[n-1]!=-1){
                a[0]=a[n-1];
            }
            if(a[0]!=-1&&a[n-1]==-1){
                a[n-1]=a[0];
            }
            cout<<abs(a[n-1]-a[0])<<endl;
            for(i=0;i<n;i++){
                if(i==n-1){
                    cout<<a[i]<<endl;
                    return;
                }
                cout<<a[i]<<" ";
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