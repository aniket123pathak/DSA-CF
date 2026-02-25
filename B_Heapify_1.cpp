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
        vector<ll>a(n+1);
        for(i=1;i<=n;i++){
           cin>>a[i];
        }
        if(n%2!=0){
            if((n+1)/2!=a[(n+1)/2]){
                cout<<"No\n";
            }
            else{
                cout<<"Yes\n";
            }
            return;
        }

        for(i=1;i<=n;i++){
            ll temp1 = i;
            bool check = false;
            while(temp1*2<=n){
                if(i==a[temp1]){
                    check = true;
                    break;
                }
                temp1*=2;
            }
            ll temp2 = i;
            while(temp2/2>0){
                if(i==a[temp2]){
                    check = true;
                    break;
                }
                temp1/=2;
            }
            if(!check){
                cout<<"No\n";
                return;
            }
        }
        cout<<"Yes\n";
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