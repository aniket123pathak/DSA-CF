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
        if(c-d-(a-b)>0){
            cout<<-1<<endl;
            return;
        }
        if(d<b){
            cout<<-1<<endl;
            return;
        }
        ll dis1 = (d-b) + abs(c-(a+(d-b)));
        cout<<dis1<<endl;
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