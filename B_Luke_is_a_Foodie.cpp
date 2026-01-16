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
        ll n,x,i;
        cin>>n>>x;
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        pair<ll,ll>range;
        range.first=a[0]-x;
        range.second=a[0]+x;
        ll change = 0 ;
        for(i=1;i<n;i++){
           range.first = max(range.first,a[i]-x);
           range.second = min(range.second,a[i]+x);
           if(range.first>range.second){
            change++;
            range.first = a[i]-x;
            range.second = a[i]+x;
           }
        }
        cout<<change<<endl;
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