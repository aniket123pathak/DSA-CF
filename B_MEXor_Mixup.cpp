#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:

    //O(1) function tu calculate the exor from 0 to n
    int XOR(int n) {
        if (n % 4 == 0) return n;
        if (n % 4 == 1) return 1;
        if (n % 4 == 2) return n + 1;
        return 0;
    }
    void solve()
    {
        ll a,b,i;
        cin>>a>>b;

        ll ans = a;
        // ***Remember***.  Y^X=b. => Y=X^b
        ll cur = XOR(a-1);
        ll req = cur^b;

        if(req==0){
            cout<<ans<<endl;
        }
        else if(req!=a){
            cout<<ans+1<<endl;
        }
        else{
            cout<<ans+2<<endl;
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