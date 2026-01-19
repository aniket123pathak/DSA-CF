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
        sort(a.begin(),a.end());

        ll mx=0;
        ll count=0;

        for(i=0;i<n-1;i++){
            if(a[i+1]-a[i]==1){
                count++;
            }
            else if(a[i+1]-a[i]==0){
                continue;
            }
            else{
                mx=max(mx,count);
                count=0;
            }
        }
        mx=max(mx,count);

        cout<<mx+1<<endl;
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