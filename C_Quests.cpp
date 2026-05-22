#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,k;
        cin>>n>>k;
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        vector<ll>b(n);
        for(i=0;i<n;i++){
           cin>>b[i];
        }
        vector<ll>sum(n);
        sum[0]=a[0];
        for(i=1;i<n;i++){
            sum[i]=sum[i-1]+a[i];
        }
        vector<ll>subMx(n);
        subMx[0]=(b[0]);
        for(i=1;i<n;i++){
            subMx[i]=max(subMx[i-1],b[i]);
        }
        ll ans = 0;
        for(i=0;i<n;i++){
            if(k-i-1>=0){
                ans = max(ans,sum[i]+(k-i-1)*subMx[i]);
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