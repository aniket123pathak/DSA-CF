#include <iostream>
#include <vector>
#include <algorithm>
#include<cmath>
using namespace std;

#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

const long long MOD = 1e9 + 7;

class Solution {
public:


    ll pw(ll n,ll k){
        ll ans = 1  ;

        while(k>0){
            ans=(ans*n)%MOD;
            k--;
        }
        return ans;
    }


    void solve()
    {
        ll n,k,i;
        cin>>n>>k;
        
        cout<<pw(n,k)<<"\n";
       
    } 
};

int main() {
    Solution s;
    int tc;
    cin >> tc;
    while (tc-- > 0)
    {
        s.solve();
    }
    return 0;
}