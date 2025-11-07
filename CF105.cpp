#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
            long long n,x,i;
            cin>>n;
            vector<long long>a(n);
            for(i=0;i<n;i++){
                cin>>a[i];
            }


            cin>>x;
            long long maxEle = *max_element(a.begin(),a.end());
            long long minEle = *min_element(a.begin(),a.end());

            
            if(x>=minEle && x<=maxEle){
                cout<<"YES\n";
                return;
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