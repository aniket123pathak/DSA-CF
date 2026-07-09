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
        /*
        2 1 5 2.   
        5 2 2 1

        3 0 1 2


        9 5 4 3 1 1    9+4+1
        
        4 0 4 3 1 1 

        4 0 0 1 1 1

        4 0 0 1 0 0


        1 1 1 1 1.  

        0 0 0 0 1
        */
        ll mnGrpi = 0;
        sort(a.rbegin(),a.rend());
        for(i=0;i<n-1;i+=2){
            mnGrpi+=max(a[i],a[i+1]);
        }
        if(n%2==0){
            cout<<mnGrpi<<endl;
        }
        else{
            cout<<mnGrpi+a[n-1]<<endl;
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