#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    ll digitSm(ll n) {
        ll sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    void solve()
    {
        ll n, i;
        cin >> n;
        
        ll count = 0;
        for(i = n; i <= n + 100; i++) {
            if(i - digitSm(i) == n) {
                count++;
            }
        }
        
        cout << count << "\n";
        return;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution s;
    ll tc;
    cin >> tc;
    while (tc-- > 0)
    {
        s.solve();
    }
    return 0;
}