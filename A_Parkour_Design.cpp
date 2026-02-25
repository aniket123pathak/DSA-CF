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
        ll x, y;
        cin >> x >> y;

        if(x==1){
            cout<<"NO\n";
            return;
        }
        
        if((x-2*y)%3==0){
            if(y>=0&&(x-2*y)>=0)
                cout<<"YES\n";
            else if(y<0&&(x+4*y)>=0){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
        else{
            cout<<"NO\n";
        }
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