#include <iostream>
#include <vector>
#include <algorithm>
#include<numeric>
using namespace std;

#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,x,y,i;
        cin>>n>>x>>y;

        if(x==y){
            cout<<"0\n";
            return;
        }
        ll LCM = lcm(x,y);
        ll divLCM = n/LCM;
        ll divX = n/x;
        ll divY = n/y;

        ll sumx=0;
        ll sumy=0;

        ll tempx = n - max((ll)0,divX-divLCM);
        ll tempy = max((ll)0,divY-divLCM);

        ll totalSum = (n*(n+1))/2;

        sumy=(tempy*(tempy+1))/2;

        sumx = totalSum - ((tempx*(tempx+1))/2);
        


        cout<<sumx-sumy<<endl;
        
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