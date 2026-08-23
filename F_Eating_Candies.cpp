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
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        vector<ll>pf(n);
        vector<ll>pfr(n);
        pf[0]=a[0];
        for(i=1;i<n;i++){
            pf[i]=pf[i-1]+a[i];
        }
        reverse(a.begin(),a.end());
        pfr[0]=a[0];
        for(i=1;i<n;i++){
            pfr[i]=pfr[i-1]+a[i];
        }

        ll ans = 0;
        ll left = 0;
        ll right = 0;
        
        while((left+right+2)<=n){
            if(pf[left]==pfr[right]){
                ans = max(ans,(left+right+2));
                left++;
                right++;
            }
            else if(pf[left]<pfr[right]){
                left++;
            }
            else{
                right++;
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