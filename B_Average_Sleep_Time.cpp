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
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        ll weeks = n-k+1;
        ll sumK = 0;
        ll curK = 0;
        for(i=0;i<k;i++){
            curK+=a[i];
        }
        sumK = curK;
        ll cur = 1;
        ll nextK = k;

        while(nextK<n){
            curK = curK-a[cur-1]+a[nextK];
            sumK+=curK;
            nextK++;
            cur++;
        }

        double ans = (long double)sumK/(long double)weeks;
        cout<<fixed<<setprecision(10)<<ans<<"\n";
        

        
        
        return;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution s;
    
        s.solve();
    
    return 0;
}