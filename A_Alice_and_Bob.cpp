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
        ll n,a,i;
        cin>>n>>a;
        v(v,n);
        fin(i,0,n,v);
        ll After=0;
        ll Before=0;

        for(i=0;i<n;i++){
            if(v[i]<a){
                Before++;
            }
            if(v[i]>a){
                After++;
            }
        }

        if(After>Before){
            cout<<a+1<<endl;
        }
        else if((After<Before)){
            cout<<a-1<<endl;
        }
        else{
            cout<<a+1<<endl;
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