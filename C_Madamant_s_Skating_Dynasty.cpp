#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]


class Solution {
public:

long long power(long long base, long long exp) {
    long long res = 1;
    long long mod = 998244353;
    base = base % mod;
    while (exp > 0) {
        // If exp is odd, multiply base with the result
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }
        // Square the base and halve the exponent
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

    void solve()
    {
        ll n,i;
        ll mod = 998244353;
        cin>>n;
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        sort(a.rbegin(),a.rend());
        vector<ll>pf(n);
        pf[0]=a[0];
        for(i=1;i<n;i++){
            pf[i]=pf[i-1]+a[i];
        }
        ll fact = 1;
        for(i=2;i<n;i++){
            fact = (fact*i)%mod;
        }
        ll ans = 0;
        for(i=1;i<n;i++){
            ll bra = (pf[i-1]-((i)*a[i])%mod)%mod;
            bra = (bra + mod)%mod;
            bra = (bra*fact)%mod;
            ll inv = power(i,mod-2);
            bra=(bra*inv)%mod;
            ans=(ans+bra)%mod;
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