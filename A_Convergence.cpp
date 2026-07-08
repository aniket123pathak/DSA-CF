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
        sort(a.begin(),a.end());

        ll midEle = 0;
        ll ans = 0;
        if(n%2==0){
            midEle = a[n/2];
            ll ans1 = 0;
            for(i=0;i<n;i++){
                if(a[i]!=midEle || a[n-1-i]!=midEle){
                    ans1++;
                }
            }
            midEle = a[(n-1)/2];
            ll ans2 = 0;
            for(i=0;i<n;i++){
                if(a[i]!=midEle || a[n-1-i]!=midEle){
                    ans2++;
                }
            }
            ans=min(ans1,ans2);
        }
        else{
            midEle = a[(n-1)/2];
            
            for(i=0;i<n;i++){
                if(a[i]!=midEle || a[n-1-i]!=midEle){
                    ans++;
                }
            }
        }
        cout<<ans/2<<endl;
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