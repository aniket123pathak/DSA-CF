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
        bool check = true;
        for(i=0;i<n;i++){
           cin>>a[i];
           if(a[i]>=0){
            check = false;
           }
        }
        if(check){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
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