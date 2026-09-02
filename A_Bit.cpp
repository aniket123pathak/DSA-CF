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
        ll ans = 0;
        for(i=0;i<n;i++){
           string s;
           cin>>s;
           if((s[0]=='+'&&s[1]=='+')||(s[2]=='+'&&s[1]=='+')){
                ans++;
           }
           else{
            ans--;
           }
        }
        cout<<ans<<endl;
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