#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,k;
        cin>>n>>k;
        ll sum = 0;
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
           sum+=a[i];
        }
        if(sum%2!=0){
            cout<<"YES\n";
            return;
        }

        if(k*n%2==0){
            cout<<"YES\n";
            return ;
        }
        cout<<"NO\n";
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