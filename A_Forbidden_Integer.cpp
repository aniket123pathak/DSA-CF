#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,k,x;
        cin>>n>>k>>x;
        if(x!=1){
            cout<<"YES\n";
            cout<<n<<endl;
            for(ll i=0;i<n;i++){
                cout<<1<<" ";
            }
            cout<<endl;
            return;
        }
        
        if((k==2 && n%2!=0) || (k==1)){
            cout<<"NO\n";
            return;
        }

        cout<<"YES\n";

        if(n%2==0) {
            cout<<n/2<<endl;
            for(ll i=0;i<n/2;i++){
                cout<<2<<" ";
            }
            cout<<endl;
            return;
        }

        cout<<1+(n-3)/2<<endl;
        cout<<3<<" ";
        for(ll i=0;i<(n-3)/2;i++){
            cout<<2<<" ";
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