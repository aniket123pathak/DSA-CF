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
        vector<ll>tempA = a;
        sort(tempA.begin(),tempA.end());
        vector<ll>pf(n);
        pf[0]=tempA[0];
        for(i=1;i<n;i++){
            pf[i]=pf[i-1]+tempA[i];
        }
        vector<ll>ans(n);

        ll cnt = 0;

        for(i = 0; i < n; i++) {
            ll idx = upper_bound(tempA.begin(), tempA.end(), a[i]) - tempA.begin();
            ll ele = pf[idx-1]; 
            ll cnt = idx;         
            ll ub = cnt;
            while(cnt < n) {
                ub=upper_bound(tempA.begin(), tempA.end(), ele) - tempA.begin();
                if(ub==cnt) {
                    break;
                }
                cnt=ub;
                ele=pf[ub - 1];
            }
            
            ans[i]=ub-1; 
        }
        for(i=0;i<n;i++){
            cout<<ans[i]<<" ";
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