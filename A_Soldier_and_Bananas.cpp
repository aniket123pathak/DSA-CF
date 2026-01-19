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
        ll k,n,w;
        cin>>k>>n>>w;
        ll total = w;
        
        if(total-n<=0){
            cout<<"0\n";
        }
        else{
            cout<<total-n<<endl;
        }
    }
};

int main() {
    Solution s;
    
        s.solve();

    return 0;
}