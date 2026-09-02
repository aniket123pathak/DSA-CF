#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    
    ll dp[20][2][11][2];

    ll shatShut(ll i,bool tight,ll prev,bool lz,string& s,ll& n){
        if(i==n){
            return 1;
        }
        if(dp[i][tight][prev][lz]!=-1){
            return dp[i][tight][prev][lz];
        }
        ll ub = 9;
        if(tight){
            ub = s[i]-'0';
        }
        ll ans = 0;
        for(ll num = 0;num<=ub;num++){
            if(prev==num && !lz ){
                continue;
            }
            ll checkLead = false;
            if(lz && num==0){
                checkLead = true;
            }
            ll checkTight = false;
            if(tight && num==ub){
                checkTight = true;
            }
            ans+=shatShut(i+1,checkTight,num,checkLead,s,n);
        }
        return dp[i][tight][prev][lz]=ans;
    }
    ll shatShut2(ll x){
        if(x<0){
            return 0;
        }
        if(x==0){
            return 1;
        }
        string s = to_string(x);
        ll n = s.length();
        memset(dp, -1, sizeof(dp));
        return shatShut(0,1,10,1,s,n);
    }
    void solve()
    {
        ll a,b;
        cin>>a>>b;
        ll ans1 = shatShut2(a-1);
        ll ans2 = shatShut2(b);
        cout<<ans2-ans1;
        return;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution s;
    s.solve();
    return 0;
}