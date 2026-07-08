#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,d;
        cin>>n>>d;
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        sort(a.begin(),a.end());
        ll mx = n-1;
        ll mn = 0;
        ll ans = 0;
        while(mn<=mx){
            ll req = d/a[mx];
            if(mn+req<=mx){
                ans++;
                mn+=req;
                mx--;
            }
            else{
                break;
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
   
    
        s.solve();
    
    return 0;
}