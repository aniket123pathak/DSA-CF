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
        vector<ll>b(n);
        for(i=0;i<n;i++){
           cin>>b[i];
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        vector<ll>ele(n);
        ll first = 0;
        ll second = 0;
        ll temp = 0;
        while(first<n&&second<n){
            if(a[first]>b[second]){
                temp++;
            }
            else{
                if(first!=0){
                    ele[first]=ele[first-1]+temp;
                }
                else{
                    ele[first]=temp;
                }
                temp=0;
                first++;
                second--;
            }
            second++;
        }
        if(first<n) {
            if(first!=0){
                ele[first]=ele[first-1]+temp;
            }
            else{
                ele[first]=temp;
            }
            first++;
            while(first<n){
                ele[first]=ele[first-1];
                first++;
            }
        }
        ll ans=1;
        ll MOD=1e9+7;
        
        for(i=0;i<n;i++){
            ll choices = ele[i] - i;
            if(choices<=0){
                ans=0;
                break;
            }
            ans=(ans*choices)%MOD;
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