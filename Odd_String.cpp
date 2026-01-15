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

        if(n==1){
            cout<<"YES\n";
            return;
        }
        vector<ll>hash(126,0);

        for(i=0;i<s.length();i++){
            hash[s[i]]++;
        }

        for(i=0;i<126;i++){
            if(hash[i]>2){
                cout<<"NO\n";
                return;
            }
        }
        cout<<"YES\n";

    }
};

int main() {
    Solution s;
    int tc;
    cin >> tc;
    while (tc-- > 0)
    {
        s.solve();
    }
    return 0;
}