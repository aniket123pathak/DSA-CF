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
        ll n,p,i;
        cin>>n>>p;
        vector<ll>a(n);
        vector<ll>b(n);
        vector<pair<ll,ll>>pr(n);
        for(i=0;i<n;i++){
            cin>>a[i];
            pr[i].first = a[i];
        }
        for(i=0;i<n;i++){
            cin>>b[i];
            pr[i].second = b[i];
        }

        sort(pr.begin(),pr.end());

        for(i=0;i<n;i++){
            
        }

        ll x= n ;
        ll cost = p;


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