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
        vector<ll>a(k);
        for(i=0;i<k;i++){
           cin>>a[i];
        }
        vector<pair<ll,ll>>b(n);
        for(i=0;i<n;i++){
           cin>>b[i].first;
           b[i].second=i+1;
        }
        sort(b.begin(),b.end());

        ll m = 0;
        vector<ll>ans;
        for(i=n-1;i>=0;i--){
            ll diff = k+1 - b[i].first;
            while(diff>0){
                ans.push_back(b[i].second);
                diff--;
            }
        }
        cout<<ans.size()<<endl;
        for(i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
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