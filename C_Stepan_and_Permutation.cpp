#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,x,y;
        cin>>n>>x>>y;
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        if(is_sorted(a.begin(),a.end())){
            cout<<"YES\n";
            return;
        }

        ll curGcd = __gcd(x,y);
        bool check=true;

        for(i=0;i<n;i++){
            ll diff = abs(a[i]-(i+1));
            if(diff%curGcd!=0){
                check = false;
                break;
            }
        }

        if(check){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
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