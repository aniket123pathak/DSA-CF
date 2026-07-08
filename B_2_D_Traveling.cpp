#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,k,a,b;
        cin>>n>>k>>a>>b;
        vector<pair<ll,ll>>p(n);
        for(i=0;i<n;i++){
           cin>>p[i].first;
           cin>>p[i].second;
        }
        if(a<=k&&b<=k){
            cout<<0<<endl;
            return;
        }
        if(k==0){
            cout<<abs(p[a-1].first-p[b-1].first)+abs(p[a-1].second-p[b-1].second)<<endl;
            return;
        }
        
        ll ans = abs(p[a-1].first-p[b-1].first)+abs(p[a-1].second-p[b-1].second);
        

        ll minA=INT64_MAX;
        for(i=0;i<k;i++){
            ll dist = abs(p[i].first - p[a-1].first) + abs(p[i].second - p[a-1].second);
            minA = min(minA, dist);
        }
        ll minB=INT64_MAX;
        for(i=0;i<k;i++){
            ll dist = abs(p[i].first - p[b-1].first) + abs(p[i].second - p[b-1].second);
            minB = min(minB, dist);
        }

        cout<<min(minA+minB,ans)<<endl;

        
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