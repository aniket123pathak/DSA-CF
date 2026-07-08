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
        vector<ll>a(n);
        vector<pair<ll,ll>>pr(n);
        for(i=0;i<n;i++){
           cin>>a[i];
           pr[i].first=a[i]%k;
           if(a[i]%k==0){
            pr[i].first=k;
           }
           pr[i].first=-pr[i].first;
           pr[i].second=i;
        }
        sort(pr.begin(),pr.end());
        for(i=0;i<n;i++){
            cout<<pr[i].second+1<<" ";
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