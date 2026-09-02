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
        // 1 2 5 7 9
        // 
        if(n%2!=0){
            cout<<"NO\n";
            return;
        }
        ll mn = INT64_MAX;
        ll mx = INT64_MIN;
        for(i=0;i<n;i++){
            if(i%2==0){
                mn =min(mn,a[i]);
            }
            else{
                mx = max(mx,a[i]);
            }
        }

        if(mx+1>=mn){
            cout<<"NO\n";
            return;
        }
        cout<<"YES\n";

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