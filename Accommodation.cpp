#include <iostream>
#include <vector>
#include <algorithm>
#include<math.h>
using namespace std;

#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll b,g,x,y,n;
        cin>>b>>g>>x>>y>>n;
        ll mnR = (b+g+n-1)/n;
        ll mxR = min(b/x,g/y);

        if(mxR>=mnR){
            cout<<mnR<<endl;
        }
        else{
            cout<<-1<<endl;
        }
        
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