#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll x,y,k;
        cin>>x>>y>>k;
        // we have to gather the k number of coal first then onlyt we can make the torches with that

        // material required for k torches = k*y + k-1 

        // stick 1 => 2 => 4 => 8 => 3
        // 12 + 2 = 14
        ll stkReq = k*y+k-1;
        ll stkG =x-1; 
		ll cnt = 0;
		cnt+=(stkReq+stkG-1)/stkG;
		cnt+=k;
		cout<<cnt<<endl;

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