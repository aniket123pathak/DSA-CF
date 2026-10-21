#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,m;
        cin>>n>>m;
        vector<ll>a(n);
        a[0]=1;
        for(i=1;i<n;i++){
           cin>>a[i];
        }
        vector<ll>b(n);
        for(i=0;i<n;i++){
           cin>>b[i];
        }
        /*
        4 3 3 2 2 1 1 1
        1 1 1 1 3 3 3 3

        1 1 1 2 2 3 3 4 
        1 1 1 1 3 3 3 3

        1 9 2 8 3 7 4 6 5
        1 2 3 2 1 4 5 6 5

        1 2 3 4 5 
        1 1 2 2 3 4 5 5 6

        5 6 4 5 3 5 3 4 2 

        +4 
        */

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        ll ans = 0;
        ll mxB = b[n-1];
        ll lb = lower_bound(a.begin(),a.end(),mxB)-a.begin();

        if(lb==0){
            cout<<n<<endl;
            return;
        }
        ans += n-lb;
        ll leftA = 0;
        ll rightA = lb;

        ll leftB = (n-lb);
        ll rightB = n;

        while(leftB<rightB&&leftA<rightA){
            if(a[leftA]>=b[leftB]){
                ans++;
                leftB++;
            } 
            else{
                leftB++;
                leftA++;
            }
        }

        cout<<ans<<endl;
        

        
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