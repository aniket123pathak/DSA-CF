#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        string s;
        cin>>s;
        ll sm1 = 0;
        ll sm2 = 0;
        for(ll i=0;i<3;i++){
            sm1+=s[i]-'0';
            sm2+=s[6-(i+1)]-'0';
        }
        if(sm1==sm2){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
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