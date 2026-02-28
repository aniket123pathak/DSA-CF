#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    void solve(){
        string n;
        cin>>n;
        ll ans=(n.length()-1)*9+(n[0]-'0');
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
