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
        v(a,n);
        fin(i,0,n,a);
        if(a[0]>n){
            cout<<"NO\n";
            return;
        }
        vector<ll>hori;
        for(i=n-1;i>=0;i--){
            while(a[i]>hori.size())
            {
                hori.push_back(i+1);
            }
        }

        for(i=0;i<n;i++){
            if(a[i]!=hori[i]){
                cout<<"NO\n";
                return;
            }
        }
        cout<<"YES\n"; 
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