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
        string s;
        cin>>s;
        ll cnt1 = 0;
        ll cnt0 = 0;
        for(i=0;i<n;i++){
            if(s[i]=='1'){
                cnt1++;
            }
            else{
                cnt0++;
            }
        }
        /*
        10 1
        1101011001

        */

       ll total = n;
       ll rem = n - (2*k);

       if(cnt1<rem/2||cnt0<rem/2){
        cout<<"NO\n";
        return;
       }

       cnt1-=rem/2;
       cnt0-=rem/2;

       ll mx = max(cnt1,cnt0);
       ll mn = min(cnt1,cnt0);

       ll mnPair = 0;
       if(mn%2!=0){
        mnPair=(mn-1)/2;
        
       }
       else{
        mnPair=mn/2;
       }
       ll mxPair = 0;
       if(mx%2!=0){
        mxPair=(mx-1)/2;
        
       }
       else{
        mxPair=mx/2;
       }

       if(mnPair+mxPair<k){
        cout<<"NO\n";
        return;
       }

       cout<<"YES\n";

        
        

        
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