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
        ll sum =0;
        for(i=0;i<n;i++){
           cin>>a[i];
           sum+=a[i];
        }
        for(i=0;i<n-1;i++){
            if(a[i]==-1&&a[i+1]==-1){
                cout<<sum+4<<endl;
                return;
            }
        }
        for(i=0;i<n-1;i++){
            if(a[i]+a[i+1]==0){
                cout<<sum<<endl;
                return;
            }
        }
        
        cout<<sum-4<<endl;
        
        
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