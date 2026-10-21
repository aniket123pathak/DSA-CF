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
        sort(a.begin(),a.end());
        ll x = 0;
        ll ans = 0;
        ll left = 0;
        ll right = n-1;
        while(left<=right){
            if(a[left]==0){
                left++;
                continue;
            }
            if(a[right]==0){
                right--;
                continue;
            }
            if(left==right){
                if(x>=a[left]){
                    ans++;
                    break;
                }
                ll want = a[left]-x;

                ans += (want+1)/2;
                a[left]-= (want+1)/2;

                if(a[left]>0){
                    ans++;
                }
                break;

            }
            if(a[left]+x>=a[right]){
                ans++;
                ans+=a[right]-x;
                a[left]-=a[right]-x;
                a[right]=0;
                x=0;
                right--;
            }
            else{
                x+=a[left];
                ans+=a[left];
                a[left]=0;
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