#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,h;
        cin>>n>>h;
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        ll ans = 0;
        ll left = 0;
        ll right = n;

        while(left<=right){
            ll mid = left + (right-left)/2;
            vector<ll> temp(a.begin(),a.begin()+mid);
            sort(temp.rbegin(),temp.rend());
            ll rem = h;
            ll sz = temp.size();
            bool check = true;
            for(i=0;i<sz;i++){
                if(temp[i]<=rem){
                    rem-=temp[i];
                    i++;
                }
                else{
                    check= false;
                    break;
                }
            }
            if(check){
                left=mid+1;
                ans=mid;
            }
            else{
                right=mid-1;
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
    s.solve();
    return 0;
}