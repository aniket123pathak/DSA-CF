#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
            long long n;
            cin>>n;
            string a,t;
            cin>>a>>t;
            vector<long long>v(300);
            vector<long long>k(300);

            for(int i = 0 ;i<n;i++){
                v[a[i]]++;
                k[t[i]]++;
            }

            for(int i = 0 ;i<300;i++){
                if(v[i]!=k[i]){
                    cout<<"NO\n";
                    return;
                }
            }

            cout<<"YES\n";
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