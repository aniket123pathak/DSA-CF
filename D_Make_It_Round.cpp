#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,m;
        cin>>n>>m;
        vector<ll>a(10);
        a[1]=10;
        a[2]=5;
        a[3]=10;
        a[4]=5;
        a[5]=4;
        a[6]=5;
        a[7]=10;
        a[8]=5;
        a[9]=10;

        ll firstNonZeroRem = 0;
        ll x = n;
        while(x>0){
            ll rem = x%10;
            if(rem>0){
                firstNonZeroRem = rem;
                break;
            }
            x/=10;
        }

        if(m<a[firstNonZeroRem]){
            cout<<m*n<<endl;
            return;
        }

        ll req = m/a[firstNonZeroRem];
        cout<<n*req*a[firstNonZeroRem]<<endl;


        
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