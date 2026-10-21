#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,a,b,c,x,k;
        cin>>n>>k;
        cin>>x>>a>>b>>c;
        vector<ll>arr(n);
        arr[0]=x;
        for(i=1;i<n;i++){
            arr[i]= (a*arr[i-1]+b)%c;
        }
        
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution s;
    s.solve();
    return 0;
}