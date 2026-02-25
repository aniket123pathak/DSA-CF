#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<ll>valid;

    Solution(){
        for (ll p=1;p<=99999;p*=10) {
            for (ll d=1;d<=9;d++) {
                valid.push_back(d*p);
            }
        }
        sort(valid.begin(),valid.end());
    }

    void solve(){
        ll n;
        cin>>n;
        ll ans=upper_bound(valid.begin(),valid.end(),n)-valid.begin();
        cout<<ans<<"\n";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    int tc;
    cin >> tc;
    while (tc--) {
        s.solve();
    }
    return 0;
}
