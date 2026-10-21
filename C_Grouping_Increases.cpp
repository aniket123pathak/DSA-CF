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
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        vector<ll>a2 = a;
        sort(a2.rbegin(),a2.rend());
        ll cur = 0;
        vector<ll>s,t;
        for(i=0;i<n;i++){
            if(a[i]==a2[cur]){
                s.push_back(a[i]);
                cur++;
            }
            else{
                t.push_back(a[i]);
            }
        }
        ll ans = 0;
        ll sz = t.size();
        for(i=0;i<sz-1;i++){
            if(t[i]<t[i+1]){
                ans++;
            }
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