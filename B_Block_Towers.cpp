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
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        ll first = a[0];
        sort(a.begin(),a.end());
        for(i=0;i<n;i++){
            ll diff = a[i]-first;
            if(diff>0){
                if(diff%2==0){
                    first+=(diff)/2;
                }
                else{
                    first += (diff+1)/2;
                }
            }
        }
        cout<<first<<endl;
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