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
            long long ans = n;
            vector<long long>v(n);
            for(i=0;i<n;i++){
                if(i%2==0){
                    v[i]=(-1);
                }
            }
            if(n%2==0){
                v[n-1]=2;
            }
            else{
                v[n-1]=-1;
            }
            
            for(i=0;i<n-1;i++)
            {
                if(i%2!=0){
                    v[i]=3;
                }
            }

            for(i=0;i<n;i++){
                cout<<v[i]<<" ";
            }
            cout<<"\n";

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