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
        vector<ll>a(n+1);
        for(i=1;i<=n;i++){
           cin>>a[i];
        }

        for(ll i=1;i<=n;i+=2){
            for(ll j=i;j<=n;j*=2){
                for(ll k=i*2;k<=n;k*=2){   
                    if(a[k/2]>a[k]){
                        swap(a[k/2],a[k]);
                    }
                }
            }
        }
        if(is_sorted(a.begin(),a.end())){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
        
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