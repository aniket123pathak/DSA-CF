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
        string s;
        cin>>s;
        ll fo = -1;
        for(i=0;i<n;i++) {
            if(s[i]=='1'){
                fo=i;
                break;
            }
        }
        if(fo==-1){
            cout<<0<<endl;
            return;
        }
        if(fo==0){
            ll zero = 0;
            for(i=1;i<n;i++){
                if(s[i]=='0'){
                    zero++;
                }
            }
            cout<<zero<<endl;
            return;
        }
        ll next1s = 0;
        ll next0s =0;
        for(i=fo+1;i<n;i++){
            if(s[i]=='0'){
                next0s++;
            }
            else{
                next1s++;
            }
        }

        //jar mi sagle  1  0 banvel tar condition
        ll reqC1 =1;
        ll reqC0 =next0s;
        ll ans= next0s;
        // now for every zero 
        for(i=fo+1;i<n;i++){
            if(s[i]=='0'){
                reqC0--; 
            }
            ans=min(ans,reqC1+reqC0);  
            if(s[i]=='1'){
                reqC1++;
            }
        }
        cout<<ans<<endl;
        return;


        
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