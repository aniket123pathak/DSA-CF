#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout<<'NO'<<endl
#define yes cout<<'YES'<<endl
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,q;
        cin>>n>>q;
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        vector<ll>pfQ(n,0);
        for(i=0;i<q;i++){
            ll l;
            ll r;
            cin>>l>>r;
            pfQ[l-1]++;
            if(r<n){
                pfQ[r]--;
            }
        }
        vector<ll>pf(n,0);
        pf[0]=pfQ[0];
        for(i=1;i<n;i++){
            pf[i]=pf[i-1]+pfQ[i];
        }
        sort(pf.rbegin(),pf.rend());
        sort(a.rbegin(),a.rend());
        ll cst = 0;
        for(i=0;i<n;i++){
            cst+=pf[i]*a[i];
        }
        cout<<cst<<endl;
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