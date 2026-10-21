#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]
ll mod = 1e9+7;
ll mx = 40005;
vector<ll> dp(mx,0);

void solve(){
    ll n,i;
    cin>>n;
    cout<<dp[n]<<endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    vector<ll>a;
        for(ll i=1;i<=40000;i++){
            vector<ll>temp;
            ll x = i;
            while(x>0){
                temp.push_back(x%10);
                x/=10;
            }
            ll l = 0;
            ll r = (ll)temp.size()-1;
            bool check = true;
            while(l<r){
                if(temp[l]!=temp[r]){
                    check=false;
                    break;
                }
                l++;
                r--;
            }
            if(check){
                a.push_back(i);
            }
        }
        dp[0]=1;
        for(ll coin:a) {
            for (ll sum = coin; sum < mx; sum++) {
                dp[sum]=(dp[sum]+dp[sum-coin])% mod;
            }
        }
    while (tc-- > 0)
    {
        solve();
    }
    return 0;
}