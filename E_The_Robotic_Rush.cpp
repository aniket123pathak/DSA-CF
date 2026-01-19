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
        ll n,m,k,i;
        cin>>n>>m>>k;
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        vector<ll>b(m);
        for(i=0;i<m;i++){
           cin>>b[i];
        }
        string s;
        cin>>s;
        ll x=0;
        for(i=0;i<k;i++){
            if(a[i]=='L'){
                x--;
            }
            else{
                x++;
            }
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