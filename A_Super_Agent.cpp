#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        vector<string>grid(3);
        for(ll i=0;i<3;i++){
            cin>>grid[i];
        }
        bool isSymmetric=true;
        for(ll i=0;i<3;i++){
            for(ll j=0;j<3;j++){
                if(grid[i][j]!=grid[2-i][2-j]){
                    isSymmetric=false;
                }
            }
        }
        if(isSymmetric){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
        return;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution s;
    
        s.solve();
    
    return 0;
}