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
        vector<ll>b(n);
        for(i=0;i<n;i++){
           cin>>b[i];
        }
        vector<ll> cntA(2*n+1,0);
        vector<ll> cntB(2*n+1,0);

        ll cur= 1;
        for (ll i = 1; i < n; i++) {
            if (a[i]==a[i-1]) {
                cur++;
            } 
            else{
                cntA[a[i-1]]=max(cntA[a[i-1]],cur);
                cur=1;
            }
        }
        cntA[a[n-1]]=max(cntA[a[n-1]],cur); 

        cur=1;
        for(ll i=1;i<n;i++) {
            if (b[i]==b[i-1]) {
                cur++;
            } 
            else{
                cntB[b[i-1]]=max(cntB[b[i-1]],cur);
                cur=1; 
            }
        }
        cntB[b[n-1]]=max(cntB[b[n-1]],cur);

        ll fans =0;
        for (ll i=1;i<=2*n;i++) {
            fans=max(fans,cntA[i]+cntB[i]);
        }

        cout<<fans<< "\n";
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