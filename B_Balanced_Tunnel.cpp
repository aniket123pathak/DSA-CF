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
        vector<pair<ll,ll>>a(n);
        for(i=0;i<n;i++){
           cin>>a[i].first;
           a[i].second=i;
        }
        vector<pair<ll,ll>>b(n);
        for(i=0;i<n;i++){
           cin>>b[i].first;
           b[i].second=i;
        }
        // soooooo....max Diff of pos of car which loooosed their pos.. 
        // lol its not that easy...lets think of another soln...
        //
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        ll diff = -1;
        for(i=0;i<n;i++){
            diff = max(diff,b[i].second-a[i].second);
        }
        cout<<max((ll)0,diff)<<endl;
        
        return;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution s;
    int tc;
    
        s.solve();
    
    return 0;
}