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
        if(n==1){
            cout<<-1<<endl;
            return;
        }
        if(a[1]!=a[0]||a[n-1]!=a[n-2]){
            cout<<-1<<endl;
            return;
        }
        for(i=1;i<n-1;i++){
            if(a[i]!=a[i-1]&&a[i]!=a[i+1]){
                cout<<-1<<endl;
                return;
            }
        }
        vector<ll>ans(n);
        for(i=0;i<n;i++){
            ll temp = a[i];
            ll start = i;
            ll lastIdx = i;
            while(i<n&&temp==a[i]){
                lastIdx=i;
                i++;
            }
            ans[start]=lastIdx+1;
            for(ll j = start+1;j<=lastIdx;j++){
                ans[j]=j;
            }
            i--;
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