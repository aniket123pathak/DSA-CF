#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:

    bool check(ll am,ll x){
        return am<=x;
    }

    ll BS(vector<ll>& a,ll val){
        ll low = 0;
        ll high = a.size()-1;
        ll ans = 0;
        while(low<=high){
            ll mid = low+(high-low)/2;

            if( check(a[mid],val)){
                ans = mid+1;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

        return ans;
    }

    void solve()
    {
        ll n,i,k;
        cin>>n>>k;
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        vector<ll>q(k);
        for(i=0;i<k;i++){
           cin>>q[i];
        }

        for(i=0;i<k;i++){
            cout<<BS(a,q[i])<<endl;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution s;
    s.solve();
    return 0;
}