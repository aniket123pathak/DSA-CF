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
        ll check1 = a[0]%2;
        ll check2 = a[1]%2;

        for(i=0;i<n;i++){
            if(i%2==0){
                if(a[i]%2!=check1){
                    cout<<"NO\n";
                    return;
                }
            }
            else{
                if(a[i]%2!=check2){
                    cout<<"NO\n";
                    return;
                }
            }
        }
        cout<<"YES\n";
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