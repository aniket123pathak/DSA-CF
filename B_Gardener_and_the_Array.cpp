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
        vector<vector<ll>>a;
        map<ll,ll>mp;
        for(i=0;i<n;i++){
            ll k;
            cin>>k;
            vector<ll>temp(k);
            for(ll j=0;j<k;j++){
                cin>>temp[j];
                mp[temp[j]]++;
            }
            a.push_back(temp);
        }

        for(i=0;i<n;i++){
            bool check = true;
            for(ll j = 0;j<a[i].size();j++){
                if(mp[a[i][j]]==1){
                    check = false;
                    break;
                }
            }
            if(check){
                cout<<"YES\n";
                return;
            }
        }
        cout<<"NO\n";

        
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