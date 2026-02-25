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
        ll n,x,k;
        cin>>n>>x>>k;
        
        if(x%k==0){
            cout<<0<<endl;
            return;
        }

        if(x/k==0){
            cout<<min(x,k-x)<<endl;
            return ;
        }

        ll rem = x%k;
        cout<<min(rem,k)<<endl;


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