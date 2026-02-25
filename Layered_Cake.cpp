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
        ll n,i,m;
        cin>>n>>m;
        vector<ll>a(n),b(m);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        for(i=0;i<m;i++){
           cin>>b[i];
        }
        ll count = 0 ;

        for(i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                if(a[i]>b[j]){
                    count++;
                }
            }
        }
        cout<<count<<endl;
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