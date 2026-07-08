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
        
        for(i=0;i<pow(2,8);i++){
            ll temp = a[0]^i;

            for(ll j = 1;j<n;j++){
                ll exor = a[j] ^ i;
                temp = temp ^ exor;
            }
            if(temp == 0){
                cout<<i<<endl;
                return;
            }
        }
        cout<<-1<<endl;
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