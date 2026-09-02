#include <bits/stdc++.h>
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
        unordered_map<ll,ll>mp;
        for(i=0;i<n;i++){
           cin>>a[i];
           mp[a[i]]++;
        }

        for(i=0;i<n;i++){
           if(mp[a[i]]>1){
            cout<<i+1<<" ";
            break;
           }
        }
        for(i=n-1;i>=0;i--){
           if(mp[a[i]]>1){
            cout<<i+1<<" ";
            cout<<endl;
            return;
           }
        }
        cout<<"1 1"<<endl;
        return;
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