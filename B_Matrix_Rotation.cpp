#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        vector<ll>a(4);
        for(ll i=0;i<4;i++){
            cin>>a[i];
        }    
        ll maxELe = *max_element(a.begin(),a.end()); 
        ll minELe = *min_element(a.begin(),a.end());    

        if(maxELe==a[0]&&minELe==a[3]||maxELe==a[3]&&minELe==a[0]||maxELe==a[1]&&minELe==a[2]||maxELe==a[2]&&minELe==a[1])
        {
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }


    }
};

int main() {
    Solution s;
    int tc;
    cin >> tc;
    while (tc-- > 0)
    {
        s.solve();
    }
    return 0;
}