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
        vector<char>s(n+1);
        ll cnt = 0;
        for(i=1;i<=n;i++){
            cin>>s[i];
            if(s[i]=='0'){
                cnt++;
            }
        }
        vector<char>temp = s;
        ll cst=0;
        for(i=1;i<=n;i++){
            ll cur=i;
            ll j=1;
            while(i*j<=n){
                if((s[i*j]==temp[i*j]&&s[i*j]=='1')){
                    break;
                }
                else{
                    if(s[i*j]=='0'){
                        s[i*j]='1';
                        cst+=cur;
                        j++;
                    }
                    else{
                        j++;
                    }
                }
            }
        }
        cout<<cst<<endl;
        
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