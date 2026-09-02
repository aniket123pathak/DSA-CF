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
        ll sump = 0;
        ll sumn = 0;
        for(i=0;i<n;i++){
           cin>>a[i];
           if(a[i]>0){
            sump++;
           }
           else{
            sumn++;
           }
        }
        if(n%2!=0){
            cout<<"NO\n";
            return;
        }
        if(sump+sumn==0){
            cout<<"YES\n";
            return;
        }

        ll target = n/2;
        if(abs(sump-target)%2==0){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
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