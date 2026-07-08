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
        // lets minimize the search space try...
        // find a[i]<i+1 == a[i]<=i
        vector<pair<ll,ll>>refined;
        for(i=0;i<n;i++){
            if(a[i]<=i){
                refined.push_back({a[i],i+1});
            }
        }
        sort(refined.begin(),refined.end());
        ll sz = refined.size();
        ll ans = 0;
        for(i=0;i<sz;i++){
            ll cur = refined[i].second;
            ll left = i+1;
            ll right = sz-1;
            ll mn = sz;
            while(left<=right){
                ll mid = left+(right-left)/2;
                if(refined[mid].first>cur){
                    right = mid-1;
                    mn = mid;
                }
                else{
                    left=mid+1;
                }
            }
            ans+=(sz-mn);
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