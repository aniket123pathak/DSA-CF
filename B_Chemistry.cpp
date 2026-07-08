#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<ll>hash(26,0);
        for(i=0;i<s.length();i++){
            hash[s[i]-'a']++;
        }
        bool isFirstOdd = true;
        ll ans = 0;
        for(i=0;i<26;i++){
            if(hash[i]%2!=0){
                if(isFirstOdd){
                    isFirstOdd=false;
                }
                else{
                    ans++;
                }
            }
        }
        if(ans<=k){
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