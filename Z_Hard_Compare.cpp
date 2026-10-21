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
        double l1 = log(a)*b;
        double l2 = log(c)*d;
        if(l1>l2){
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
    s.solve();
    return 0;
}