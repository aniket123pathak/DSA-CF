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
        ll n,i;
        cin>>n;
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        if(is_sorted(a.begin(),a.end())){
            cout<<"0\n";
            return;
        }
        if(is_sorted(a.begin(),a.end(),greater<ll>())){
            cout<<"1\n";
            return;
        }

        for(i=n-1;i>=0;i--){
            if(a[i]!=i+1){
                cout<<a[i]<<endl;
                return;
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