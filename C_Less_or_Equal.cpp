#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,k;
        cin>>n>>k;
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        sort(a.begin(),a.end());
        if(k==0){
            if(a[0]==1){
                cout<<-1<<endl;
                return;
            }
            else{
                cout<<1<<endl;
                return;
            }
        }
        if(k==1){
            if(n==1){
                cout<<a[0]<<endl;
                return;
            }
            else{
                if(a[0]!=a[1]){
                    cout<<a[0]<<endl;
                    return;
                }
                else{
                    cout<<-1<<endl;
                    return;
                }
            }
        }
        if(k==n){
            cout<<a[n-1]<<endl;
            return;
        }
        if(a[k-1]==a[k]){
            cout<<-1<<endl;
        }
        else{
            cout<<a[k-1]<<endl;
        }
        return;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution s;
    s.solve();
    return 0;
}