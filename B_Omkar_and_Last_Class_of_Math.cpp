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
        if(n%2==0){
            cout<<n/2<<" "<<n/2<<endl;
            return;
        }

        ll a = 1;
        ll b = n-1;
        
        vector<ll>div;
        for(i=2;i*i<=n;i++){
            ll cur = -1;
            ll cur2 = -1;
            if(n%i==0){
                cur = i;
                if(i!=n/i){
                    cur2=n/i;
                }
            }
            if(cur2!=-1){
                if((n-cur2)%cur2==0){
                    if(cur2 > a){
                        a=cur2;
                        b=n-cur2;
                    }
                }      
            }
            
            if(cur!=-1){ 
                if((n-cur)%cur==0){
                    if(cur>a){
                        a=cur;
                        b=n-cur;
                    }
                }
            }
        }
        cout<<a<<" "<<b<<endl;
        
        
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