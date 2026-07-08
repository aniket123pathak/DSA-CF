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
        ll mx = n;
        ll idx = -1;
        for(i=0;i<n;i++){
            if(a[i]==mx){
                mx--;
            }
            else{
                idx=i; 
                break;
            }
        }
        if(idx==-1){
            for(i=0;i<n;i++){
                cout<<a[i]<<" ";
            }
            cout<<endl;
            return;
        }
        ll nwMx=n-idx;
        for(i=0;i<idx;i++){
            cout<<a[i]<<" ";
        }
        ll nwIdx = -1;
        for(i=idx;i<n;i++){
            if(a[i]==nwMx){
                nwIdx = i;
                break;
            }
        }
        for(i=nwIdx;i>=idx;i--){
            cout<<a[i]<<" ";
        }
        for(i=nwIdx+1;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
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