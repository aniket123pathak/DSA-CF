#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,a,b;
        cin>>n>>a>>b;
        vector<ll>k(n);
        for(i=0;i<n;i++){
           cin>>k[i];
        }
    
        ll firstCase =  a*(k[0]-0);
        ll secondCase = b*(k[0]-a);
        
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