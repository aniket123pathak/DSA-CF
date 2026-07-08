#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,k;
        cin>>n>>k;
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }

        ll robin = 0;
        ll ans =0;
        for(i=0;i<n;i++){
            if(a[i]==0){
                if(robin>0){
                    ans++;
                    robin--;
                }
            }
            else{
                if(a[i]>=k){
                    robin+=(a[i]);
                }
            }
        }
        cout<<ans<<endl;
        
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