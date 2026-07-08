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
        ll ans=0;
        if(a[n-1]>0){
            ans++;
        }
        for(i=n-2;i>=0;i--){
            bool ch = false;
            if(a[i]>0){
                ans++;
                ch = true;
            }
            if(a[i]+a[i+1]>a[i]){
                a[i]=a[i]+a[i+1];
                if(a[i]>0 && !ch){
                    ans++;
                }
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