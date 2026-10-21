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
        vector<ll>b(n);
        for(i=0;i<n;i++){
           cin>>b[i];
        }
        vector<ll>multiplier(n,0);
        vector<ll>inCaseSum(n,0);
        vector<ll>pf(n);
        pf[0]=b[0];
        for(i=1;i<n;i++){
            pf[i]=pf[i-1]+b[i];
        }
        for(i=0;i<n;i++){
            ll prev = 0;
            if(i>0){
                prev = pf[i-1];
            }
            ll cur = a[i] + prev;
            ll ub = upper_bound(pf.begin()+i,pf.end(),cur)-pf.begin();
            if(ub==n){
                multiplier[i]++;
                continue;
            }
            ll prevSum = 0;
            if(ub>0){
                prevSum=pf[ub-1]-prev;
                multiplier[i]++;
                multiplier[ub]--;
            }
            inCaseSum[ub]+=min(b[ub],a[i]-prevSum);
        }
        vector<ll>pfMulti(n,0);
        pfMulti[0]=multiplier[0];
        for(i=1;i<n;i++){
            pfMulti[i]=pfMulti[i-1]+multiplier[i];
        }

        vector<ll>final(n);
        for(i=0;i<n;i++){
            final[i]=b[i]*pfMulti[i]+inCaseSum[i];
            cout<<final[i]<<" ";
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