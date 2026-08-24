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
        ll total = 0;
        ll neg = 0;
        ll mn = INT64_MAX;
        for(i=0;i<n;i++){
           cin>>a[i];
           if(a[i]<0){
            neg++;
           }
           mn = min(abs(a[i]),mn);
           total+=abs(a[i]);
        }
        if(neg%2==0){
            cout<<total<<endl;
            return;
        }
        cout<<total - 2*mn<<endl;
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