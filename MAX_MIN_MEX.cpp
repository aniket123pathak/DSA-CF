#include <iostream>
#include <vector>
#include <algorithm>
#include<math.h>
using namespace std;

#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

/*
we have to find the number of longest chains
*/

ll pow2(ll p){
    ll x = 2;
    ll ans = 1;

    for(ll i=1;i<=p;i++){
        ans = (ans*2)%998244353;
    }
    return ans;
}
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
        sort(a.begin(),a.end());

        ll count = 0;
        ll cntOfCount=0;
        ll mx = 0;

        for(i=1;i<n;i++){
            if(a[i]-a[i-1]==1){
                count++;
            }
            else{
                mx=max(mx,count);
                count=0;
            }
        }
        mx=max(mx,count);
        count=0;

        for(i=1;i<n;i++){
             if(a[i]-a[i-1]==1){
                count++;
            }
            else{
                if(count==mx){
                    cntOfCount++;
                }
                count=0;
            }
        }
        if(count==mx){
            cntOfCount++;
        }
        ll rem = n-mx-1;
        ll ans =1;
        if(rem>0){
            ll fact =1;
            for(i=1;i<=rem;i++){
                fact=(fact*i)%998244353;
            }
            ans = fact;
        }

        ll finalAns = (ans*cntOfCount)%998244353;
        ll finalAns2=((finalAns)*pow2(mx))%998244353;

        cout<<finalAns2<<endl;


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