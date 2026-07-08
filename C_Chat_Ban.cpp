#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,k,x;
        cin>>k>>x;

        ll left = 1;
        ll right = 2*k-1;

        ll ans = 0;

        while(left<=right){
            ll mid = left+(right-left)/2;
            ll emotes = 0;
            if(mid<=k){
                emotes=(mid*(mid+1))/2;
            }
            else{
                ll extra = mid-k;
                ll total = (k*(k+1))/2;
                ll sm = (k*(k-1))/2;
                ll strt = ((k-extra)*(k-extra-1))/2;
                emotes = total + (sm-strt);
            }

            if(emotes<x){
                left=mid+1;
                ans = mid;
            }
            else{
                ll cur = 0;
                if(mid<=k){
                    cur=mid;
                }
                else{
                    cur = k - (mid-k);
                }

                if((emotes-cur)>=x){
                    right = mid-1;
                }
                else{
                    ans = mid;
                    break;
                }
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