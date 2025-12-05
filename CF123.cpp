#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
            long long n,k1=0,i,k2=0;
            cin>>n;
            vector<long long>a(n),b(n);

            for(i=0;i<n;i++){
                cin>>a[i];
            }
            for(i=0;i<n;i++){
                cin>>b[i];
            }
            long long nextK1 = 0;
            for(int i=0;i<n;i++){
                nextK1 = max(k1 - a[i], b[i] - k2);
                k2 = min(k2 - a[i], b[i] - k1);
                k1=nextK1;
               
            }
            cout<<k1<<endl;
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