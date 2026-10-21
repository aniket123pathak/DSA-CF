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
        string s;
        cin>>s;
        n = s.length();
        bool check1 = false;
        bool check2 = false;
        for(i=0;i<n;i++){
            if(!check1 && s[i]=='1'){
                check1 = true;
                continue;
            }
            if(!check2 && s[i]=='0'){
                check2 = true;
                continue;
            }
            cout<<s[i];
        }
        cout<<endl;

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