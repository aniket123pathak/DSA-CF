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
        ll n,i,q;
        cin>>n>>q;
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        vector<ll>x(q);
        for(i=0;i<q;i++){
           cin>>x[i];
        }

        vector<long long> pow2(31);
        pow2[0]=1;
        for(i=1;i<=30;i++){
            pow2[i]=pow2[i-1]*2;
        }
      
        long long mx = INT16_MAX;

        for(i=0;i<q;i++){
            if(x[i]>=mx)continue;
            for(ll j=0;j<n;j++){
                if(a[j]%pow2[x[i]]==0){
                    a[j]+=pow2[x[i]-1];
                }
            }
            mx=x[i];
        }

        for(i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        
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