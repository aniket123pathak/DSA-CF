#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,c;
        cin>>n>>c;
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        vector<ll>b(n);
        for(i=0;i<n;i++){
           cin>>b[i];
        }

        sort(a.rbegin(),a.rend());
        sort(b.rbegin(),b.rend());

        for(i=0;i<n;i++){
            if(a[i]<b[i]){
                cout<<"-1"<<endl;
                return;
            }
        }
        ll ans=0;
        for(i=0;i<n;i++){
            if(a[i]>b[i]){
                cout<<"-1"<<endl;
                return;
            }
        }


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