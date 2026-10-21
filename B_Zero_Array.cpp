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
        ll sum =0;
        for(i=0;i<n;i++){
           cin>>a[i];
           sum+=a[i];
        }
        if(sum%2!=0){
            cout<<"NO\n";
            return;
        }
        ll mx = *max_element(a.begin(),a.end());
        if(sum%2!=0|| mx > sum-mx){
            cout<<"NO\n";
            return;
        }
        cout<<"YES\n";



        
        
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution s;
    s.solve();
    return 0;
}