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
        ll cnt1 = 0;
        ll cnt2 = 0;
        ll cnt0 = 0;
        for(i=0;i<n;i++){
           cin>>a[i];
           if(a[i]==1){
            cnt1++;
           }
           else if(a[i]==2){
            cnt2++;
           }
           else{
            cnt0++;
           }
        }
        ll ans1 = 0;
        if(cnt1>cnt2){
            ans1 = cnt2 + (cnt1-cnt2)/3;
        }
        else{
            ans1 = cnt1 + (cnt2-cnt1)/3;
        }

        cout<<ans1+cnt0<<endl;
        
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