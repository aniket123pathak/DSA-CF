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
        ll n, i, j;
        cin >> n;
        ll x = 1;
        ll y = n * n;
        ll k = 1;
       

            for (i = 1; i <= n; i++)
            {
                vector<ll>temp;
                for (j = 1; j <= n; j++)
                {
                    if (k % 2 == 0)
                    {
                        temp.push_back(y);
                        y--;
                    }
                    else
                    {
                        temp.push_back(x);
                        x++;
                    }
                    k++;
                }
                if(i%2==0){
                    for(ll z=0;z<n;z++){
                        cout<<temp[z]<<" ";
                    }
                }
                else{
                    for(ll z=n-1;z>=0;z--){
                        cout<<temp[z]<<" ";
                    }
                }
                cout << endl;
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