#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll i=0;
        string s,t;
        cin>>s>>t;
        ll n = s.length();
        ll m = t.length();
        ll cnt = 0;
        while(i<n&&i<m){
            if(s[i]==t[i]){
                cnt++;
            }
            else{
                break;
            }
            i++;
        }

        ll ans = 0;

        if(cnt==0){
            cout<<n+m<<endl;
        }
        else{
            ans = cnt+1;
            ans+=max(n-cnt,(ll)0);
            ans+=max(m-cnt,(ll)0);
            cout<<ans<<endl;
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