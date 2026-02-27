#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,m,l,r;
        cin>>n>>m>>l>>r;

        if(r-l+1<m){
            cout<<l<<" "<<r<<endl;
            return;
        }
        else{
            if(l+m<0){
                cout<<l<<" "<<l+m<<endl;
                return;
            }
            else{
                cout<<l+(-(l+m))<<" "<<(l+m)-(-(l+m))<<endl;
                return;
            }
            
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