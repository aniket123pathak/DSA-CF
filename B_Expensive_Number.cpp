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
        ll n,i;
        n = s.length();
        ll back0=0;
        for(i=n-1;i>=0;i--){
            if(s[i]=='0'){
                back0++;
            }
            else{
                break;
            }
        }
        ll tot0 =0;
        for(i=0;i<n;i++){
            if(s[i]=='0'){
                tot0++;
            }
        }
        ll rahuDyayche = 1+tot0-back0;
        cout<<n-rahuDyayche<<endl;
        
        
        
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