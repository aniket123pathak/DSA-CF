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
        vector<ll>a(n+1,0);
        ll cur = 1;
        ll mul = 1;
        while(k*mul<=n){
            a[k*mul]=cur;
            cur++;
            mul++;
        }
        for(i=1;i<=n;i++){
            if(a[i]==0){
                a[i]=cur;
                cur++;
            }
        }
        for(i=1;i<=n;i++){
            cout<<a[i]<<" ";
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