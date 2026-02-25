#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define v(a, n) vector<long long> a(n)
#define fin(i, x, n, a)     \
    for (i = x; i < n; i++) \
    cin >> a[i]
/*
a[i]&a[j]>=a[i]^a[j]

6 2 5 3

6&2 6^2

110   110
&      ^
010   010

010   100     x >= (a|b) & !(x)


6 2 3 5

110
010
011
101

jika msb dono 1 hai
*/
class Solution
{
public:
    int findMSBPosManual(unsigned int n)
    {
        if (n == 0)
        {
            return -1; // Handle 0 case
        }
        int position = 0;
        while (n > 1)
        {
            n >>= 1;
            position++;
        }
        return position;
    }

    void solve()
    {
        ll n, i, j;
        cin >> n;
        vector<ll> a(n);
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (n == 1)
        {
            cout << 0 << endl;
            return;
        }
        vector<ll>hash(32);
        ll cnt = 0;
        for (i = 0; i < n ; i++)
        {
            hash[findMSBPosManual(a[i])]++;
        }

        for(i=0;i<32;i++){
            if(hash[i]>1){
                cnt+=(hash[i]*(hash[i]-1))/2;
            }
        }
        cout << cnt << endl;
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