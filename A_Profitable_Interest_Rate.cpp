#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll a,b,i;
        cin>>a>>b;

        if(b<=a){
            cout<<a<<endl;
            return;
        }
        // a-x >= b-2x
        // 2x-x=b-a
        // x = b-a
        //cout<<min(0,a-x);
        ll diff = b-a;
        cout<<max((ll)0,a-diff)<<endl;

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