#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i;
        cin>>n;
        ll ans = 0;
        ll mx=n/2;
    
        for(i=1;i<=mx;i++) {
            ll nu=n/i; 
            ll next_D = N / current_val; 
        
            if (next_D > limit) {
                next_D = limit;
            }
        
            long long count_in_block = next_D - D + 1;
            total_pairs += count_in_block * (current_val - 1);
        
            D = next_D + 1;
        }
    
    cout << total_pairs << "\n";
        
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