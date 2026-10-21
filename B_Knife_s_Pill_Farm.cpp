#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,m;
        cin>>n>>m;
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        if(m==1){
            cout<<*max_element(a.begin(),a.end())<<endl;
            return;
        }
        priority_queue<ll>pq;
        ll cur = 0;
        for(i=0;i<m-1;i++){
            pq.push(a[i]);
            cur+=a[i];
        }
        ll ans = -2e18;
        for(i=m-1;i<n;i++){
            ans = max(ans , m*a[i]-cur);
            if(pq.top()>a[i]){
                cur -=  pq.top();
                pq.pop();
                pq.push(a[i]);
                cur += a[i];
            }
        }
        cout<<ans<<endl;
        
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