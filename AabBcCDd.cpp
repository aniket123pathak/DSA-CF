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
            if(s[i]>=97){
                hash[s[i]-'a']++;
            }
            else{
                hash[s[i]-'A']++;
            }
        }
        sort(hash.begin(),hash.end());

        cout<<hash[24]+hash[25]<<endl;
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