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
        // 1 2 4 8 16 32 64 128 256 512 1024 2048
        //.  1 2 3 4  5.  6  7   8.  9.  10.  11

        ll money = pow(2,n-(k-1)) + (k-1)*2;
        cout<<money<<endl;
        
        
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