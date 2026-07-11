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
        vector<ll>hash(m+1,-1);
        for(i=0;i<n;i++){
           ll c;
           ll s;
           cin>>c;
           cin>>s;
           hash[c]=max(hash[c],s);
        }

        for(i=1;i<=m;i++){
            cout<<hash[i]<<" ";
        }
        cout<<endl;
        
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