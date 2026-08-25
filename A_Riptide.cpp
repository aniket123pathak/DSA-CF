#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        vector<ll>a(3);
        for(int i=0;i<3;i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        // 1 4 6
        // 2 4 5
        // 3 4 4
        cout<<min(a[2]-a[1],a[1]-a[0])<<endl;
        
        
        
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