#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout << 'NO' << endl
#define yes cout << 'YES' << endl
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
        cin>>n;

        string s;
        cin>>s;

       
        if(n!=5){
            cout<<"NO\n";
            return;
        }
        string target = "Timur";
        sort(target.begin(), target.end());
        sort(s.begin(), s.end());
        if(s==target){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
        return;
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