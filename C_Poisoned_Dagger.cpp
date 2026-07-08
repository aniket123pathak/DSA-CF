#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,h;
        cin>>n>>h;
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        ll left = 1;
        ll right = h;
        ll ans = 0;
        while(left<=right){
            ll mid = left+(right-left)/2;
            ll curH = h;

            for(i=0;i<n-1;i++){
                curH -= min(mid,a[i+1]-a[i]);
            }
            curH-=mid;
            if(curH<=0){
                right=mid-1;
                ans=mid;
            }
            else{
                left=mid+1;
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