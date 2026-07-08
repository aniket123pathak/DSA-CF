#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,c;
        cin>>n>>c;
        vector<ll>a(n);
        ll sum = 0;
        ll sq = 0;
        for(i=0;i<n;i++){
           cin>>a[i];
           sum+=a[i];
           sq+=(a[i]*a[i]);
        }
        // eqn will be 4*n*w^2 + 4*sum*w + sq-c = 0
        // so we have to find the roots 
        
        __int128 A = 4*n;
        __int128 b = 4*(__int128)sum;
        __int128 C = (__int128)sq - c;
        __int128 discriminant = (b * b) - (4 * A * C);

        long double disc_double = (long double)discriminant;
        ll root = round(sqrtl(disc_double));

        ll x1 = (-b + root) / (2 * A);
        ll x2 = (-b - root) / (2 * A);

        if(x1>0){
            cout<<x1<<endl;
        }
        else{
            cout<<x2<<endl;
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