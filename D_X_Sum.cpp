#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,m,j;
        cin>>n>>m;
        vector<vector<ll>>a(n,vector<ll>(m,0));
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        vector<ll>leftDig(m+n-1);
        vector<ll>rightDig(m+n-1);

        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                
            }
        }
        /*
        1 2 3 4 5 6 7 8
        1 2 3 4 5 6 7 8
        1 2 3 4 5 6 7 8

        1 2 3
        1 2 3
        1 2 3
        1 2 3
        1 2 3
        1 2 3
        1 2 3
        
        */
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