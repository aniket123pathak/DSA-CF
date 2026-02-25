#include <iostream>
#include <vector>
#include <algorithm>
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
        string s;
        cin>>s;
        vector<ll>hash(26);
        for(i=0;i<n;i++){
           hash[s[i]-'a']++;
        }
        string k = "abcdefghijklmnopqrstuvwxyz";
        for(i=0;i<26;i++){
            if(hash[i]==0){
                cout<<k[i]<<endl;
                return;
            }
        }
        ll hash2[26][26];
        for(i=0;i<26;i++){
            for(ll j=0;j<26;j++){
                hash2[i][j]=0;
            }
        }
        for(i=0;i<n-1;i++){
            hash2[s[i]-'a'][s[i+1]-'a']++;
        }
        for(i=0;i<26;i++){
            for(ll j=0;j<26;j++){
                if(hash2[i][j]==0){
                    cout<<k[i]<<k[j]<<endl;
                    return;
                }
            }
        }

        ll hash3[26][26][26];
        for(i=0;i<26;i++){
            for(ll j=0;j<26;j++){
                for(ll m =0;m<26;m++){
                    hash3[i][j][m]=0;
                }
            }
        }
        for(i=0;i<n-2;i++){
            hash3[s[i]-'a'][s[i+1]-'a'][s[i+2]-'a']++;
        }
        for(i=0;i<26;i++){
            for(ll j=0;j<26;j++){
                for(ll m =0;m<26;m++){
                    if(hash3[i][j][m]==0){
                        cout<<k[i]<<k[j]<<k[m]<<endl;
                        return;
                    }
                }
            }
        }
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