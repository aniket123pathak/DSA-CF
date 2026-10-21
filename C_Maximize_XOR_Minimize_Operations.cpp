#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        // we can do this in logn such that we have to increse the y to next power of 2 and and 
        // either we have to find that max possibe=le power of 2 in x should be decrese by 1 or y should be increse by 1 so tha t we can get ur exor maximum
        ll n,x,y,i;
        cin>>x>>y;
        ll curLimit = x+y;
        vector<ll>pc(30);
        pc[0]=1;
        for(i=1;i<31;i++){
            pc[i]=2*pc[i-1];
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