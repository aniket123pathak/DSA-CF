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
        cin>>n;
        vector<vector<ll>>a;
        for(i=0;i<n;i++){
           cin>>m;
           vector<ll>temp(m);
           for(ll j = 0;j<m;j++){
            cin>>temp[j];
           }
           sort(temp.begin(),temp.end());
           a.push_back(temp);
        }

        ll minFirst = INT64_MAX;
        ll sumSec = 0;
        for(i=0;i<n;i++){
            minFirst = min(minFirst,a[i][0]);
            sumSec+=a[i][1];
        }
        ll beauty = INT64_MIN;
        for(i=0;i<n;i++){
            beauty = max(beauty,(sumSec-a[i][1]+min(a[i][0],minFirst)));
        }
        cout<<beauty<<endl;
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