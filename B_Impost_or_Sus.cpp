#include <iostream>
#include <vector>
#include <algorithm>
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
        ll n,i;
        string s;
        cin >> s;
        n = s.length();
        ll minOp= 0;
        if (s[0]== 'u'){
            s[0]= 's';
            minOp++;
        }
        if (s[n-1] == 'u'){
            s[n-1] = 's';
            minOp++;
        }

        ll curUcnt= 0;
        for (i = 0; i < n; i++){
            if (s[i] == 'u'){
                curUcnt++;
            }
            else{
                minOp += (curUcnt / 2);
                curUcnt = 0;
            }
        }
        cout << minOp << endl;
    }
};

int main()
{
    Solution s;
    int tc;
    cin >> tc;
    while (tc-- > 0)
    {
        s.solve();
    }
    return 0;
}