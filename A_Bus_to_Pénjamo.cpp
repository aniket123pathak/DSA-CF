#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,r;
        cin>>n>>r;
        vector<ll>a(n);
        ll ans = 0;
        ll rem = 0;
        for(i=0;i<n;i++){
            cin>>a[i];
            if(a[i]%2==1){
                rem++;
            }
            ans+=(a[i]/2)*2;
            r -= (a[i]/2);
        }
        // r = 3
        // rem = 4
        // seates = 6
        if(r>=rem){
            ans+=rem;
        }
        else{
            ans+=2*r-rem;
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