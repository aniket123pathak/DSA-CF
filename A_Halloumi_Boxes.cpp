#include <iostream>
#include <vector>
#include <algorithm>
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
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        if(is_sorted(a.begin(),a.end())){
            cout<<"YES\n";
            return;
        }
        if(k==1){
            cout<<"NO\n";
            return;
        }
        cout<<"YES\n";
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