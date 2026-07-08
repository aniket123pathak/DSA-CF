#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

/*
what is the brute force logic of this??
checking from minheight column to desired height of the wall 
*/
class Solution {
public:
    void solve()
    {
        ll n,i,x;
        cin>>n>>x;
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        ll left = 1;
        ll right = 2e9;
        ll ans = 0;

        while(left<=right){
            ll mid = left + (right - left)/2;

            ll trapped = 0;
            for(i=0;i<n;i++){
                if(mid>a[i]){
                    trapped+=(mid - a[i]);
                }
            }
            if(trapped>x){
                right=mid-1;
            }
            else{
                ans=max(ans,mid);
                left=mid+1;
            }
            
        }
        cout<<ans<<endl;

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