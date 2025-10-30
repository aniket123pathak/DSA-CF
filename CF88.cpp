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
            vector<long long>a(n);
            for(i=0;i<n;i++){
                cin>>a[i];
            }

            for(i=1;i<n-1;i++){
                if(a[i]>a[i-1] && a[i]>a[i+1]){
                    cout<<"YES\n";
                    cout<<i<<" "<<i+1<<" "<<i+2<<endl;
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