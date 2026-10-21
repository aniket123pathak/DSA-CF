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
        vector<pair<ll,ll>>a(n);
        for(i=0;i<n;i++){
           cin>>a[i].first;
           cin>>a[i].second;
        }

        ll l = 0;
        ll r = 1e9;
        ll ans = INT64_MAX;
        while(l<=r){
            ll mid = l+(r-l)/2;
            ll lMax = 0;
            ll rMax = 0;
            ll k = mid;
            bool check = true;
            for(i=0;i<n;i++){
                ll reqL = a[i].first;
                ll reqR = a[i].second;
                ll curMaxL = max(0LL,lMax-k);
                ll curMaxR = rMax + k;
                if((curMaxR<reqL)||(curMaxL>reqR)){
                    check = false;
                    break;
                }
                lMax = max(curMaxL,reqL);
                rMax = min(curMaxR,reqR); 
            }

            if(check){
                ans = min(ans,k);
                r = mid-1;
            }
            else{
                l =mid+1;
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