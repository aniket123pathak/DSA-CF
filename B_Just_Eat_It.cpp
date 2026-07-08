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
        ll tsty = 0;
        for(i=0;i<n;i++){
           cin>>a[i];
           tsty += a[i];
        }
        ll ans1 = 0;
        ll ans2 = 0;
        ll mxSum = INT64_MIN;
        ll curSum = 0;
        for(i=1;i<n;i++){
            curSum+=a[i];
            mxSum=max(curSum,mxSum);
            if(curSum<0){
                curSum=0;
            }
        }
        ans1 = mxSum;

        mxSum = INT64_MIN;
        curSum = 0;
        for(i=0;i<n-1;i++){
            curSum+=a[i];
            mxSum=max(curSum,mxSum);
            if(curSum<0){
                curSum=0;
            }
        }
        ans2 = mxSum;

        ll ans = max(ans1,ans2);

        if(tsty>ans){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
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