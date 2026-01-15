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
        ll x,y;
        cin>>x>>y;

        if(x>=y){
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
   
    
        s.solve();

    return 0;
}