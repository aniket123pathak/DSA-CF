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
        vector<ll>hash(101,0);
        for(i=0;i<n;i++){
           cin>>a[i];
           hash[a[i]]++;
        }
        ll mx = *max_element(hash.begin(),hash.end());

        for(i=0;i<101;i++){
            if(mx==hash[i]){
                cout<<i<<endl;
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