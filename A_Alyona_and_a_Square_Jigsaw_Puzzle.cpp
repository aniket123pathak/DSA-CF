#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define v(a, n) vector<long long> a(n)

class Solution
{
public:
    void solve()
    {
        ll n, i;
        cin >> n;
        v(a, n);
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll happyDays=0;
        ll sum = 0;
        vector<ll>puz;
        ll k=1;
        while(k*k<1000000){
            puz.push_back(k*k);
            k+=2;
        }
        for(i=0;i<n;i++){
            sum+=a[i];
            for(int j=0;j<puz.size();j++){
                if(puz[j]==sum){
                    happyDays++;
                    break;
                }
            }
        }
        cout << happyDays << endl;
}
}
;

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