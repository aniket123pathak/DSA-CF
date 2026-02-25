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

        for(i=0;i<n;i++){
            for(ll j =1;j<n-1;j++){
                if(a[j-1]<a[j]&&a[j]>a[j+1]){
                    swap(a[j],a[j+1]);
                }
            }
        }

        if(is_sorted(a.begin(),a.end())){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
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