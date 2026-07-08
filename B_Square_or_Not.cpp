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
        ll cnt0=0;
        string s;
        cin>>s;
        for(i=0;i<n;i++){
            if(s[i]=='0'){
                cnt0++;
            }
        }

        ll cnt1 = n-cnt0;

        for(i=0;i*i<=cnt0;i++){
            if(i*i==cnt0){
                if(cnt1==i*4+4){
                    cout<<"Yes\n";
                    return;
                }
            }
        }
        cout<<"No\n";
        
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