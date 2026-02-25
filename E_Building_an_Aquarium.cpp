#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

/*
what is the brute force logic of this??
checking from minheight column to desired height of the wall 
*/
class Solution {
public:
    void solve()
    {
        ll n,i,x;
        cin>>n>>x;
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        sort(a.begin(),a.end());

        

    }
};

int main() {
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