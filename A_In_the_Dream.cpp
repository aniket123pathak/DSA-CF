#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll a,b,c,d;
        cin>>a>>b>>c>>d;

        c=c-a;
        d=d-b;
        
        if((max(a,b)-2*min(a,b)>2)||(max(c,d)-2*min(c,d)>2)){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
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