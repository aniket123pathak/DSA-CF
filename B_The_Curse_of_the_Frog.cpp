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
        ll n,i,x;
        cin>>n>>x;
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        vector<vector<ll>>qry(n);
        ll count = 0 ;
        ll mn = INT64_MAX ;
        vector<ll>idx;
        for(i=0;i<n;i++){
            ll a,b,c;
            cin>>a>>b>>c;
            qry[i].push_back(a);
            qry[i].push_back(b);
            qry[i].push_back(c);
            if(b>1&&a-c>0){
                idx.push_back(i);
            }
        }
        vector<pair<ll,ll>>diff(count);
        for(i=0;i<;i++){
            
        }



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