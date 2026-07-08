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
        ll mx = 0;

        for(i=0;i<n-1;i++){
            mx=max(mx,a[i]-a[i+1]);
        }
        for(i=0;i<n-1;i++){
            if(a[i]>a[i+1]){
                a[i+1]+=mx;
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