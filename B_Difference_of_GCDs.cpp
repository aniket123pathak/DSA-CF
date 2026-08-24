#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,l,r;
        cin>>n>>l>>r;
        
        vector<ll>ans(n+1);
        bool check = true;
        ans[1] = l;
        for(i=2;i<=n;i++){
            ll cur = i;
            ll x = l/cur;
            ll now = 0;
            while(now<l){
                now = cur*x;
                x++;
            }
            if(now>r){
                cout<<"NO\n";
                return;
            }
            ans[i]=now;
        }
        cout<<"YES\n";
        for(i=1;i<=n;i++){
            cout<<ans[i]<<" ";
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