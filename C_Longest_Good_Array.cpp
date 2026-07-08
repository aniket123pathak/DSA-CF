#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll l,r;
        cin>>l>>r;

        ll left = 1;
        ll right = 1e9;
        ll ans = 0;
        while(left<=right){
            ll mid = left + (right-left)/2;

            ll sum = (mid*(mid+1))/2;

            if(sum+l<=r){
                ans = mid;
                left=mid+1;
            }
            else{
                right = mid-1;
            }
        }
        
        cout<<ans+1<<endl;
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