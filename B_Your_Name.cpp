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
        string s1;
        string s2;
        cin>>s1>>s2;
        vector<int>hash1(26);
        vector<int>hash2(26);
        for(int i = 0;i<n;i++){
            hash1[s1[i]-'a']++;
        }
        for(int i = 0;i<n;i++){
            hash2[s2[i]-'a']++;
        }
        for(int i =0;i<26;i++){
            if(hash1[i]!=hash2[i]){
                cout<<"NO\n";
                return;
            }
        }
        cout<<"YES\n";

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