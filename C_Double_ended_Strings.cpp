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
        string s1,s2;
        cin>>s1>>s2;
        string small,big;

        if(s1.length()>s2.length()){
            big=s1;
            small=s2;
        }
        else{
            big=s2;
            small=s1;
        }
        ll sm = small.length();
        ll bg = big.length();
        ll ans = 0;
        for(ll i =0;i<sm;i++){
            string temp ="";
            for(ll j=i;j<sm;j++){
                temp+=small[j];
                ll cur = temp.length();
                for(ll k = 0;k<=bg-cur;k++){
                    ll l=0;
                    for(l=0;l<cur;l++){
                        if(big[k+l]!=temp[l]){
                            break;
                        }
                    }
                    if(l==cur){
                        ans=max(ans,cur);
                    }
                }
            }
        }
        cout<<sm+bg-2*ans<<endl;
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