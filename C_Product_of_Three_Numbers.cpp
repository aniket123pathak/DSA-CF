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
        vector<ll>pf;
        
        for(i=2;i*i<=n;i++){
            if(n%i==0){
                while(n%i==0){
                    pf.push_back(i);
                    n/=i;
                }
            }
        }
        if(n>1){
            pf.push_back(n);
        }

        ll a = pf[0];
        ll b = 1;
        ll c = 1;

        for(i=1;i<pf.size();i++){
            if(b==1||b==a){
                b*=pf[i];
            }
            else{
                c*=pf[i];
            }
        }

        if(a==1||b==1||c==1||c==b||c==a){
            cout<<"NO\n";
            return;
        }
        cout<<"YES\n";
        cout<<a<<" "<<b<<" "<<c<<endl;

        
        
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