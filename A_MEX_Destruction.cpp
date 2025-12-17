#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
            long long n,i,count0=0,count01=0;
            cin>>n;
            vector<long long>a(n);
            for(i=0;i<n;i++){
                cin>>a[i];
                if(a[i]==0){
                    count0++;
                }
            }
            if(count0==n){
                cout<<"0\n";
                return;
            }
            if(count0==0){
                cout<<"1\n";
                return;
            }
            if(n==1){
                cout<<"1\n";
                return;
            }
            i=0;
            while(i<n){
                if(a[i]==0){
                i++;
                }
                else{
                    break;
                }
            }
            while(n>0){
                
                if(a[n-1]==0){
                n--;
                }
                else{
                    break;
                }
            }
            for(int j=i;j<n;j++){
                if(a[j]==0){
                    count01++;
                }
            }
            if(count01==0){
                cout<<"1\n";
                return;
            }
            else{
                cout<<"2\n";
                return;
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