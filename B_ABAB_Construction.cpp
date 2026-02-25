#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a, n) vector<long long> a(n)
#define fin(i, x, n, a)     \
    for (i = x; i < n; i++) \
    cin >> a[i]

class Solution
{
public:
    void solve()
    {
        ll n, i = 0;
        ll x = 0;
        cin >> n;
        string s;
        cin >> s;

        if (n%2!=0){
            if(s[0]=='b'){
                cout<<"NO\n";
                return;
            }
            x=1;
        }

        for (i=x;i<n-1;i+=2){
            if ((s[i]=='a'&&s[i + 1]=='a')||(s[i]=='b'&&s[i+1]=='b')){
                cout<<"NO\n";
                return;
            }
        }

        cout<<"YES\n";
    }
};

int main()
{
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