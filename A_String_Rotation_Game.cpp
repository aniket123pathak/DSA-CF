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
        string s;
        cin>>s;

        ll blck=1;

        for(i=0;i<n-1;i++){
            if(s[i]!=s[i+1]){
                blck++;
            }
        }
        if(blck==n){
            cout<<n<<endl;
            return;
        }
        if(s[0]==s[n-1]){
            cout<<blck<<endl;
            return;
        }
        cout<<blck+1<<endl;

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