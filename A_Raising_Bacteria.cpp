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
        
        ll x = 0;
        for(i=0;i<80;i++){
            if((n>>i)>0){
                continue;
            }
            else{
                if(n==0){
                    cout<<x<<endl;
                    return;
                }
                ll p = pow(2,i-1);
                n=n%p;
                x++;
                i=-1;
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution s;
    int tc; 
        s.solve();
    
    return 0;
}