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
        ll mx2p = 1;
        while(mx2p*2<=n-1){
            mx2p*=2;
        }
        for(i=n-1;i>=mx2p;i--){
            cout<<i<<" ";
        }
        for(i=0;i<mx2p;i++){
            cout<<i<<" ";
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