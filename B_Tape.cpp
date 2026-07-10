#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,m,k;
        cin>>n>>m>>k;
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        if(n==1){
            cout<<1<<endl;
            return;
        }
        vector<ll>diff;
        for(i=0;i<n-1;i++){
            diff.push_back(a[i+1]-a[i]);
        }
        
        /*
        1 2 4 60 87 200 201
        1 2 56 27 113  1
        
        1 1 2 27 56 113 

        20 30 75 80
        10 45 5


        1 2 4 60 87
              se se
        1 2 56 27
        */
        sort(diff.begin(),diff.end());

        ll sealed = n-(k+1);
        ll ans = k;
        for(i=0;i<=sealed;i++){
            ans+=diff[i];
        }
        cout<<ans<<endl;

        
        return;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution s;
    s.solve();
    return 0;
}