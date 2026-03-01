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
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        // 1 0 1 0 1=> 1 1 // 00000001=>01 111111111111110  0000000000001111111111  11111111111111110 0 0    1111111111100
        // 0 1 0 1 0 1=> 0 1 0 1 => 
        //   1 1 1 1 1 0 0 0 => 1 1 1 1 1
        // 1 ≤ l < r ≤ |a|   always choose 2 or more than 2 bc (l<r)  read read read read properly
        if((a[n-1]==1 && a[0]==0)||(a[n-1]==0 && a[0]==1)||(a[n-1]==1 && a[0]==1)){
            cout<<"Alice\n";
        }
        else{
            cout<<"Bob\n";
        }
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