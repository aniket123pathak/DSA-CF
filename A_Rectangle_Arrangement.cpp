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
        ll mx1 = -1;
        ll mx2 = -1;
        for(i=0;i<n;i++){
           ll fr ,sc;
           cin>>fr>>sc;
           mx1 = max(mx1,fr);
           mx2 = max(mx2,sc);
        }

        cout<<2*(mx1+mx2)<<endl;
        
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