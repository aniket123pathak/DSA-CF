#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll a,b;
        cin>>a>>b;
        ll ans = 0;
        ll diff = max(a,b)-min(a,b);

        ll x = 10;

        while(diff>0 && x>0){
            if((diff/x)!=0){
                ans+=diff/x;
                diff=diff%x;
            }
            x--;
        }
        cout<<ans<<endl;
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