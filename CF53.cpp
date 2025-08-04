#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
            int n,k;
            cin>>n>>k;
            vector<long long>v(n);
            for(int i=0;i<n;i++)
            {
                cin>>v[i];
            }
            if(k>1){
                cout<<"YES\n";
                return;
            }
            else{
                for(int i = 1;i<n;i++)
                {
                    if(v[i-1]>v[i])
                    {
                        cout<<"NO\n";
                        return;
                    }
                }
                cout<<"YES\n";
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