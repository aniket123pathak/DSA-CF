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
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        vector<ll>b(m);
        for(i=0;i<m;i++){
           cin>>b[i];
        }
        ll arem = 0;
        ll brem = 0;
        for(i=0;i<n;i++){
            if(i==n-1){
                arem+=a[i];
                break;
            }
            arem+=a[i]-a[i+1]+1;
        }
        for(i=0;i<m;i++){
            if(i==m-1){
                brem+=b[i];
                break;
            }
            brem+=b[i]-b[i+1]+1;
        }

        if(arem>=brem){
            cout<<1<<endl;
        }
        else{
            cout<<2<<endl;
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