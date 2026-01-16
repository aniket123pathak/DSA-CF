#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_map>
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
        bool check = false;
        vector<ll>a(n);
        unordered_map<ll,ll>mp;
        for(i=0;i<n;i++){
           cin>>a[i];
           mp[a[i]]++;
           if(mp[a[i]]>1){
            check=true;
           }
        }
        if(check){
            cout<<"YES\n";
            return;
        }
        cout<<"NO\n";

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