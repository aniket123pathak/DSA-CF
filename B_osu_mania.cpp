#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i;
        cin>>n;
        vector<vector<char>>a(n,vector<char>(4));
        for(i=0;i<n;i++){
            for(ll j = 0;j<4;j++){
                cin>>a[i][j];
            }
        }
        for(i=n-1;i>=0;i--){
            for(ll j = 0;j<4;j++){
                if(a[i][j]=='#'){
                    cout<<j+1<<" ";
                    break;
                }
            }
        }
        cout<<endl;
        
        return;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution s;
    int tc;
    cin >> tc;
    while (tc-- > 0)
    {
        s.solve();
    }
    return 0;
}