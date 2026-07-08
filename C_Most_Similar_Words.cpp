#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,m;
        cin>>n>>m;
        vector<string>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        ll ans = 10000000;
        for(i=0;i<n;i++){
            for(ll j=i+1;j<n;j++){                
                ll temp=0;
                for(ll k=0;k<m;k++){
                    temp+=abs(a[i][k]-a[j][k]);
                }
                ans=min(ans,temp);
            }
        }
        cout<<ans<<endl;
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