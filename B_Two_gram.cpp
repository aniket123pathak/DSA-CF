#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,j;
        cin>>n;
        string s;
        cin>>s;
        vector<vector<ll>>mp(26,vector<ll>(26,0));
        for(i=0;i<n-1;i++){
            mp[s[i]-'A'][s[i+1]-'A']++;
        }
        ll mx = 0;
        ll f = -1;
        ll l = -1;
        for(i=0;i<26;i++){
            for(j=0;j<26;j++){
                mx = max(mx,mp[i][j]);
            }
        }
        for(i=0;i<26;i++){
            for(j=0;j<26;j++){
                if(mp[i][j]==mx){
                    f = i;
                    l = j;
                    break;
                }
            }
        }
        string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        cout<<str[f]<<str[l]<<endl;        
        return;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution s;
    s.solve();
    return 0;
}