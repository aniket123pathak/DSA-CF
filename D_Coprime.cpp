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
        vector<ll>idx(1001,-1);

        for(i=0;i<n;i++){
            idx[a[i]]=i+1;
        }
        ll mxm = -1;

        for(i=1;i<=1000;i++){
            if(idx[i]==-1){
                continue;
            }
            for(ll j=i;j<=1000;j++){
                if(idx[j]!=-1){
                    if(__gcd(i,j)==1){
                        mxm = max(mxm,idx[i]+idx[j]);
                    }
                }
            }
        }
        cout<<mxm<<endl;
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