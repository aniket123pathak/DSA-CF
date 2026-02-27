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
        ll count1 = 0;
        for(i=0;i<n;i++){
           cin>>a[i];
           if(a[i]==1){
            count1++;
           }
        }
        if(count1==1){
            cout<<"0\n";
            return;
        }
        ll first1=-1;
        for(i=0;i<n;i++){
            if(a[i]==1){
                first1=i;
                break;
            }
        }
        ll last1=-1;
        for(i=n-1;i>=0;i--){
            if(a[i]==1){
                last1=i;
                break;
            }
        }
        ll ans = 0;
        for(i=first1;i<last1;i++){
            if(a[i]==0){
                ans++;
            }
        }
        cout<<ans<<endl;
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