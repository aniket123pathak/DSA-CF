#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout<<'NO'<<endl
#define yes cout<<'YES'<<endl
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
            cin>>a[i].second;
        }
        sort(a.begin(),a.end());
        pair<ll,ll>tv1={-1,-1};
        pair<ll,ll>tv2={-1,-1};
        for(i=0;i<n;i++){
            ll curStTime = a[i].first;
            ll curEdTime = a[i].second;
            if(tv1.second<curStTime){
                tv1.first = curStTime;
                tv1.second = curEdTime;
                continue;
            }
            if(tv2.second<curStTime){
                tv2.first = curStTime;
                tv2.second = curEdTime;
                continue;
            }
            cout<<"NO\n";
            return;
        }
        cout<<"YES\n";

        
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