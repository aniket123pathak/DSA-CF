#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
            long long n,i,m;
            cin>>n>>m;
            vector<long long>x(n),y(n);
            for(i=0;i<n;i++){
                cin>>x[i];
                cin>>y[i];
            }
            

            long long peri = 0 ;
            for(i=1;i<n;i++){
                // if(i==n-1){
                //     peri+=x[i]+y[i];
                //     break;
                // }
                peri += 2*x[i]+2*y[i];
            }

            cout<<peri+(4*m)<<endl;
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