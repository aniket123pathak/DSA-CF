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
        
        for(i=0;i<n;i++){
            ll j = 0;
            vector<ll> mxFromLeft(n);
            mxFromLeft[0]=a[i];
            for(j=1;j<n;j++){
                mxFromLeft[j]=max(mxFromLeft[j-1],a[(i+j)%n]);
            }
            vector<ll>mxFromRight(n);
            mxFromRight[n-1]=a[(i+n-1)%n];
            for (j=n-2;j>=0;j--) {
                mxFromRight[j]=max(mxFromRight[j+1],a[(i+j)%n]);
            }
            ll sm=0;
            for(j=1;j<n;j++) {
                sm+=min(mxFromLeft[j-1],mxFromRight[j]);
            }
            cout<<sm<<" ";
        }
        cout<<endl;
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