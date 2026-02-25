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
        ll n;
        cin>>n;

        if(n%2==0){
            cout<<n/2<<" "<<n/2<<endl;
            return;
        }

        vector<ll>factors;

        for(ll i=2;i*i<=n;i++){
            if(n%i==0){
                factors.push_back(i);
                factors.push_back(n/i);
            }
        }

        if(factors.size()==0){
            cout<<1<<" "<<n-1<<endl;
            return;
        }
        ll x =*max_element(factors.begin(),factors.end());
        cout<<x<<" "<<n-x<<endl;
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