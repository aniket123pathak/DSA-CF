#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,k,j;
        cin>>n>>k;
        string s;
        cin>>s;
        ll ans = 0;
        for(i=0;i<n;i+=k){
            bool check = false;
            for(j=i;j<i+k;j++){
                if(s[j]=='0'){
                    check = true;
                    break;
                }
            }
            if(!check){
                ans++;
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
    cin >> tc;
    while (tc-- > 0)
    {
        s.solve();
    }
    return 0;
}