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
        pf[0]=a[0];
        for(i=1;i<n;i++){
            pf[i]=pf[i-1]+a[i];
        }
        sort(a.begin(),a.end());
        vector<ll>pfSrt(n);
        pfSrt[0]=a[0];
        for(i=1;i<n;i++){
            pfSrt[i]=pfSrt[i-1]+a[i];
        }
        ll m;
        cin>>m;
        for(i=0;i<m;i++){
            ll type;
            cin>>type;
            ll l,r;
            cin>>l>>r;
            if(type==1){
                ll tot = pf[r-1];
                ll rm = 0;
                if(l>1){
                    rm = pf[l-2];
                }
                cout<<tot-rm<<endl;
            }
            else{
                ll tot = pfSrt[r-1];
                ll rm = 0;
                if(l>1){
                    rm = pfSrt[l-2];
                }
                cout<<tot-rm<<endl;
            }
        }

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