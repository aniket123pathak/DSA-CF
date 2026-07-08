#include <iostream>
#include <vector>
#include <algorithm>
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
        if(n==1){
            cout<<1<<endl;
            return;
        }
        ll ans=1;
        ll idx = n;
        for(i=1;i<n;i++){
            if(a[i]!=a[0]){
                idx=i;
                break;
            }
        }
        if(idx==n){
            cout<<1<<endl;
            return;
        }
        else{
            ans++;
        }
        bool incresing = false;
        if(a[idx]>a[0]){
            incresing = true; 
        }
        ll prev = a[idx];
        for(i=idx+1;i<n;i++){
            if(incresing){
                if(a[i]>=prev){
                }
                else{
                    incresing=false;
                    ans++;
                }
                prev=a[i];
            }
            else{
                if(a[i]<=prev){
                }
                else{
                    incresing=true;
                    ans++;
                }
                prev=a[i];
            }
        }
        cout<<ans<<endl;
        

    }
};

int main() {
    Solution s;
    int tc;
    cin >> tc;
    while (tc-- > 0)
    {
        s.solve();
    }
    return 0;
}