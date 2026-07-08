#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,k,i;
        cin>>n>>k;

        if(k>=n){
            cout<<1<<endl;
            return;
        }
        vector<ll>div;
        for(i=1;i*i<=n;i++){
            if(n%i==0){
                div.push_back(i);
                if(i!=n/i){
                    div.push_back(n/i);
                }
            }
        }
        sort(div.begin(),div.end());
        ll sz = div.size();
        ll left = 0;
        ll right = sz-1;
        ll ans = 1;
        while(left<=right){
            ll mid = left+(right-left)/2;

            if(div[mid]>k){
                right = mid-1;
            }
            else{
                left = mid+1;
                ans = max(div[mid],ans);
            }
        }
        cout<<n/ans<<endl;
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