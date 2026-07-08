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
        if(n<=6){
            cout<<"NO\n";
            return;
        }
        for(i=2;1+i+(i*i)<=n;i++){
            ll k = i;
            ll ans = 1+k;
            vector<ll>powOfK;
            ll cur = 1;
            while(cur<=n){
                powOfK.push_back(cur);
                cur=cur*k;
            }
            ll j=2;
            ll mnSnowFlakeOfSizeK = 1 + ( k * ( ans ) );
            while(mnSnowFlakeOfSizeK<=n){
                if(mnSnowFlakeOfSizeK==n){
                    cout<<"YES\n";
                    return;
                }
                ans+=powOfK[j];
                mnSnowFlakeOfSizeK = 1 + ( k * ( ans ) );
                j++;  
            }
        }
        cout<<"NO\n";
        
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