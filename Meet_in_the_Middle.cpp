#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,x;
        cin>>n>>x;
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        ll first = n/2;
        ll second = n - first;
        vector<ll>firstHalf;
        for(ll mask = 0;mask<((ll)1<<first);mask++){
            ll sum = 0;
            for(ll j = 0; j<first;j++){
                if(mask & ((ll)1<<j)){
                    sum+=a[j];
                }
            }
            firstHalf.push_back(sum);
        }
        vector<ll>secondHalf;
        for(ll mask = 0;mask<((ll)1<<second);mask++){
            ll sum = 0;
            for(ll j = first ; j<n ; j++){
                if(mask & ((ll)1<<(j-first))){
                    sum+=a[j];
                }
            }
            secondHalf.push_back(sum);
        }
        sort(secondHalf.begin(),secondHalf.end());

        ll sz1 = firstHalf.size();
        ll sz2 = secondHalf.size();
        ll ans = 0;
        for(i=0;i<sz1;i++){
            ll rem = x - firstHalf[i];
            ll lb = lower_bound(secondHalf.begin(),secondHalf.end(),rem)-secondHalf.begin();
            ll ub = upper_bound(secondHalf.begin(),secondHalf.end(),rem)-secondHalf.begin();
            ans+=ub-lb;
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