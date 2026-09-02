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
        vector<ll>a(n+2);
        a[0]=0;
        for(i=1;i<=n;i++){
           cin>>a[i];
        }
        a[n+1]=1440;
        ll cnt = 0;
        for(i=0;i<n+1;i++){
            if(a[i+1]-a[i]>=240){
                cout<<"YES\n";
                return;
            }
            if(a[i+1]-a[i]>=120){
                cnt++;
            }
        }
        if(cnt>1){
            cout<<"YES\n";
            return;
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