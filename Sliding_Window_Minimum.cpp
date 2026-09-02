#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,a,b,c,x,k;
        cin>>n>>k;
        cin>>x>>a>>b>>c;
        vector<ll>arr(n);
        arr[0]=x;
        for(i=1;i<n;i++){
            arr[i]= (a*arr[i-1]+b)%c;
        }
        ll ans = 0;
        ll mn1 = INT64_MAX;
        ll mn2 = INT64_MAX;
        for(i=0;i<k;i++){
            if(arr[i]<mn1){
                mn2 = mn1;
                mn1 = arr[i];
            }
            else if(arr[i]==mn1){
                mn2 = arr[i];
            }
            else if(arr[i]<mn2){
                mn2 = arr[i];
            }
        }
        ans = mn1;
        ll left = 0;
        for(i=k;i<n;i++){
            if(arr[i]=1){
                
            }
        }
        cout<<ans<<endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution s;
    s.solve();
    return 0;
}