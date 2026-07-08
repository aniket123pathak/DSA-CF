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
        vector<pair<ll,ll>>pr(n);
        for(i=0;i<n;i++){
           cin>>a[i];
           pr[i].first=a[i];
           pr[i].second = i;
        }
        sort(pr.rbegin(),pr.rend());
        vector<ll>ans(n+1);
        ll check = 1;
        ll tme = 0;
        for(i=0;i<n;i++){
            ans[pr[i].second+1]=check;
            tme += 2*(pr[i].first)*abs(check);
            if(check<0){
                check=abs(check)+1;  
            }
            else{
                check = -check;
            }
        }
        cout<<tme<<endl;
        for(i=0;i<n+1;i++){
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