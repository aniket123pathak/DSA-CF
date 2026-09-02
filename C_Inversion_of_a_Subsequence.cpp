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
        if(a==b){
            cout<<0<<endl;
            return;
        }
        ll noMatch0=0;
        ll noMatch1=0;
        ll match0=0;
        ll match1=0;
        for(i=0;i<n;i++){
            if(a[i]!=b[i]){
                if(a[i]==1){
                    noMatch1++;
                }
                else{
                    noMatch0++;
                }
            }
            else{
                if(a[i]==1){
                    match1++;
                }
                else{
                    match0++;
                }
            }
        }
        
        if(noMatch0==noMatch1&&noMatch0==0){
            cout<<0<<endl;
            return;
        }
        // if mismatd 1 is odd then no issue
        if(noMatch1>0&&noMatch1%2!=0){
            cout<<1<<endl;
            return;
        }
        // if mismatch 1 are non odd but pos means even so we flip a single 1 to make odd and then in 1 operation odo eveything other
        if(noMatch1>0&&noMatch1%2==0){
            cout<<2<<endl;
            return;
        }

        if(noMatch1==0){
            if(noMatch0!=0){
                // if we have noMismatch 1 and and no matched zeros so if any thing is zero so we cannot do anything
                if(match1==0||match0==0){
                    cout<<-1<<endl;
                }
                else{
                    cout<<2<<endl;
                }
                return;
            }
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