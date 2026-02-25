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
        ll n, i;
        string s;
        cin >> s;
        n=s.length();

        if(s[1]=='a'){
            cout<<s[0]<<" "<<s[1]<<" ";
            for(i=2;i<n;i++){
                cout<<s[i];
            }
        }
        else{
            cout<<s[0]<<" ";
            for(i=1;i<n-1;i++){
                cout<<s[i];
            }
            cout<<" "<<s[n-1];
        }
        cout<<endl;
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