#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,a,b,i;
        cin>>n>>a>>b;
        ll ans = 0;
        ll rem = n%3;
        ll div = n/3;

        if(b<=3*a){
            ans+=div*b;
        }
        else{
            ans+=(n-rem)*a;
        }

        if(rem==1){
            if(b<=a){
                ans+=b;
            }
            else{
                ans+=a;
            }
        }
        else if(rem==2){
            if(b<=2*a){
                ans+=b;
            }
            else{
                ans+=2*a;
            }
        }

        cout<<ans<<endl;
        
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