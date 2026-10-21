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
        if(a==0 && c==0){
            cout<<0<<endl;
            return ;
        }
        if(a==0 || c==0){
            cout<<1<<endl;
            return;
        }
        if(a==b && c==d){
            cout<<0<<endl;
        }
        // 3.    6
        // 100.  25
        ll mxd = max(b,d);
        ll mnd = min(b,d);

        
        
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