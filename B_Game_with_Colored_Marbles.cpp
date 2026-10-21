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
        vector<ll>mp(1001,0);
        for(i=0;i<n;i++){
           cin>>a[i];
           mp[a[i]]++;
        }
        ll cnt1 = 0;
        for(i=1;i<=1000;i++){
            if(mp[i]==1){
                cnt1++;
            }
        }
        ll points = ((cnt1+1)/2)*2;
        for(i=1;i<=1000;i++){
            if(mp[i]>1){
                points++;
            }
        }
        cout<<points<<endl;
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