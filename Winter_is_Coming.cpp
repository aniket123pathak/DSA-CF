#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
temp>=a without jacket comf
temp<=b with jacket comf
*/
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,a,b;
        cin>>n>>a>>b;
        vector<ll>c(n);
        for(i=0;i<n;i++){
           cin>>c[i];
        }
        ll count = 0 ;
        bool wearing = false;
        for(i=0;i<n;i++){
            if(c[i]>=a && c[i]>b && wearing ){
                wearing=false;
            }
            else if(c[i]<=b && c[i]<a && !wearing){
                count++;
                wearing=true;
            }
            else if(c[i]<=b && c[i]>=a){
                
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